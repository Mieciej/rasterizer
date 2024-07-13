#include <assert.h>
#include <stdlib.h>

#include "raylib.h"
#include "structs.h"
#include "triangle.h"
#include "defs.h"


int main(void) {
  InitWindow(cw, ch, "rasterizer");
  iVector2 pa = {-100, 200};
  iVector2 pb = {0, 300};
  iVector2 pc = {100, 0};

  while (!WindowShouldClose()) {
    BeginDrawing();
    // \/ DO NOT  MOVE \/
    ClearBackground(RAYWHITE);
    // ^ DO NOT  MOVE ^
    draw_filled_triangle(pa,pb,pc, BLUE);
    draw_wireframe_triangle(pa,pb,pc, BLACK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

