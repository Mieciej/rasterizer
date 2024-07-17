//
// Created by maciej on 13/07/24.
//

#ifndef STRUCTS_H
#define STRUCTS_H
#include <raylib.h>

typedef struct{
  int x;
  int y;
} iVector2;
typedef struct{
  int x;
  int y;
  int z;
  float h;
} Vertex;
typedef struct {
  unsigned int a;
  unsigned int b;
  unsigned int c;
  Color color;
} Triangle;
#endif //STRUCTS_H
