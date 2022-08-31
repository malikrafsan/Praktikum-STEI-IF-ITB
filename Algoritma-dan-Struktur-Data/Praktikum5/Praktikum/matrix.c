#include "boolean.h"
#include "matrix.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m) {
  ROWS(*m) = nRow;
  COLS(*m) = nCol;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j) {
  return (i < ROW_CAP && i >= 0 && j < COL_CAP && j >= 0);
}
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m) {
  return (ROWS(m) - 1);
}
/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol(Matrix m) {
  return (COLS(m) - 1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j) {
  return (i >= 0 && i < ROWS(m) && j >= 0 && j < COLS(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, Index i) {
  return (ELMT(m,i,i));
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
  *mRes = mIn;
}
/* Melakukan assignment MRes = MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
  int i,j;
  
  CreateMatrix(nRow, nCol, m);
  for (i=0;i<nRow;i++) {
    for (j=0;j<nCol;j++) {
      scanf("%d",&ELMT(*m,i,j));
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
void displayMatrix(Matrix m) {
  int i,j;
  
  for (i=0;i<ROWS(m);i++) {
    printf("%d",ELMT(m,i,0));
    for (j=1;j<COLS(m);j++) {
      printf(" %d",ELMT(m,i,j));
    }
    if (i!=(ROWS(m)-1)) {
      printf("\n"); 
    }
  }
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
Matrix addMatrix(Matrix m1, Matrix m2) {
  int i, j;
  Matrix m3;

  CreateMatrix(ROWS(m1),COLS(m1), &m3);

  for (i=0;i<ROWS(m1);i++) {
    for (j=0;j<COLS(m1);j++){
      ELMT(m3,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
    }
  }
  // displayMatrix(m3);
  return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2) {
  int i, j;
  Matrix m3;

  CreateMatrix(ROWS(m1),COLS(m1),&m3);

  for (i=0;i<ROWS(m1);i++) {
    for (j=0;j<COLS(m1);j++){
      ELMT(m3,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
    }
  }
  return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
  int i, j,k;
  Matrix m3;

  CreateMatrix(ROWS(m1),COLS(m2),&m3);

  // printf("ROWS: %d COLS: %d\n",ROWS(m1),COLS(m2));
  // printf("ROWS: %d COLS: %d\n", ROWS(m3),COLS(m3));

  for (i=0;i<ROWS(m1);i++) {
    for (j=0;j<COLS(m2);j++) {
      ELMT(m3,i,j) = 0;
      for (k=0;k<ROWS(m2);k++) {
        ELMT(m3,i,j) += ELMT(m1,i,k) * ELMT(m2,k,j);
      }
      // printf("%d ",ELMT(m3,i,j));
    }
    // printf("\n");
  }

  // printf("\n");
  // displayMatrix(m3); printf("\n");

  return m3;
}

// void mulMat(int mat1[][C1], int mat2[][C2]) {
//     int rslt[R1][C2];
 
//     printf("Multiplication of given two matrices is:\n\n");
 
//     for (int i = 0; i < R1; i++) {
//         for (int j = 0; j < C2; j++) {
//             rslt[i][j] = 0;
 
//             for (int k = 0; k < R2; k++) {
//                 rslt[i][j] += mat1[i][k] * mat2[k][j];
//             }
 
//             printf("%d\t", rslt[i][j]);
//         }
 
//         printf("\n");
//     }
// }

/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyConst(Matrix m, ElType x) {
  int i, j;
  Matrix mNew;

  CreateMatrix(ROWS(m),COLS(m),&mNew);

  for (i=0;i<ROWS(m);i++) {
    for (j=0;j<COLS(m);j++){
      ELMT(mNew,i,j) = x * ELMT(m,i,j);
    }
  }
  return mNew;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConst(Matrix *m, ElType k) {
  int i, j;

  for (i=0;i<ROWS(*m);i++) {
    for (j=0;j<COLS(*m);j++){
      ELMT(*m,i,j) = k * ELMT(*m,i,j);
    }
  }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2) {
  int i, j;
  
  if ((ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2))) {
    for (i=0;i<ROWS(m1);i++){
      for (j=0;j<COLS(m1);j++) {
        if (ELMT(m1,i,j) != ELMT(m2,i,j))
          return false;
      }
    }
    return true;
  }
  else
    return false;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isNotEqual(Matrix m1, Matrix m2) {
  return (!isEqual(m1,m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isSizeEqual(Matrix m1, Matrix m2) {
  return ((ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2)));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */

/* ********** Operasi lain ********** */
int count(Matrix m) {
  return (ROWS(m) * COLS(m));
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
  return (ROWS(m) == COLS(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m) {
  int i,j;
  
  if (isSquare(m)) {
    for (i=0;i<ROWS(m);i++) {
      for (j=0;j<COLS(m);j++) {
        if (ELMT(m,i,j) != ELMT(m,j,i))
          return false;
      }
    }
    return true;
  }
  else
    return false;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m) {
  int i, j;

  for (i=0;i<ROWS(m);i++){
    for (j=0;j<COLS(m);j++) {
      if (i==j && ELMT(m,i,j) != 1)
        return false;
      if (i!=j && ELMT(m,i,j) != 0)
        return false;
    }
  }
  return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m) {
  int countElem = count(m);
  double countNot0 = 0.0;
  int i,j;
  double persentage;

  for (i=0;i<ROWS(m);i++){
    for (j=0;j<COLS(m);j++){
      if (ELMT(m,i,j) != 0)
        countNot0++;
    }
  }
  persentage = countNot0 / countElem; 

  if (persentage <= 0.05)
    return true;
  else
    return false;
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix inverse1(Matrix m) {
  int i,j;
  Matrix m1;
  CreateMatrix(ROWS(m),COLS(m),&m1);

  for(i=0;i<ROWS(m);i++) {
    for (j=0;j<COLS(m);j++) {
      ELMT(m1,i,j) = (-1) * ELMT(m,i,j);
    }
  }
  return m1;
}
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
void pInverse1(Matrix *m) {
  int i,j;
  
  for(i=0;i<ROWS(*m);i++) {
    for (j=0;j<COLS(*m);j++) {
      ELMT(*m,i,j) = (-1) * ELMT(*m,i,j);
    }
  }
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

Matrix subMatrix(Matrix matOri, int rowBan, int colBan) {
  int i,j;
  int idxRow, idxCol;
  Matrix newMat;

  CreateMatrix(ROWS(matOri)-1, COLS(matOri)-1, &newMat);

  idxRow = 0;
  for (i=0;i<ROWS(matOri);i++) {
    idxCol = 0;
    for (j=0;j<ROWS(matOri);j++) {
      if (i != rowBan && j != colBan) {
        ELMT(newMat, idxRow, idxCol) = ELMT(matOri,i,j);
        // printf("(newMat,%d,%d): %d\n",idxRow,idxCol, ELMT(newMat, idxRow, idxCol));

        idxCol++;
        if (idxCol == COLS(matOri)-1) {
          idxCol = 0;
          idxRow++;
        }
      } 
      // else {
      //   printf("rowban: %d colban: %d i: %d j: %d\n",rowBan,colBan,i,j);
      // }
    }
    // printf("\n");
  }
  // printf("ORI MAT\n");
  // displayMatrix(matOri); printf("\n");
  // printf("NEW MAT\n");
  // displayMatrix(newMat); printf("\n");
  return newMat;
}

float determinant(Matrix m) {
  int sign, i;
  float sum;
  Matrix cofactors;

  if (ROWS(m) == 1) {
    // printf("%d\n", ELMT(m,0,0));
    return ELMT(m,0,0);
  }
  // if (ROWS(m) == 2) {
  //   displayMatrix(m); printf("\n");
  // }
  CreateMatrix(ROWS(m)-1, COLS(m)-1, &cofactors);
  sum = 0; sign = 1;

  for (i=0; i<ROWS(m); i++) {
    cofactors = subMatrix(m,0,i);
    sum += sign * ELMT(m,0,i) * determinant(cofactors);

    sign = -sign;
  }
  // printf("MAT %d, SUM: %f\n",ROWS(m),sum);

  return sum;
}

/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */

void transpose(Matrix *m) {
  int i,j;
  Matrix m1;

  copyMatrix(*m,&m1);

  for (i=0;i<ROWS(*m);i++){
    for (j=0;j<COLS(*m);j++) {
      ELMT(*m,i,j) = ELMT(m1,j,i);
    }
  }
}
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */


// int main() {
//   Matrix m1,m2,m3,m4,m5,m6;
//   CreateMatrix(2,4,&m1);
//   readMatrix(&m1,2,4);

//   CreateMatrix(4,3,&m2);
//   readMatrix(&m2,4,3);

//   printf("ori matrix\n");
//   displayMatrix(m1);
//   printf("\n\n");
//   printf("Determinant: %f\n", determinant(m1));

//   printf("\n");

//   m3 = multiplyMatrix(m1,m2);
//   printf("m3 mat\n");
//   displayMatrix(m3); printf("\n");

//   printf("\n");

//   copyMatrix(m1,&m2);
//   printf("m2 mat\n");
//   displayMatrix(m2); printf("\n");
//   ELMT(m2,1,1) = 1;
//   printf("m1 mat\n");
//   displayMatrix(m1); printf("\n");
//   printf("m2 mat\n");
//   displayMatrix(m2); printf("\n");

//   if (isSparse(m3))
//     printf("Sparse\n");
//   else
//     printf("Not Sparse\n");

//   pMultiplyConst(&m3,2);
//   printf("m3 multiplyConst\n");
//   displayMatrix(m3); printf("\n");

//   copyMatrix(m3,&m4);
//   if (isEqual(m3,m4))
//     printf("copy success\n");
//   else
//     printf("copy unsuccess\n");

//   if (isSizeEqual(m3,m4))
//     printf("size equal\n");
//   else {
//     printf("M3 row:%d col:%d", ROWS(m3),COLS(m3));
//     printf("M4 row:%d col:%d", ROWS(m4),COLS(m4));
//   }
//   printf("COUNT: %d\n", count(m4));
//   if (isSquare(m4))
//     printf("square\n");

//   if (isSymmetric(m1))
//     printf("symmetric\n");
  
//   if (isIdentity(m1))
//     printf("identity\n");

//   m5 = inverse1(m4);
//   displayMatrix(m5); printf("\n");
//   pInverse1(&m5);
//   displayMatrix(m5); printf("\n");

//   printf("\n\n");
//   printf("TRANSPOSE\n");
//   copyMatrix(m5,&m6);
//   transpose(&m6);
//   displayMatrix(m6); printf("\n");

//   return 0;
// }


// void subMatrix(int mat[N][N], int temp[N][N], int p, int q, int n) {
//    int i = 0, j = 0;
//    // filling the sub matrix
//    for (int row = 0; row < n; row++) {
//       for (int col = 0; col < n; col++) {
//          // skipping if the current row or column is not equal to the current
//          // element row and column
//          if (row != p && col != q) {
//             temp[i][j++] = mat[row][col];
//             if (j == n - 1) {
//                j = 0;
//                i++;
//             }
//          }
//       }
//    }
// }
// int determinantOfMatrix(int matrix[N][N], int n) {
//    int determinant = 0;
//    if (n == 1) {
//       return matrix[0][0];
//    }
//    if (n == 2) {
//       return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
//    }
//    int temp[N][N], sign = 1;
//    for (int i = 0; i < n; i++) {
//       subMatrix(matrix, temp, 0, i, n);
//       determinant += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);
//       sign = -sign;
//    }
//    return determinant;
// }

// int determinant( int matrix[10][10], int n) {
//    int det = 0;
//    int submatrix[10][10];
//    if (n == 2)
//    return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
//    else {
//       for (int x = 0; x < n; x++) {
//          int subi = 0;
//          for (int i = 1; i < n; i++) {
//             int subj = 0;
//             for (int j = 0; j < n; j++) {
//                if (j == x)
//                continue;
//                submatrix[subi][subj] = matrix[i][j];
//                subj++;
//             }
//             subi++;
//          }
//          det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
//       }
//    }
//    return det;
// }

// void getCofactor(int mat[N][N], int temp[N][N], int p,
//                  int q, int n)
// {
//     int i = 0, j = 0;
 
//     // Looping for each element of the matrix
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < n; col++)
//         {
//             //  Copying into temporary matrix only those
//             //  element which are not in given row and
//             //  column
//             if (row != p && col != q)
//             {
//                 temp[i][j++] = mat[row][col];
 
//                 // Row is filled, so increase row index and
//                 // reset col index
//                 if (j == n - 1)
//                 {
//                     j = 0;
//                     i++;
//                 }
//             }
//         }
//     }
// }
 
// /* Recursive function for finding determinant of matrix.
//    n is current dimension of mat[][]. */
// int determinantOfMatrix(int mat[N][N], int n)
// {
//     int D = 0; // Initialize result
 
//     //  Base case : if matrix contains single element
//     if (n == 1)
//         return mat[0][0];
 
//     int temp[N][N]; // To store cofactors
 
//     int sign = 1; // To store sign multiplier
 
//     // Iterate for each element of first row
//     for (int f = 0; f < n; f++)
//     {
//         // Getting Cofactor of mat[0][f]
//         getCofactor(mat, temp, 0, f, n);
//         D += sign * mat[0][f]
//              * determinantOfMatrix(temp, n - 1);
 
//         // terms are to be added with alternate sign
//         sign = -sign;
//     }
 
//     return D;
// }