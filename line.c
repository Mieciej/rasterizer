//
// Created by maciej on 13/07/24.
//

#include "line.h"
#include <assert.h>
#include <stdlib.h>
#include <raylib.h>
#include "defs.h"
void put_pixel(int x, int y, Color c) {
  iVector2 pos = {.x = x + cw / 2, .y = -y + ch / 2};
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

void draw_line(iVector2 pa, iVector2 pb, Color c) {
  int dx = abs(pb.x - pa.x);
  int dy = abs(pb.y - pa.y);
  if (dx > dy) {
    if (pb.x < pa.x) {
      iVector2 tmp = pb;
      pb = pa;
      pa = tmp;
    }
    int *y = malloc(sizeof(int) * (dx + 1));
    interpolate(pa.x, pa.y, pb.x, pb.y, y);
    for (int x = pa.x; x <= pb.x; ++x) {
      put_pixel(x, y[x - pa.x], c);
    }
    free(y);
  } else {
    if (pb.y < pa.y) {
      iVector2 tmp = pb;
      pb = pa;
      pa = tmp;
    }
    int *x = malloc(sizeof(int) * (dy + 1));
    interpolate(pa.y, pa.x, pb.y, pb.x, x);
    for (int y = pa.y; y <= pb.y; ++y) {
      put_pixel(x[y - pa.y], y, c);
    }
    free(x);
  }
}
