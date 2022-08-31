/* File: point.c */
/* Nama : Malik Akbar Hashemi Rafsanjani */
/* NIM : 13520105 */
/* Tanggal: 1 September 2021 */
/* *** Implementasi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y) {
  /* Membentuk sebuah POINT dari komponen-komponennya */
  
  // KAMUS
  POINT P;
  
  // ALGORITMA
  Absis(P) = X;
  Ordinat(P) = Y;

  return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
  /* I.S. Sembarang */
  /* F.S. P terdefinisi */

  // KAMUS
  float X, Y;

  // ALGORITMA
  scanf("%f %f", &X, &Y);
  *P = MakePOINT(X,Y);

  // APLIKASI
  /* Contoh: 1 2 
    akan membentuk POINT <1,2> */
}

void TulisPOINT (POINT P) {
  /* I.S. P terdefinisi */
  /* F.S. P tertulis di layar dengan format "(X,Y)" */

  // ALGORITMA
  printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}        

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
  /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

  // ALGORITMA
  return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2) {
  /* Mengirimkan true jika P1 tidak sama dengan P2 */

  // ALGORITMA
  return (!EQ(P1, P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
  /* Menghasilkan true jika P adalah titik origin */

  // ALGORITMA
  return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P) {
  /* Menghasilkan true jika P terletak Pada sumbu X */

  // ALGORITMA
  return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P) {
  /* Menghasilkan true jika P terletak pada sumbu Y */

  // ALGORITMA
  return (Absis(P) == 0);
}

int Kuadran (POINT P) {
  /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
  /* Prekondisi : P bukan titik origin, */
  /*              dan P tidak terletak di salah satu sumbu */

  // ALGORITMA
  if (Absis(P) > 0 ) {
    if (Ordinat(P) > 0) return 1;
    else return 4;
  } else {
    if (Ordinat(P) > 0) return 2;
    else return 3;
  }
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P) {
  /* Mengirim salinan P dengan absis ditambah satu */ 

  // ALGORITMA
  Absis(P) += 1;

  return P;
}
             
POINT NextY (POINT P) {
  /* Mengirim salinan P dengan ordinat ditambah satu */

  // ALGORITMA
  Ordinat(P) += 1;

  return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
  /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

  // ALGORITMA
  Absis(P) += deltaX;
  Ordinat(P) += deltaY;

  return P;
}

POINT MirrorOf (POINT P, boolean SbX) {
  /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
  /* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
  /* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

  // ALGORITMA
  if (SbX)
    Ordinat(P) *= -1;
  else 
    Absis(P) *= -1;

  return P;
}

float Jarak0 (POINT P) {
  /* Menghitung jarak P ke (0,0) */

  // ALGORITMA
  return sqrt(pow(Absis(P),2) + pow(Ordinat(P),2));
}

float Panjang (POINT P1, POINT P2) {
  /* Menghitung panjang SEGMEN garis yang dibentuk P1 dan P2 */

  // ALGORITMA
  return sqrt(pow(Absis(P2)-Absis(P1),2) + 
              pow(Ordinat(P2)-Ordinat(P1),2));
}

void Geser (POINT *P, float deltaX, float deltaY) {
  /* I.S. P terdefinisi */
  /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

  // ALGORITMA
  Absis(*P) += deltaX;
  Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
  /* I.S. P terdefinisi */
  /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */

  // ALGORITMA
  Ordinat(*P) = 0;

  //APLIKASI
  /* Proses : P digeser ke sumbu X. */
  /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
}

void GeserKeSbY (POINT *P) {
  /* I.S. P terdefinisi*/
  /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */

  // ALGORITMA
  Absis(*P) = 0;

  /* Proses : P digeser ke sumbu Y. */
  /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
}

void Mirror (POINT *P, boolean SbX) {
  /* I.S. P terdefinisi */
  /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
  /* Jika SbX true maka dicerminkan terhadap sumbu X */
  /* Jika SbX false maka dicerminkan terhadap sumbu Y */

  // ALGORITMA
  if (SbX) 
    Ordinat(*P) *= -1;
  else 
    Absis(*P) *= -1;
}

void Putar (POINT *P, float Sudut) {
  /* I.S. P terdefinisi */
  /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */

  // KAMUS
  float initAbsis = Absis(*P);

  // ALGORITMA
  Sudut = (360 - Sudut) * M_PI/180;
  Absis(*P) = Absis(*P)*cos(Sudut) - 
              Ordinat(*P)*sin(Sudut);
  Ordinat(*P) = initAbsis*sin(Sudut) - 
                Ordinat(*P)*cos(Sudut);
}
