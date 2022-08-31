#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

int main() {
  int N,M, i,j, curSum;
  Matrix mat;
  ElType max, min;

  scanf("%d",&N);
  readMatrix(&mat,N,N);

  printf("ROW MEAN: %f\n", rowMean(mat,0));
  printf("COL MEAN: %f\n", colMean(mat,1));
  rowExtremes(mat,0,&max,&min);
  printf("MAX MIN ROW: %d %d\n", max,min);
  colExtremes(mat,0,&max,&min);
  printf("MAX MIN COL: %d %d\n", max,min);
  printf("COUNT 5 ROW 0: %d\n", countValOnRow(mat,0,5));
  printf("COUNT 5 COL 0: %d\n", countValOnCol(mat,0,5));

  return 0;
}