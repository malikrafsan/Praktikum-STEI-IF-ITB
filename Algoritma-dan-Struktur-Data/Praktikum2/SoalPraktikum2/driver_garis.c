#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "point.h"
#include "garis.h"

int main() {
  // KAMUS
  POINT p1, p2;
  GARIS g1, g2;
  float dx,dy;

  // ALGORITMA
  p1 = MakePOINT(1,1);
  p2 = MakePOINT(2,2);
  MakeGARIS(p1,p2,&g1);
  printf("Baca garis2: \n");
  BacaGARIS(&g2);

  printf("My garis: ");
  TulisGARIS(g1);
  printf("\n");
  printf("Your garis: ");
  TulisGARIS(g2);
  printf("\n\n");

  printf("Panjang garis1: %f\n",PanjangGARIS(g1));
  printf("Panjang garis2: %f\n\n",PanjangGARIS(g2));

  printf("Grad garis1: %f\n",Gradien(g1));
  printf("Grad garis2: %f\n\n",Gradien(g2));

  if (IsTegakLurus(g1,g2)) 
    printf("g1 dan g2 saling tegak lurus\n");
  
  if (IsSejajar(g1,g2))
    printf("g1 dan g2 sejajar\n");

  printf("Input dx dy: ");
  scanf("%f %f",&dx,&dy);
  GeserGARIS(&g2,dx,dy);
  printf("g2 sekarang: ");
  TulisGARIS(g2);
  printf("\n");

  return 0;
}