/* File: driver_point.c */
/* Nama : Malik Akbar Hashemi Rafsanjani */
/* NIM : 13520105 */
/* Tanggal: 1 September 2021 */
/* ***  MAIN DRIVER POINT *** */

#include <stdio.h>
#include "point.h"

int main(){
  // KAMUS
  POINT myPoint, yourPoint, ourPoint;
  float dx, dy;

  // ALGORITMA
  myPoint = MakePOINT(1,1);
  printf("Input your point: ");
  BacaPOINT(&yourPoint);
  printf("My point: ");
  TulisPOINT(myPoint);
  printf("\n");
  printf("Your point: ");
  TulisPOINT(yourPoint);
  printf("\n\n");

  if (EQ(myPoint,yourPoint))
    printf("My point is equal to yours\n");
  if (NEQ(myPoint,yourPoint))
    printf("My point isn't equal to yours\n");
  if (IsOnSbX(yourPoint) || IsOnSbY(yourPoint)){
    if (IsOrigin(yourPoint))
      printf("Your point is origin\n");
    if (IsOnSbX(yourPoint))
      printf("Your point is on X axis");
    if (IsOnSbY(yourPoint))
      printf("Your point is on Y axis");
  } 
  else
    printf("Your point is on %d Kuadran\n", Kuadran(yourPoint));
  printf("\n");

  printf("Next X of your point: ");
  TulisPOINT(NextX(yourPoint));
  printf("\n");
  printf("Next Y of your point: ");
  TulisPOINT(NextY(yourPoint));
  printf("\n\n");
  
  printf("Input dx and dy: ");
  scanf("%f %f", &dx, &dy);
  ourPoint = PlusDelta(myPoint,dx,dy);
  printf("Our point: ");
  TulisPOINT(ourPoint);
  printf("\n");
  printf("Mirror of our point to X axis: ");
  TulisPOINT(MirrorOf(ourPoint,true));
  printf("\n");
  printf("Mirror of our point to Y axis: ");
  TulisPOINT(MirrorOf(ourPoint,false));
  printf("\n\n");

  printf("Distance of our point to origin: %f\n", 
          Jarak0(ourPoint));
  printf("Distance between my point and yours: %f\n\n", 
          Panjang(myPoint,yourPoint));

  printf("Input dx and dy: ");
  scanf("%f %f", &dx, &dy);
  Geser(&ourPoint,dx,dy);
  printf("Now our point: ");
  TulisPOINT(ourPoint);
  printf("\n");
  Mirror(&ourPoint,true);
  printf("Mirroring our point: ");
  TulisPOINT(ourPoint);
  printf("\n");
  Putar(&ourPoint,90);
  printf("Rotate 90 degree of our point: ");
  TulisPOINT(ourPoint);
  printf("\n\n");

  GeserKeSbX(&ourPoint);
  GeserKeSbY(&ourPoint);
  if (IsOrigin(ourPoint))
    printf("Our point now is origin\n");

  return 0;
}