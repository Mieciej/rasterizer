#include "raylib.h"
#include "raymath.h"
const int cw = 800;
const int ch = 450;


void put_pixel(int x, int y, Color c);

int main(void) {
  InitWindow(cw, ch, "rasterizer");
  Vector2 pa = {0, 0};
  Vector2 pb = {200, 200};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (int x = pa.x; x <= pb.x; ++x) {
      int y;
      float alpha = (float) (pb.y - pa.y) / (float) (pb.x - pa.x);
      int b = pa.y - alpha * pa.x;
      y = alpha * x + b;
      put_pixel(x, y,BLACK);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

void put_pixel(int x, int y, Color c) {
  Vector2 pos = (Vector2){.x = x + cw / 2, .y = -y + ch / 2};
  DrawPixelV(pos, c);
}
