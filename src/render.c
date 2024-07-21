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
  return viewport_to_canvas((float) v.x * (float) D / (float) v.z, (float) v.y * (float) D / (float) v.z);
}

Matrix get_3d_to_canvas_matrix() {
  Matrix m = {0};
  m.m0 = D * cw / vw;
  m.m5 = D * ch / vh;
  m.m10 = 1;
  return m;
}


void render_object(const Vector3 *vertices, const triangle_t *triangles, size_t n_triangles, transform_t obj_transform,
                   transform_t camera) {
  Matrix transformation = MatrixIdentity();
  transformation = MatrixMultiply(obj_transform.scale, transformation);
  transformation = MatrixMultiply(obj_transform.rot, transformation);
  transformation = MatrixMultiply(obj_transform.trans, transformation);
  transformation = MatrixMultiply(MatrixInvert(camera.trans), transformation);
  transformation = MatrixMultiply(MatrixInvert(camera.rot), transformation);
  for (int i = 0; i < n_triangles; ++i) {
    Vector3 a = Vector3Transform(vertices[triangles[i].a], transformation);
    Vector3 b = Vector3Transform(vertices[triangles[i].b], transformation);
    Vector3 c = Vector3Transform(vertices[triangles[i].c], transformation);
    draw_wireframe_triangle(project_vertex(a), project_vertex(b), project_vertex(c), triangles[i].color);
  }
}

void render_scene(instance_t *scene, size_t n_instances) {
  transform_t camera = {.trans = MatrixTranslate(0, 0, -10), .rot = MatrixIdentity()};
  for (int i = 0; i < n_instances; ++i) {
    instance_t in = scene[i];
    render_object(in.model->vertices, in.model->triangles, in.model->n_triangles, in.transform, camera);
  }
}
