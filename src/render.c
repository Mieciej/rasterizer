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

void render_object(const Vector3 *vertices, const triangle_t *triangles, size_t n_triangles, transform_t transform) {
  for (int i = 0; i < n_triangles; ++i) {
    Vector3 a = vertices[triangles[i].a];
    Vector3 b = vertices[triangles[i].b];
    Vector3 c = vertices[triangles[i].c];
    a = Vector3Scale(a,transform.scale);
    b = Vector3Scale(b,transform.scale);
    c = Vector3Scale(c,transform.scale);
    a = Vector3Transform(a,transform.rot);
    b = Vector3Transform(b,transform.rot);
    c = Vector3Transform(c,transform.rot);
    a = Vector3Add(transform.pos,a);
    b = Vector3Add(transform.pos,b);
    c = Vector3Add(transform.pos,c);
    draw_wireframe_triangle(project_vertex(a),project_vertex(b),project_vertex(c),triangles[i].color);
  }
}

void render_scene(instance_t* scene, size_t n_instances) {
  for (int i = 0; i < n_instances; ++i) {
    instance_t in = scene[i];
    render_object(in.model->vertices,in.model->triangles,in.model->n_triangles,in.transform);
  }
}
