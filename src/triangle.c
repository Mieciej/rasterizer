//
// Created by maciej on 13/07/24.
//

#include "triangle.h"
#include "structs.h"
#include "line.h"

#include <raylib.h>
#include <stdlib.h>
#include <tgmath.h>

void draw_wireframe_triangle(iVector2 p0, iVector2 p1, iVector2 p2, Color c) {
  draw_line(p0, p1, c);
  draw_line(p1, p2, c);
  draw_line(p2, p0, c);
}

void draw_filled_triangle(iVector2 p0, iVector2 p1, iVector2 p2, Color c) {
  // sort vertices from lowest to highest
  if (p1.y < p0.y) {
    swap_ivectors(&p1, &p0);
  }
  if (p2.y < p0.y) {
    swap_ivectors(&p2, &p0);
  }
  if (p2.y < p1.y) {
    swap_ivectors(&p2, &p1);
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

  // decide which of vertical pixel series is on the right
  int m = x02_size / 2;
  int *x_left, *x_right;
  if (x02[m] < x012[m]) {
    x_left = x02;
    x_right = x012;
  } else {
    x_left = x012;
    x_right = x02;
  }
  // fill the triangle
  for (int y = p0.y; y <= p2.y; ++y) {
    for (int x = x_left[y - p0.y]; x < x_right[y - p0.y]; ++x) {
      put_pixel(x, y, c);
    }
  }
  free(mem);
}
