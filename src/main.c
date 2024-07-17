#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

#include "structs.h"
#include "triangle.h"
#include "defs.h"
#include "model.h"
float d = 10.0f;

ivector_t project_vertex(Vector3 v);

ivector_t viewport_to_canvas(float x, float y);

void render_object(const Vector3 *vertices, const triangle_t *triangles, size_t n_triangles, Vector3 translate);

int main(void) {
  InitWindow(cw, ch, "rasterizer");
  model_t cube;
  initialise_cube(&cube);

  while (!WindowShouldClose()) {
    BeginDrawing();
    // \/ DO NOT  MOVE \/
    ClearBackground(RAYWHITE);
    // ^ DO NOT  MOVE ^]
    render_object(cube.vertices, cube.triangles, 12, (Vector3){-1.5,0,7});
    EndDrawing();
  }

  CloseWindow();
  unload_model(&cube);
  return 0;
}

ivector_t viewport_to_canvas(float x, float y) {
  return (ivector_t){x * cw / vw, y * ch / vh};
}

ivector_t project_vertex(Vector3 v) {
  return viewport_to_canvas((float) v.x * (float) d / (float) v.z, (float) v.y * (float) d / (float) v.z);
}

void render_object(const Vector3 *vertices, const triangle_t *triangles, size_t n_triangles, Vector3 translate) {
  for (int i = 0; i < n_triangles; ++i) {
    draw_wireframe_triangle(project_vertex(Vector3Add(vertices[triangles[i].a],translate)),
                            project_vertex(Vector3Add(vertices[triangles[i].b],translate)),
                            project_vertex(Vector3Add(vertices[triangles[i].c],translate)),
                            triangles[i].color);
  }
}
