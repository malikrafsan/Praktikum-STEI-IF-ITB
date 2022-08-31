/* File: point.c */
/* Nama : Hafidz Nur Rahman Ghozali */
/* NIM : 13520117 */
/* Tanggal: 1 September 2021 */
/* ***  FILE BODY TIME *** */

#include <stdio.h>
#include "time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
    return (H>=0 && H<24 && M>=0 && M<=59 && S>=0 && S<=59);
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */

TIME MakeTIME (int HH, int MM, int SS){
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

// Kamus Lokal
// T : TIME

// Algoritma
    TIME T;
    Hour(T) = HH;
    Minute(T) = MM;
    Second(T) = SS;

    return T;       // Mengembalikan TIME T
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */

    // Kamus lokal
    int H, M, S;

    // Algoritma
    // do {
    //     scanf("%d %d %d", &H, &M, &S);
    // } while (!(IsTIMEValid(H, M, S)));

    while(1){
        scanf("%d %d %d", &H, &M, &S);
        if (IsTIMEValid(H, M, S)) break;
        else printf("Jam tidak valid.\n");
    }
    *T = MakeTIME(H, M, S);             // Membuat TIME dengan H, M, dan S yang sudah valid
}
   
void TulisTIME (TIME T){
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

    // Algoritma
    if (Hour(T) > 9) printf("%d:", Hour(T));        // Print hour
    else printf("0%d:", Hour(T));
    if (Minute(T) > 9) printf("%d:", Minute(T));    // Print minute
    else printf("0%d:", Minute(T));
    if (Second(T) > 9) printf("%d\n", Second(T));   // Print Second
    else printf("0%d\n", Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

    // Algoritma
    return 3600*Hour(T) + 60*Minute(T)+ Second(T);  // Mengembalikan total detik
}

TIME DetikToTIME (long N){
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME 
   Asumsi N selalu bernilai tak negatif*/

    // Kamus
    // T : TIME

    // Algoritma
    N %= 86400;
    TIME T;
    Hour(T) = N/3600;
    N = N%3600;
    Minute(T) = N/60;
    N = N%60;
    Second(T) = N;

    return T;           // Mengembalikan TIME T
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
/* Mengirimkan true jika T1=T2, false jika tidak */
    
    // Algoritma 
    return (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2));
}
boolean TNEQ (TIME T1, TIME T2){
/* Mengirimkan true jika T1 tidak sama dengan T2 */

    // Algoritma
    return !(Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2));
}
boolean TLT (TIME T1, TIME T2){
/* Mengirimkan true jika T1<T2, false jika tidak */

    // Kamus
    //  Detik1, Detik2 : long

    // Algoritma
    long Detik1, Detik2;
    Detik1 = TIMEToDetik(T1);
    Detik2 = TIMEToDetik(T2);
    if (Detik2 > Detik1) return true;
    else return false;
}
boolean TGT (TIME T1, TIME T2){
/* Mengirimkan true jika T1>T2, false jika tidak */

    // Kamus
    //  Detik1, Detik2 : long

    // Algoritma
    long Detik1, Detik2;
    Detik1 = TIMEToDetik(T1);
    Detik2 = TIMEToDetik(T2);
    if (Detik1 > Detik2) return true;
    else return false;
}
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
/* Mengirim 1 detik setelah T dalam bentuk TIME */

    // Kamus
    // Detik : long integer

    // Algoritma
    long Detik = TIMEToDetik(T);
    Detik += 1;
    T = DetikToTIME(Detik);
    return T;
}
TIME NextNDetik (TIME T, int N){
/* Mengirim N detik setelah T dalam bentuk TIME */

    // Kamus
    // Detik : long integer

    // Algoritma
    long Detik = TIMEToDetik(T);
    Detik += N;
    T = DetikToTIME(Detik);
    return T;
}
TIME PrevDetik (TIME T){
/* Mengirim 1 detik sebelum T dalam bentuk TIME */

    // Kamus
    // Detik : long integer

    // Algoritma
    int Detik = TIMEToDetik(T);
    Detik += 86399;
    T = DetikToTIME(Detik);
    return T;
}
TIME PrevNDetik (TIME T, int N){
/* Mengirim N detik sebelum T dalam bentuk TIME */

    // Kamus
    // Detik : long integer

    // Algoritma
    N %= 86400;
    long Detik = TIMEToDetik(T);
    Detik = Detik + 86400 - N;
    T = DetikToTIME(Detik);
    return T;
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

    // Algoritma
    if (TLT(TAw, TAkh)) return (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
    else return (86400 + TIMEToDetik(TAkh) - TIMEToDetik(TAw));
}