#include <stdio.h>
#include "point.h"
#include "vector.h"

int main() {
  // KAMUS
  VECTOR vec1, vec2, vec3, vec4, vec5;

  // ALGORITMA
  vec1 = MakeVector(2,3.5);
  vec2 = MakeVector(2.5,-10);
  printf("My vector: ");
  TulisVector(vec1);
  printf("\n");
  printf("Your vector: ");
  TulisVector(vec2);
  printf("\n");
  printf("Magnitude mine: %f, and yours: %f\n\n",
          Magnitude(vec1),Magnitude(vec2));

  vec3 = Add(vec1,vec2);
  printf("Vector3: ");
  TulisVector(vec3);
  printf("\n");
  vec4 = Substract(vec3,vec2);
  printf("Vector4: ");
  TulisVector(vec4);
  printf("\n");
  vec5 = Multiply(vec1,-3);
  printf("Vector5: ");
  TulisVector(vec5);
  printf("\n\n");

  printf("Dot of vec1 and vec2: %f\n",Dot(vec1,vec2));

  return 0;
}