#include "raylib.h"
#include "raymath.h"
const int cw = 800;
const int ch = 450;


void put_pixel(int x, int y, Color c);

void draw_line(Vector2 pa, Vector2 pb, Color c);

int main(void) {
  InitWindow(cw, ch, "rasterizer");
  Vector2 pa = {0, 0};
  Vector2 pb = {200, 200};

  while (!WindowShouldClose()) {
    BeginDrawing();
    draw_line(pa, pb, BLACK);
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

void put_pixel(int x, int y, Color c) {
  Vector2 pos = (Vector2){.x = x + cw / 2, .y = -y + ch / 2};
  DrawPixelV(pos, c);
}

void draw_line(Vector2 pa, Vector2 pb, Color c) {
  float alpha = (float) (pb.y - pa.y) / (float) (pb.x - pa.x);
  int b = pa.y - alpha * pa.x;
  for (int x = pa.x; x <= pb.x; ++x) {
    int y;
    y = alpha * x + b;
    put_pixel(x, y,BLACK);
  }
}
