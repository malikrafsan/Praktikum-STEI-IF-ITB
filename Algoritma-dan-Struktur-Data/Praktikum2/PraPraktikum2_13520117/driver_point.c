/* File: driver_point.c */
/* Nama : Hafidz Nur Rahman Ghozali */
/* NIM : 13520117 */
/* Tanggal: 1 September 2021 */
/* ***  MAIN DRIVER POINT *** */

// Import module dan file yang dibutuhkan
#include <stdio.h>
#include "point.h"

// Kamus
// P, Q, R, S, T : POINT

// Algoritma
int main(){
    POINT P, Q, R, S, T;  // Deklarasi POINT P, Q, R, S, dan T
    P = MakePOINT(1,1); // MakePoint titik P
    printf("Koordinat titik P : ");
    TulisPOINT(P);

    BacaPOINT(&Q);      // Membaca input user untuk posisi titik Q
    printf("Koordinat titik Q : ");
    TulisPOINT(Q);

    // Menguji kesamaan dua titik
    if (EQ(P, Q)) printf("Titik P dan Q berada di posisi yang sama\n");
    else printf("Titik P dan Q berada di posisi yang berbeda\n");
    // Menguji ketaksamaan dua titik
    if (NEQ(P, Q)) printf("Titik P dan Q berada di posisi yang berbeda\n");
    else printf("Titik P dan Q berada di posisi yang sama\n");

    // Menguji fungsi isOrigin, isOnSbX, isOnSbY, dan Kudran
    if (!(IsOnSbX(P) || IsOnSbY(P))){
        printf("Titik P berada di kuadran %d\n", Kuadran(P));
    } else {
        if (IsOrigin(P)) printf("Titik P berada di titik asal (0,0)\n");
        else if (IsOnSbX(P)) printf("Titik P berada di sumbu X\n");
        else printf("Titik P berada di sumbu Y\n");
    }

    // Menguji fungsi geser
    printf("Menggeser titik P sejauh 1 ke kanan\n");
    P = NextX(P);
    printf("Koordinat titik P sekarang : ");
    TulisPOINT(P);

    printf("Menggeser titik P sejauh 1 ke atas\n");
    P = NextY(P);
    printf("Koordinat titik P sekarang : ");
    TulisPOINT(P);

    // Menguji fungsi geser suatu titik dengan beberapa perubahan
    printf("M<enggeser titik P sejauh 1 ke kanan dan 2 ke atas\n");
    P = PlusDelta(P, 1, 2);
    printf("Koordinat titik P sekarang : ");
    TulisPOINT(P);

    // Menguji fungsi pencerminan suatu titik
    R = MirrorOf(P, true);
    printf("Koordinat titik R ketika titik P dicerminkan terhadap sumbu X : ");
    TulisPOINT(R);
    S = MirrorOf(P, false);
    printf("Koordinat titik R ketika titik P dicerminkan terhadap sumbu Y : ");
    TulisPOINT(S);

    //Menguji fungsi jarak dan panjang antara dua titik
    printf("Jarak titik P terhadap titik asal : %f\n", Jarak0(P));
    printf("Panjang garis antara titik P dan Q adalah sejauh %f\n", Panjang(P, Q));

    // Menguji fungsi geser dengan pointer
    printf("Menggeser titik R sejauh 2 satuan ke kanan dan 2 satuan ke atas\n");
    Geser(&R, 2, 2);
    printf("Koordinat titik R sekarang : ");
    TulisPOINT(R);

    // Menguji fungsi geser ke sumbu X dan Y dengan pointer
    printf("Menggeser titik R ke sumbu X\n");
    GeserKeSbX(&R);
    printf("Koordinat titik R sekarang : ");
    TulisPOINT(R);
    printf("Menggeser titik R ke sumbu Y\n");
    GeserKeSbY(&R);
    printf("Koordinat titik R sekarang : ");
    TulisPOINT(R);

    // Menguji fungsi pencerminan dengan pointer
    printf("Mirror titik P terhadap sumbu X dan sumbu Y\n");
    Mirror(&P, true);       // Pencerminan terhadap sumbu X
    Mirror(&P, false);      // Pencerminan terhadap sumbu Y
    printf("Koordinat titik P sekarang : ");
    TulisPOINT(P);

    // Menguji fungsi putar
    // Awalnya (-3,-4) menjadi (-4,3)
    printf("Memutar POINT P sejauh 90 derajat searah jarum jam\n");
    Putar(&P, 90);
    printf("Koordinat titik P sekarang : ");
    TulisPOINT(P);

    // Menguji fungsi putar
    T = MakePOINT(1,0);             // Membuat titik T di (1,0)
    // Awalnya (1,0) menjadi (0,-1)
    printf("Koordinat titik T sekarang : ");
    TulisPOINT(T);
    printf("Memutar POINT T sejauh 90 derajat searah jarum jam\n");
    Putar(&T, 90);
    printf("Koordinat titik T sekarang : ");
    TulisPOINT(T);
}