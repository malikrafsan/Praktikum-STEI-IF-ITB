/* File: mtime.c */
/* Tanggal: 2 September 2021 */
/* 13520023 - Ahmad Alfani Handoyo */

#include <stdio.h>
#include "time.h"

int main() {
    /* KAMUS */
    int N, iter;            /* untuk loop */
    TIME t1, t2, ttemp;     /* memuat waktu setiap loop */
    TIME AwMin, AkhMaks;    /* memuat waktu awal minimal dan waktu akhir maksimal */


    /* ALGORITMA */
    /* ASUMSI waktu di antara rentang waktu 00:00:00 dan 23:59:59 */
    scanf("%d", &iter);

    /* Inisialisasi minimal maksimal waktu */
    AwMin = MakeTIME(23, 59, 59);
    AkhMaks = MakeTIME(0, 0, 0);

    for(N = 1; N <= iter; N++) {
        printf("[%d]\n", N);
        BacaTIME(&t1);
        BacaTIME(&t2);

        if (TGT(t1, t2)) {
            ttemp = t1;
            t1 = t2;
            t2 = ttemp;
        }

        if (TLT(t1, AwMin)) {
            AwMin = t1;
        }
        if (TGT(t2, AkhMaks)) {
            AkhMaks = t2;
        }

        printf("%d\n", Durasi(t1, t2));
    }
    
    // TulisTIME(AwMin);
    printf("%d:%d:%d\n", Hour(AwMin), Minute(AwMin), Second(AwMin));
    // TulisTIME(AkhMaks);
    printf("%d:%d:%d\n", Hour(AkhMaks), Minute(AkhMaks), Second(AkhMaks));
    return 0;
}
