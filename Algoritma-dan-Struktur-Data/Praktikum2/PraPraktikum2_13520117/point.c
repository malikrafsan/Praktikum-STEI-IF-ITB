/* File: point.c */
/* Nama : Hafidz Nur Rahman Ghozali */
/* NIM : 13520117 */
/* Tanggal: 1 September 2021 */
/* ***  FILE BODY POINT *** */

#include <stdio.h>
#include <math.h>
#include "point.h"
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */

    // Kamus
    // P : POINT

    // Algoritma
    POINT P;
    Absis(P) = X;       // assign nilai absis
    Ordinat(P) = Y;     // assign nilai ordinat

    return P;           // Mengembalikan POINT P
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */

    // Kamus
    // x,y : float

    // Algoritma
    float x,y;
    scanf("%f %f", &x, &y);     // input nilai x dan y
    *P = MakePOINT(x,y);        // makePoint
}
void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

    // Algoritma
    printf("(%.2f,%.2f)\n", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

    // Algoritma
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */

    // Algoritma
    return !(Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */

    // Algoritma
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */

    // Algoritma
    return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */

    // Algoritma
    return Absis(P) == 0;
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

    // Algoritma
    if (Absis(P) > 0){
        if (Ordinat(P) > 0) return 1;
        else return 4;
    } else{
        if (Ordinat(P) > 0) return 2;
        else return 3;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */

    // Algoritma              
    Absis(P) += 1;
    return P;
}
POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */

    // Algoritma
    Ordinat(P) += 1;
    return P;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

    // Algoritma
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

    // Algoritma
    if (!(IsOnSbX(P) || IsOnSbY(P))){    
        if (SbX) Ordinat(P) *= (-1);
        else Absis(P) *= (-1);
    }

    return P;
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */

    // Algoritma
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang segmen garis dari P1 hingga P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */

    // Algoritma
    return sqrt(pow(Absis(P1)-Absis(P2), 2) + pow(Ordinat(P1)-Ordinat(P2), 2));
}
void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

    // Algoritma
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */

    // Algoritma
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */

    // Algoritma
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */

    // Algoritma
    if (!(IsOnSbX(*P) || IsOnSbY(*P))){
        if (SbX) Ordinat(*P) *= (-1);
        else Absis(*P) *= (-1);
    }
}
void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */

    // Algoritma
    Sudut = 360-Sudut;                      // Mengubah sudut menjadi 360-Sudut agar memenuhi arah jarum jam
    Sudut = Sudut*M_PI/180;                 // Konversi sudut dari derajat ke radian
    float temporary_absis = Absis(*P);      // Menyimpan nilai absis pada temporary value
    // Mengubah nilai absis dan ordinat dengan perkalian matriks rotasi
    Absis(*P) = Absis(*P)*cos(Sudut) - Ordinat(*P)*sin(Sudut);
    Ordinat(*P) = temporary_absis*sin(Sudut) + Ordinat(*P)*cos(Sudut);
}