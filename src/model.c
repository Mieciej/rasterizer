//
// Created by maciej on 17/07/24.
//

#include "model.h"

#include <assert.h>
#include <raylib.h>
#include "structs.h"
#include <stdlib.h>

void initialise_cube(model_t * cube) {
  Vector3 *cube_vertices = malloc(sizeof(Vector3) * 8);
  triangle_t *cube_triangles = malloc(sizeof(triangle_t) * 12);
  cube_vertices[0] = (Vector3){1, 1, 1};
  cube_vertices[1] = (Vector3){-1, 1, 1};
  cube_vertices[2] = (Vector3){-1, -1, 1};
  cube_vertices[3] = (Vector3){1, -1, 1};
  cube_vertices[4] = (Vector3){1, 1, -1};
  cube_vertices[5] = (Vector3){-1, 1, -1};
  cube_vertices[6] = (Vector3){-1, -1, -1};
  cube_vertices[7] = (Vector3){1, -1, -1};

  cube_triangles[0] = (triangle_t){0, 1, 2,RED};
  cube_triangles[1] = (triangle_t){0, 2, 3,RED};
  cube_triangles[2] = (triangle_t){4, 0, 3,GREEN};
  cube_triangles[3] = (triangle_t){4, 3, 7,GREEN};
  cube_triangles[4] = (triangle_t){5, 4, 7,BLUE};
  cube_triangles[5] = (triangle_t){5, 7, 6,BLUE};
  cube_triangles[6] = (triangle_t){1, 5, 6,YELLOW};
  cube_triangles[7] = (triangle_t){1, 6, 2,YELLOW};
  cube_triangles[8] = (triangle_t){4, 5, 1,PURPLE};
  cube_triangles[9] = (triangle_t){4, 1, 0,PURPLE};
  cube_triangles[10] = (triangle_t){2, 6, 7,MAGENTA};
  cube_triangles[11] = (triangle_t){2, 7, 3,MAGENTA};
  cube->n_triangles=12;
  cube->vertices = cube_vertices;
  cube->triangles = cube_triangles;

}
void unload_model(model_t* model) {
  assert(model->triangles!=NULL);
  assert(model->vertices!=NULL);
  free(model->vertices);
  free(model->triangles);
}