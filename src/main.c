#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

#include "structs.h"
#include "triangle.h"
#include "defs.h"

float d = 10.0f;

iVector2 project_vertex(Vector3 v);

iVector2 viewport_to_canvas(float x, float y);

void render_object(const Vector3 *vertices, const Triangle *triangles, size_t n_triangles, Vector3 translate);

int main(void) {
  InitWindow(cw, ch, "rasterizer");
  Vector3 v[8];
  v[0] = (Vector3){1, 1, 1};
  v[1] = (Vector3){-1, 1, 1};
  v[2] = (Vector3){-1, -1, 1};
  v[3] = (Vector3){1, -1, 1};
  v[4] = (Vector3){1, 1, -1};
  v[5] = (Vector3){-1, 1, -1};
  v[6] = (Vector3){-1, -1, -1};
  v[7] = (Vector3){1, -1, -1};
  Triangle t[12];
  t[0] = (Triangle){0, 1, 2,RED};
  t[1] = (Triangle){0, 2, 3,RED};
  t[2] = (Triangle){4, 0, 3,GREEN};
  t[3] = (Triangle){4, 3, 7,GREEN};
  t[4] = (Triangle){5, 4, 7,BLUE};
  t[5] = (Triangle){5, 7, 6,BLUE};
  t[6] = (Triangle){1, 5, 6,YELLOW};
  t[7] = (Triangle){1, 6, 2,YELLOW};
  t[8] = (Triangle){4, 5, 1,PURPLE};
  t[9] = (Triangle){4, 1, 0,PURPLE};
  t[10] = (Triangle){2, 6, 7,MAGENTA};
  t[11] = (Triangle){2, 7, 3,MAGENTA};

  while (!WindowShouldClose()) {
    BeginDrawing();
    // \/ DO NOT  MOVE \/
    ClearBackground(RAYWHITE);
    // ^ DO NOT  MOVE ^]
    render_object(v, t, 12, (Vector3){-1.5,0,7});
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

iVector2 viewport_to_canvas(float x, float y) {
  return (iVector2){x * cw / vw, y * ch / vh};
}

iVector2 project_vertex(Vector3 v) {
  return viewport_to_canvas((float) v.x * (float) d / (float) v.z, (float) v.y * (float) d / (float) v.z);
}

void render_object(const Vector3 *vertices, const Triangle *triangles, size_t n_triangles, Vector3 translate) {
  for (int i = 0; i < n_triangles; ++i) {
    draw_wireframe_triangle(project_vertex(Vector3Add(vertices[triangles[i].a],translate)),
                            project_vertex(Vector3Add(vertices[triangles[i].b],translate)),
                            project_vertex(Vector3Add(vertices[triangles[i].c],translate)),
                            triangles[i].color);
  }
}
