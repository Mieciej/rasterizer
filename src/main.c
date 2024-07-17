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
  scene[0] = (instance_t){&cube,(Vector3){-1.5,0,7}};
  scene[1] = (instance_t){&cube,(Vector3){2.5,1,7}};
  while (!WindowShouldClose()) {
    BeginDrawing();
    // \/ DO NOT  MOVE \/
    ClearBackground(RAYWHITE);
    render_scene(scene,2);
    // ^ DO NOT  MOVE ^]
    EndDrawing();
  }

  CloseWindow();
  unload_model(&cube);
  return 0;
}

