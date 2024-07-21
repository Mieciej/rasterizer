#include <raylib.h>

#include "structs.h"
#include "defs.h"
#include "model.h"
#include "render.h"


int main(void) {
  InitWindow(cw, ch, "rasterizer");
  model_t cube;
  initialise_cube(&cube);
  instance_t scene[2];
  scene[0] = (instance_t){&cube, (transform_t){.pos = {.x = -1.5, 1, 7}, .scale = 0.5, MatrixIdentity()}};
  scene[1] = (instance_t){&cube, (transform_t){.pos = {.x = 2.5, 2, 7}, .scale = 0.3, MatrixRotateX(60)}};
  while (!WindowShouldClose()) {
    BeginDrawing();
    // \/ DO NOT  MOVE \/
    ClearBackground(RAYWHITE);
    render_scene(scene, 2);
    // ^ DO NOT  MOVE ^]
    EndDrawing();
  }

  CloseWindow();
  unload_model(&cube);
  return 0;
}
