//
// Created by maciej on 13/07/24.
//

#ifndef LINE_H
#define LINE_H
#include "structs.h"
#include <raylib.h>
void put_pixel(float x, float y, Color c);

void draw_line(Vector2 pa, Vector2 pb, Color c);

void interpolate(int i0, int d0, int i1, int d1, int *output);

void interpolatef(int i0, float d0, int i1, float d1, float *output);
static void swap_ivectors(Vector2 *a, Vector2 *b) {
  const Vector2 tmp = *b;
  *b = *a;
  *a = tmp;
}
static void swap_vertices(Vector3 *a, Vector3 *b) {
  const Vector3 tmp = *b;
  *b = *a;
  *a = tmp;
}
#endif //LINE_H
