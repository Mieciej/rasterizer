#include <raylib.h>
#include <stdio.h>

#include "structs.h"
#include "defs.h"
#include "model.h"
#include "render.h"
#include "triangle.h"


int main(void) {
  InitWindow(cw, ch, "rasterizer");
  model_t cube;
  initialise_cube(&cube);
  instance_t scene[2];
  scene[0] = (instance_t){
    &cube, (transform_t){.trans = MatrixTranslate(0,1,1), .scale = MatrixScale(1, 1, 1), MatrixRotateZ(-30)}
  };
  scene[1] = (instance_t){
    &cube, (transform_t){.trans = MatrixTranslate(2.5, 0, 1), .scale = MatrixScale(1, 1, 1), MatrixRotateY(80)}
  };
  float passing_time = 0.0f;
  while (!WindowShouldClose()) {
    scene[0].transform.rot = MatrixMultiply(MatrixRotateZ(passing_time),MatrixRotateY(-passing_time));
    scene[0].transform.trans = MatrixTranslate(0,sin(passing_time)*2,1);
    passing_time+=GetFrameTime();
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
