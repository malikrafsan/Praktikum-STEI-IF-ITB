/* File: point.c */
/* Tanggal: 1 September 2021 */
/* 13520023 - Ahmad Alfani Handoyo */

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    /* KAMUS LOKAL*/
    POINT poin;
    /* ALGORITMA */
    Absis(poin) = X;
    Ordinat(poin) = Y;
    return poin;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    /* KAMUS LOKAL*/
    float x, y;
    /* ALGORITMA */
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
}

void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */       
    /* ALGORITMA */    
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}     

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    /* ALGORITMA */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    /* ALGORITMA */
    return !((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    /* ALGORITMA */
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    /* ALGORITMA */
    return Ordinat(P) == 0;
}

boolean IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    /* ALGORITMA */
    return Absis(P) == 0;
}

int Kuadran (POINT P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    /* KAMUS LOKAL*/
    float x = Absis(P);
    float y = Ordinat(P);
    int kuadran;
    /* ALGORITMA */
    if (x > 0) {
        if (y > 0) {
            kuadran = 1;
        } else {
            kuadran = 4;
        }
    } else {
        if (y > 0) {
            kuadran = 2;
        } else {
            kuadran = 3;
        }
    }
    return kuadran;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P) {
/* Mengirim salinan P dengan absis ditambah satu */
    /* ALGORITMA */
    return MakePOINT(Absis(P) + 1, Ordinat(P));
}
POINT NextY (POINT P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
    /* ALGORITMA */
    return MakePOINT(Absis(P), Ordinat(P) + 1);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    /* ALGORITMA */
    return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}

POINT MirrorOf (POINT P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    /* ALGORITMA */
    if (SbX) {
        Ordinat(P) *= -1;
    } else {
        Absis(P) *= -1;
    }
    return MakePOINT(Absis(P), Ordinat(P));
}

float Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
    /* KAMUS LOKAL*/
    float x = Absis(P);
    float y = Ordinat(P);
    /* ALGORITMA */
    return sqrt((x * x) + (y * y));
}

float Panjang (POINT P1, POINT P2) {
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
/* Menghitung jarak antara P1(a,b) dan P2(c,d) */
    /* KAMUS LOKAL*/
    float a, b, c,d, dx, dy;
    /* ALGORITMA */
    a = Absis(P1);
    b = Ordinat(P1);
    c = Absis(P2);
    d = Ordinat(P2);
    dx = a-c;
    dy = b-d;
    return sqrt((dx * dx)+(dy * dy));
}

void Geser (POINT *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    /* ALGORITMA */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P) {
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    /* ALGORITMA */
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P) {
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    /* ALGORITMA */
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX) {
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    /* ALGORITMA */
    if (SbX) {
        Ordinat(*P) *= -1;
    } else {
        Absis(*P) *= -1;
    }
}

void Putar (POINT *P, float Sudut) {
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    /* KAMUS LOKAL */
    float x, y, Rad;
    /* ALGORITMA */
    Rad = M_PI * (Sudut/180);
    x = Absis(*P);
    y = Ordinat(*P);
    /* Clockwise rotation berarti matriks rotasi [[cos(theta),sin(theta)],[-sin(theta),cos(theta)]] */
    Absis(*P) = x * cos(Rad) + y * sin(Rad);
    Ordinat(*P) = (-x) * sin(Rad) + y * cos(Rad);
}
