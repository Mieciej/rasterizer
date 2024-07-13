#include <assert.h>
#include <stdlib.h>

#include "raylib.h"
#include "structs.h"
#include "triangle.h"
#include "defs.h"


int main(void) {
  InitWindow(cw, ch, "rasterizer");
  Vertex pa = {-100, 200,0.5};
  Vertex pb = {-10, 300, 0.0};
  Vertex pc = {200, 0, 1.0};

  while (!WindowShouldClose()) {
    BeginDrawing();
    // \/ DO NOT  MOVE \/
    ClearBackground(RAYWHITE);
    // ^ DO NOT  MOVE ^
    draw_filled_triangle(pa,pb,pc, BLUE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

