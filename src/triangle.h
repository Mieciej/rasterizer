//
// Created by maciej on 13/07/24.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "structs.h"
#include <raylib.h>
void draw_wireframe_triangle(Vector2 p0, Vector2 p1, Vector2 p2, Color c);

void draw_filled_triangle(Vector3 p0, Vector3 p1, Vector3 p2, float h0,
                          float h1, float h2, Color c);
#endif // TRIANGLE_H
