//
// Created by maciej on 17/07/24.
//

#ifndef RENDER_H
#define RENDER_H
#include <stddef.h>

#include "structs.h"

ivector_t project_vertex(Vector3 v);

ivector_t viewport_to_canvas(float x, float y);

void render_object(const Vector3 *vertices, const triangle_t *triangles, size_t n_triangles, transform_t transform);

void render_scene(instance_t* scene, size_t n_instances);


#endif //RENDER_H
