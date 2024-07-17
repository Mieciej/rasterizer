//
// Created by maciej on 13/07/24.
//

#ifndef LINE_H
#define LINE_H
#include "structs.h"
#include <raylib.h>
void put_pixel(int x, int y, Color c);

void draw_line(ivector_t pa, ivector_t pb, Color c);

void interpolate(int i0, int d0, int i1, int d1, int *output);

void interpolatef(int i0, float d0, int i1, float d1, float *output);
static void swap_ivectors(ivector_t *a, ivector_t *b) {
  const ivector_t tmp = *b;
  *b = *a;
  *a = tmp;
}
static void swap_vertices(vertex_t *a, vertex_t *b) {
  const vertex_t tmp = *b;
  *b = *a;
  *a = tmp;
}
#endif //LINE_H
