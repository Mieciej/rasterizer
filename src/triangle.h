//
// Created by maciej on 13/07/24.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "structs.h"
#include <raylib.h>
void draw_wireframe_triangle(ivector_t p0, ivector_t p1, ivector_t p2, Color c);

void draw_filled_triangle(vertex_t p0, vertex_t p1, vertex_t p2, Color c);
#endif // TRIANGLE_H
