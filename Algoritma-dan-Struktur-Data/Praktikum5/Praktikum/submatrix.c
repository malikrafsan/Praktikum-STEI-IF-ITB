#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

int sumSubMatrix(Matrix mat, int idxStartI, int idxStartJ, int size) {
  int i,j,sum;

  sum = 0;
  for (i=idxStartI; i<=(idxStartI+size-1); i++) {
    for (j=idxStartJ; j<=(idxStartJ+size-1); j++) {
      sum += ELMT(mat,i,j);
    }
  }
  return sum;
}

void solve() {
  int N,M, i,j, max, curSum;
  Matrix mat;

  scanf("%d",&N);
  readMatrix(&mat,N,N);
  scanf("%d",&M);

  max = sumSubMatrix(mat,0,0,M);
  for (i=0;i<=(N-M);i++) {
    for (j=0;j<=(N-M);j++) {
      curSum = sumSubMatrix(mat,i,j,M);
      if (curSum > max)
        max = curSum;    
    }
  }
  printf("%d\n",max);
}

int main() {
  int TC,i;

  scanf("%d",&TC);
  for (i=0;i<TC;i++) {
    solve();
  }

  return 0;
}