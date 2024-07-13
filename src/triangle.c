//
// Created by maciej on 13/07/24.
//

#include "triangle.h"
#include "structs.h"
#include "line.h"
#include <raylib.h>

void draw_wireframe_triangle(iVector2 p0, iVector2 p1, iVector2 p2, Color c) {
  draw_line(p0,p1,c);
  draw_line(p1,p2,c);
  draw_line(p2,p0,c);
}
