//
// Created by maciej on 13/07/24.
//

#include "line.h"
#include <assert.h>
#include <stdlib.h>
#include <raylib.h>
#include "defs.h"
void put_pixel(float x, float y, Color c) {
  Vector3 pos = {.x = x +(float)cw / 2, .y = -y + (float)ch / 2};
  DrawPixel(pos.x, pos.y, c);
}

void interpolate(int i0, int d0, int i1, int d1, int *output) {
  assert(output!=NULL && "Null pointer passed to interpolation");
  if (i0 == i1) {
    output[0] = d0;
  }
  const float a = (float) (d1 - d0) / (float) (i1 - i0);
  float d = d0;
  for (int i = i0; i <= i1; ++i) {
    output[i - i0] = d;
    d += a;
  }
}

void interpolatef(int i0, float d0, int i1, float d1, float *output) {
  assert(output!=NULL && "Null pointer passed to interpolation");
  if (i0 == i1) {
    output[0] = d0;
  }
  const float a = (float) (d1 - d0) / (float) (i1 - i0);
  float d = d0;
  for (int i = i0; i <= i1; ++i) {
    output[i - i0] = d;
    d += a;
  }
}

void draw_line(Vector2 pa, Vector2 pb, Color c) {
  int dx = abs((int)pb.x - (int)pa.x);
  int dy = abs((int)pb.y - (int)pa.y);
  if (dx > dy) {
    if (pb.x < pa.x) {
      swap_ivectors(&pa,&pb);
    }
    float *y = malloc(sizeof(float) * (dx + 1));
    interpolatef(pa.x, pa.y, pb.x, pb.y, y);
    for (int x = pa.x; x <= pb.x; ++x) {
      put_pixel(x, y[x - (int)pa.x], c);
    }
    free(y);
  } else {
    if (pb.y < pa.y) {
      swap_ivectors(&pa,&pb);
    }
    float *x = malloc(sizeof(float) * (dy + 1));
    interpolatef(pa.y, pa.x, pb.y, pb.x, x);
    for (int y = pa.y; y <= pb.y; ++y) {
      put_pixel(x[y - (int)pa.y], y, c);
    }
    free(x);
  }
}
