#include <assert.h>
#include <stdlib.h>

#include "raylib.h"
#include "structs.h"
#include "triangle.h"
#include "defs.h"


int main(void) {
  InitWindow(cw, ch, "rasterizer");
  iVector2 pa = {0, 0};
  iVector2 pb = {30, -100};
  iVector2 pc = {100, -200};

  while (!WindowShouldClose()) {
    BeginDrawing();
    draw_wireframe_triangle(pa,pb,pc, BLACK);
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

