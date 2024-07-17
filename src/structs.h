//
// Created by maciej on 13/07/24.
//

#ifndef STRUCTS_H
#define STRUCTS_H
#include <raylib.h>

typedef struct{
  int x;
  int y;
} ivector_t;
typedef struct{
  int x;
  int y;
  int z;
  float h;
} vertex_t;
typedef struct {
  unsigned int a;
  unsigned int b;
  unsigned int c;
  Color color;
} triangle_t;
typedef struct {
  Vector3 *vertices;
  triangle_t *triangles;
  unsigned int n_triangles;
}model_t;

typedef struct {
  model_t *model;
  Vector3 pos;
}instance_t;
#endif //STRUCTS_H
