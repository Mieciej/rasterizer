#include <assert.h>
#include <stdlib.h>

#include "raylib.h"
#include "structs.h"
#include "line.h"
#include "defs.h"


int main(void) {
  InitWindow(cw, ch, "rasterizer");
  iVector2 pa = {0, 0};
  iVector2 pb = {2000, -100};

  while (!WindowShouldClose()) {
    BeginDrawing();
    draw_line(pa, pb, BLACK);
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

