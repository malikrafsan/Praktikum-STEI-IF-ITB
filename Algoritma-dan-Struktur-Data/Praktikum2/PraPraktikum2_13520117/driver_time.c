/* File: driver_time.c */
/* Nama : Hafidz Nur Rahman Ghozali */
/* NIM : 13520117 */
/* Tanggal: 1 September 2021 */
/* ***  MAIN DRIVER TIME *** */

// Import module dan file yang dibutuhkan
#include <stdio.h>
#include "time.h"

// Kamus
// T1, T2, T3 : TIME

// Algoritma
int main(){
    TIME T1, T2, T3;            // Deklarasi TIME T1 dan T2
    T1 = MakeTIME(0,0,0);       // Maketime T1
    printf("T1 = ");
    TulisTIME(T1);

    BacaTIME(&T2);              // Membaca input dari user
    printf("T2 = ");
    TulisTIME(T2);

    // Menguji fungsi koversi Time ke Detik
    printf("Jumlah detik T1 dari pukul 00:00:00 = %ld\n", TIMEToDetik(T1));
    //Menguji fungsi konversi Detik ke Time
    printf("5000 detik dari pukul 00:00:00 adalah ");
    T3 = DetikToTIME(5000);
    printf("T3 = ");
    TulisTIME(T3);

    // Menguji kesamaan antara dua Time
    if (TEQ(T1, T2)) printf("T1 dan T2 menunjukkan waktu yang sama\n");
    else printf("T1 dan T2 tidak menunjukkan waktu yang sama\n");

    // Menguji ketaksamaan antara dua Time
    if (TNEQ(T1, T2)) printf("T1 dan T2 tidak menunjukkan waktu yang sama\n");
    else printf("T1 dan T2 menunjukkan waktu yang sama\n");

    // Menguji fungsi TLT
    if (TLT(T1, T2)) printf("T1 lebih dahulu dibanding T2\n");
    else printf("T2 lebih dahulu dibanding T1\n");

    // Menguji fungsi TGT
    if (TGT(T1, T2)) printf("T2 lebih dahulu dibanding T1\n");
    else printf("T1 lebih dahulu dibanding T2\n");

    // Menguji fungsi NextDetik
    printf("T3 ditambah 1 detik\n");
    T3 = NextDetik(T3);
    printf("T3 = ");
    TulisTIME(T3);

    // Menguji fungsi NextNDetik
    printf("T3 ditambah 100 detik\n");
    T3 = NextNDetik(T3, 100);
    printf("T3 = ");
    TulisTIME(T3);

    // Menguji fungsi PrevDetik
    printf("T1 dikurangi 1 detik\n");
    T1 = PrevDetik(T1);
    printf("T1 = ");
    TulisTIME(T1);

    // Menguji fungsi PrevNDetik
    printf("T1 dikurangi 1000 detik\n");
    T1 = PrevNDetik(T1, 1000);
    printf("T1 = ");
    TulisTIME(T1);

    // Menguji fungsi Durasi antara dua Time
    printf("Durasi dari T1 ke T2 adalah sebesar %d detik\n", Durasi(T1, T2));
}