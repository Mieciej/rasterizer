//
// Created by maciej on 13/07/24.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "structs.h"
#include <raylib.h>
void draw_wireframe_triangle(iVector2 p0, iVector2 p1, iVector2 p2, Color c);

void draw_filled_triangle(Vertex p0, Vertex p1, Vertex p2, Color c);
#endif // TRIANGLE_H
