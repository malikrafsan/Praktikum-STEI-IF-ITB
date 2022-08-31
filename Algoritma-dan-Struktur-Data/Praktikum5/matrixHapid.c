// Nama : Hafidz Nur Rahman Ghozali
// NIM  : 13520117
// Nama File : Matrix.c

#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m){
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
    for (int i=0; i<nRow; i++){
        for (int j=0; j<nCol; j++){
            ELMT(*m,i,j) = 0;
        }
    }
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j){
    return ((i>=0 && i<ROW_CAP) && (j>=0 && j<COL_CAP));
}
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
    return (ROWS(m)-1);
}
/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol(Matrix m){
    return (COLS(m)-1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j){
    return ((i>=0 && i<=getLastIdxRow(m))&&(j>=0 && j<=getLastIdxCol(m)));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, Index i){
    return ELMT(m, i, i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    int i,j;

    for (int i=0; i<ROWS(mIn); i++){
        for (int j=0; j<COLS(mIn); j++){
            ELMT(*mRes,i,j) = ELMT(mIn,i,j);
        }
    }
}
/* Melakukan assignment MRes = MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    CreateMatrix(nRow, nCol, m);
    for (int i=0; i<ROWS(*m); i++){
        for (int j=0; j<COLS(*m); j++){
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    for (int i=0; i<ROWS(m)-1; i++){
        for (int j=0; j<COLS(m)-1; j++){
            printf("%d ",ELMT(m,i,j));
        }
        printf("%d\n", ELMT(m,i,COLS(m)-1));
    }
    for (int j=0; j<COLS(m)-1; j++){
        printf("%d ",ELMT(m,ROWS(m)-1,j));
    }
    printf("%d", ELMT(m,ROWS(m)-1,COLS(m)-1));
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix mNew;
    CreateMatrix(ROWS(m1), COLS(m1), &mNew);
    for (int i=0; i<ROWS(mNew); i++){
        for (int j=0; j<COLS(mNew); j++){
            ELMT(mNew,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }

    return mNew;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix mNew;
    CreateMatrix(ROWS(m1), COLS(m1), &mNew);
    for (int i=0; i<ROWS(mNew); i++){
        for (int j=0; j<COLS(mNew); j++){
            ELMT(mNew,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }

    return mNew;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix mNew;
    CreateMatrix(ROWS(m1), COLS(m2), &mNew);
    for (int i=0; i<ROWS(mNew); i++){
        for (int j=0; j<COLS(mNew); j++){
            ELMT(mNew,i,j) = 0;
            for (int k=0; k<=COLS(m1); k++){
                ELMT(mNew,i,j) += ELMT(m1,i,k)*ELMT(m2,k,j);
            }
        }
    }

    return mNew;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyConst(Matrix m, ElType x){
    Matrix mNew;
    CreateMatrix(ROWS(m), COLS(m), &mNew);
    for (int i=0; i<ROWS(mNew); i++){
        for (int j=0; j<COLS(mNew); j++){
            ELMT(mNew,i,j) = ELMT(m,i,j)*x;
        }
    }

    return mNew;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConst(Matrix *m, ElType k){
    for (int i=0; i<ROWS(*m); i++){
        for (int j=0; j<COLS(*m); j++){
           ELMT(*m,i,j) *= k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2){
    if (!isSizeEqual(m1,m2)) return false;
    for (int i=0; i<ROWS(m1); i++){
        for (int j=0; j<COLS(m1); j++){
            if (ELMT(m1,i,j) != ELMT(m2,i,j)) return false;
        }
    }

    return true;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isNotEqual(Matrix m1, Matrix m2){
    return !isEqual(m1,m2);
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isSizeEqual(Matrix m1, Matrix m2){
    return (ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */

/* ********** Operasi lain ********** */
int count(Matrix m){
    return ((ROWS(m))*(COLS(m)));
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return (ROWS(m) == COLS(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
    if (!isSquare(m)) return false;
    else {
        for (int i=0; i<ROWS(m); i++){
            for (int j=0; j<COLS(m); j++){
                if (ELMT(m,i,j) != ELMT(m,j,i)) return false;
            }
        }
    }

    return true;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
    if (!isSquare(m)) return false;
    for (int i=0; i<ROWS(m); i++){
        if (ELMT(m,i,i) != 1) return false;
        else {
            for (int j=0; j<COLS(m); j++){
                if (ELMT(m,i,j) != 0 && i != j) return false;
            }
        }
    }

    return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
    double persen = 0;

    for (int i=0; i<ROWS(m); i++){
        for (int j=0; j<COLS(m); j++){
            if (ELMT(m,i,j) != 0) persen += 1;
        }
    }
    persen /= count(m);

    if (persen > 0.05) return false;
    return true;
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix inverse1(Matrix m){
    Matrix mNew;
    CreateMatrix(ROWS(m), COLS(m), &mNew);
    for (int i=0; i<ROWS(mNew); i++){
        for (int j=0; j<COLS(mNew); j++){
            ELMT(mNew,i,j) = ELMT(m,i,j)*(-1);
        }
    }

    return mNew;
}
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
void pInverse1(Matrix *m){
    for (int i=0; i<ROWS(*m); i++){
        for (int j=0; j<COLS(*m); j++){
            ELMT(*m,i,j) *= (-1);
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

Matrix makeOne(Matrix m, int row, int col){
    int n = ROWS(m);
    Matrix mNew;
    CreateMatrix(n-1, n-1, &mNew);

    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            if (i<row){
                if (j<col) ELMT(mNew,i,j) = ELMT(m,i,j);
                else if (j>col) ELMT(mNew,i,j-1) = ELMT(m,i,j);
            } else if (i>row){
                if (j<col) ELMT(mNew,i-1,j) = ELMT(m,i,j);
                else if (j>col) ELMT(mNew,i-1,j-1) = ELMT(m,i,j);
            }
        }
    }
    return mNew;
}
float determinant(Matrix m){
    int det;
    int n = ROWS(m); 
    if (n == 1) return ELMT(m,0,0);
    else {
        for (int i=0; i<n; i++){
            int c = 1;
            if (i%2 == 1) c = -1;

            int temp = determinant(makeOne(m,0,i));

            det += c*ELMT(m,0,i)*temp;
        }
    }

    return det;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
void transpose(Matrix *m){
    for (int i=0; i<ROWS(*m); i++){
        for (int j=0; j<=i; j++){
            ElType temp = ELMT(*m,i,j);
            ELMT(*m,i,j) = ELMT(*m,j,i);
            ELMT(*m,j,i) = temp;
        }
    }
    
}
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */