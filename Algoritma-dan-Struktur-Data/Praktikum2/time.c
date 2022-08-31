/* File: time.c */
/* Nama : Malik Akbar Hashemi Rafsanjani */
/* NIM : 13520105 */
/* Tanggal: 1 September 2021 */
/* Implementasi ADT TIME */

#include <stdio.h>
#include "time.h"
#include "boolean.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S) {
  /* Mengirim true jika H,M,S dapat membentuk T yang valid */
  /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

  // ALGORITMA
  return (H>=0 && H<=23 && M>=0 && M<=59 && S>=0 && S<=59);
}


/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
TIME MakeTIME (int HH, int MM, int SS){
  /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
  /* Prekondisi : HH, MM, SS valid untuk membentuk TIME */  
  
  // KAMUS
  TIME T;

  // ALGORITMA
  Hour(T) = HH;
  Minute(T) = MM;
  Second(T) = SS;

  return T;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T) {
  /* I.S. : T tidak terdefinisi */
  /* F.S. : T terdefinisi dan merupakan jam yang valid */

  // KAMUS
  int inputH, inputM, inputS;
  
  // ALGORITMA
  while (true) {
    scanf("%d %d %d",&inputH,&inputM,&inputS);
    if (IsTIMEValid(inputH,inputM,inputS))
      break;
    printf("Jam tidak valid\n");
  }
  *T = MakeTIME(inputH, inputM, inputS);

  // APLIKASI
  /* Contoh: 
    60 3 4
    Jam tidak valid
    1 3 4
    --> akan terbentuk TIME <1,3,4> */
}

void TulisTIME (TIME T) {
  /* I.S. : T sembarang */
  /* F.S. : Nilai T ditulis dg format HH:MM:SS */

  // ALGORITMA
  if (Hour(T) <= 9) printf("0");
  printf("%d:",Hour(T));
  if (Minute(T) <= 9) printf("0");
  printf("%d:",Minute(T));
  if (Second(T) <= 9) printf("0");
  printf("%d",Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
  /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
  
  // ALGORITMA
  return (3600*Hour(T) + 60*Minute(T) + Second(T));
}

TIME DetikToTIME (long N){
  /* Mengirim  konversi detik ke TIME */
  /* Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang mewakili jumlah detik yang mungkin dalam 1 hari */
  // Prekondisi: N tidak negatif

  // KAMUS
  TIME T;
  long N1 = N % 86400;
  
  // ALGORITMA
  Hour(T) = N1 / 3600;
  Minute(T) = (N1 % 3600) / 60;
  Second(T) = N1 % 60;

  return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2) {
  /* Mengirimkan true jika T1=T2, false jika tidak */

  // ALGORITMA
  return ((Hour(T1) == Hour(T2)) && 
          (Minute(T1) == (Minute(T2))) && 
          (Second(T1) == Second(T2)));
}

boolean TNEQ (TIME T1, TIME T2) {
  /* Mengirimkan true jika T1 tidak sama dengan T2 */

  // ALGORITMA
  return (!TEQ(T1,T2));
}

boolean TLT (TIME T1, TIME T2) {
  /* Mengirimkan true jika T1<T2, false jika tidak */

  // ALGORITMA
  return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT (TIME T1, TIME T2) {
  /* Mengirimkan true jika T1>T2, false jika tidak */

  // ALGORITMA
  return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T) {
  /* Mengirim 1 detik setelah T dalam bentuk TIME */

  // ALGORITMA
  if (Second(T) != 59)
    return MakeTIME(Hour(T),Minute(T),Second(T)+1);
  else if (Minute(T) != 59)
    return MakeTIME(Hour(T),Minute(T)+1,0);
  else if (Hour(T) != 23)
    return MakeTIME(Hour(T)+1,0,0);
  else
    return MakeTIME(0,0,0);
}

TIME NextNDetik (TIME T, int N) {
  /* Mengirim N detik setelah T dalam bentuk TIME */
  
  // ALGORITMA
  return DetikToTIME(TIMEToDetik(T)+N);
}

TIME PrevDetik (TIME T) {
  /* Mengirim 1 detik sebelum T dalam bentuk TIME */

  // ALGORITMA
  if (Second(T) != 0)
    return MakeTIME(Hour(T),Minute(T),Second(T)-1);
  else if (Minute(T) != 0)
    return MakeTIME(Hour(T),Minute(T)-1,59);
  else if (Hour(T) != 0)
    return MakeTIME(Hour(T)-1,59,59);
  else
    return MakeTIME(23,59,59);
}

TIME PrevNDetik (TIME T, int N) {
  /* Mengirim N detik sebelum T dalam bentuk TIME */
  
  // ALGORITMA
  N %= 86400;
  return DetikToTIME(TIMEToDetik(T)-N+86400);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh) {
  /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
  /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

  // ALGORITMA
  if (TLT(TAw,TAkh))
    return (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
  else
    return (TIMEToDetik(TAkh) - TIMEToDetik(TAw) + 86400);
}
