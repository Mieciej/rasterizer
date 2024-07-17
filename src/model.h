//
// Created by maciej on 17/07/24.
//

#ifndef MODEL_H
#define MODEL_H


#include <raylib.h>
#include <stddef.h>

#include "structs.h"

typedef struct {
  Vector3 *vertices;
  triangle_t *triangles;
  size_t n_triangles;
}model_t;

void initialise_cube(model_t * cube);
void unload_model(model_t* model);

#endif //MODEL_H
