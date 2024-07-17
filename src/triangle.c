//
// Created by maciej on 13/07/24.
//

#include "triangle.h"
#include "structs.h"
#include "line.h"

#include <raylib.h>
#include <stdlib.h>
#include <tgmath.h>
#include <math.h>

void draw_wireframe_triangle(ivector_t p0, ivector_t p1, ivector_t p2, Color c) {
  draw_line(p0, p1, c);
  draw_line(p1, p2, c);
  draw_line(p2, p0, c);
}

void draw_filled_triangle(vertex_t p0, vertex_t p1, vertex_t p2, Color c) {
  // sort vertices from lowest to highest
  if (p1.y < p0.y) {
    swap_vertices(&p1, &p0);
  }
  if (p2.y < p0.y) {
    swap_vertices(&p2, &p0);
  }
  if (p2.y < p1.y) {
    swap_vertices(&p2, &p1);
  }
  // determine sides of the triangle (vertically going pixels)
  const size_t x01_size = p1.y - p0.y +1;
  const size_t x02_size = p2.y - p0.y + 1;
  const size_t x12_size = p2.y - p1.y + 1;
  const size_t total_size = x01_size + x02_size + x12_size;
  int *mem = malloc(total_size * sizeof(int));
  int *x012 = mem;
  int *x12 = &mem[x01_size-1];
  int *x02 = &mem[x01_size + x12_size-1];

  interpolate(p0.y, p0.x, p1.y - 1, p1.x, x012);
  interpolate(p1.y, p1.x, p2.y, p2.x, x12);
  interpolate(p0.y, p0.x, p2.y, p2.x, x02);

  float *mem_h = malloc(total_size * sizeof(float));
  float *h012 = mem_h;
  float *h12 = &mem_h[x01_size-1];
  float *h02 = &mem_h[x01_size + x12_size-1];

  interpolatef(p0.y, p0.h, p1.y - 1, p1.h, h012);
  interpolatef(p1.y, p1.h, p2.y, p2.h, h12);
  interpolatef(p0.y, p0.h, p2.y, p2.h, h02);
  // decide which of vertical pixel series is on the right
  int m = x02_size / 2;
  int *x_left, *x_right;
  float *h_left, *h_right;

  if (x02[m] < x012[m]) {
    x_left = x02;
    x_right = x012;
    h_left = h02;
    h_right = h012;
  } else {
    x_left = x012;
    x_right = x02;
    h_left = h012;
    h_right = h02;
  }
  // fill the triangle
  for (int y = p0.y; y <= p2.y; ++y) {
    const int x_l = x_left[y - p0.y];
    const int x_r = x_right[y - p0.y];
    float * h_segment = malloc((x_r - x_l + 1) * sizeof(float) );
    interpolatef(x_l, h_left[y-p0.y], x_r, h_right[y-p0.y], h_segment);
    for (int x = x_l; x < x_r; ++x) {
      Color shaded_color = c;
      shaded_color.r *= h_segment[x-x_l];
      shaded_color.b *= h_segment[x-x_l];
      shaded_color.g *= h_segment[x-x_l];
      put_pixel(x, y, shaded_color);
    }
    free(h_segment);
  }
  free(mem);
  free(mem_h);
}
