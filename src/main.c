#include <assert.h>
#include <stdlib.h>

#include "raylib.h"
#include "structs.h"
#include "triangle.h"
#include "defs.h"
#include "line.h"

int d = 10;

iVector2 project_vertex(Vertex v);

iVector2 viewport_to_canvas(float x, float y);

int main(void) {
  InitWindow(cw, ch, "rasterizer");
  Vertex vAf = {-4, -1, 10};
  Vertex vBf = {-4, 1, 10, 2};
  Vertex vCf = {-2, 1, 10};
  Vertex vDf = {-2, -1, 10};

  Vertex vAb = {-4, -1, 12};
  Vertex vBb = {-4, 1, 12};
  Vertex vCb = {-2, 1, 12};
  Vertex vDb = {-2, -1, 12};

  while (!WindowShouldClose()) {
    BeginDrawing();
    // \/ DO NOT  MOVE \/
    ClearBackground(RAYWHITE);
    // ^ DO NOT  MOVE ^]
    draw_line(project_vertex(vAf), project_vertex(vBf), BLUE);
    draw_line(project_vertex(vBf), project_vertex(vCf), BLUE);
    draw_line(project_vertex(vCf), project_vertex(vDf), BLUE);
    draw_line(project_vertex(vDf), project_vertex(vAf), BLUE);
    draw_line(project_vertex(vAb), project_vertex(vBb), RED);
    draw_line(project_vertex(vBb), project_vertex(vCb), RED);
    draw_line(project_vertex(vCb), project_vertex(vDb), RED);
    draw_line(project_vertex(vDb), project_vertex(vAb), RED);
    draw_line(project_vertex(vAf), project_vertex(vAb), GREEN);
    draw_line(project_vertex(vBf), project_vertex(vBb), GREEN);
    draw_line(project_vertex(vCf), project_vertex(vCb), GREEN);
    draw_line(project_vertex(vDf), project_vertex(vDb), GREEN);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

iVector2 viewport_to_canvas(float x, float y) {
  return (iVector2){x * cw / vw, y * ch / vh};
}

iVector2 project_vertex(Vertex v) {
  return viewport_to_canvas((float) v.x * (float) d / (float) v.z, (float) v.y * (float) d / (float) v.z);
}
