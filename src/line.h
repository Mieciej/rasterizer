//
// Created by maciej on 13/07/24.
//

#ifndef LINE_H
#define LINE_H
#include "structs.h"
#include <raylib.h>
void put_pixel(int x, int y, Color c);

void draw_line(iVector2 pa, iVector2 pb, Color c);

void interpolate(int i0, int d0, int i1, int d1, int *output);

void interpolatef(int i0, float d0, int i1, float d1, float *output);
static void swap_ivectors(iVector2 *a, iVector2 *b) {
  const iVector2 tmp = *b;
  *b = *a;
  *a = tmp;
}
static void swap_vertices(Vertex *a, Vertex *b) {
  const Vertex tmp = *b;
  *b = *a;
  *a = tmp;
}
#endif //LINE_H
