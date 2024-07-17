//
// Created by maciej on 17/07/24.
//
#include <raylib.h>
#include "render.h"

#include <raymath.h>

#include "structs.h"
#include "defs.h"
#include "triangle.h"
ivector_t viewport_to_canvas(float x, float y) {
  return (ivector_t){x * cw / vw, y * ch / vh};
}

ivector_t project_vertex(Vector3 v) {
  return viewport_to_canvas((float) v.x * (float) D / (float) v.z, (float) v.y * (float) D/ (float) v.z);
}

void render_object(const Vector3 *vertices, const triangle_t *triangles, size_t n_triangles, Vector3 translate) {
  for (int i = 0; i < n_triangles; ++i) {
    draw_wireframe_triangle(project_vertex(Vector3Add(vertices[triangles[i].a],translate)),
                            project_vertex(Vector3Add(vertices[triangles[i].b],translate)),
                            project_vertex(Vector3Add(vertices[triangles[i].c],translate)),
                            triangles[i].color);
  }
}

void render_scene(instance_t* scene, size_t n_instances) {
  for (int i = 0; i < n_instances; ++i) {
    instance_t in = scene[i];
    render_object(in.model->vertices,in.model->triangles,in.model->n_triangles,in.pos);
  }
}
