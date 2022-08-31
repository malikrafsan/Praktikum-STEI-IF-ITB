// NIM              : 13520105
// Nama             : Malik Akbar Hashemi Rafsanjani 
// Tanggal          : 9 September 2021
// Topik praktikum  : ADT List
// Deskripsi        : Driver dari listpos.h

#include <stdio.h>
#include "listpos.h"
#include "boolean.h"

void findMedian(ListPos l, ElType *median);

int main(){
  // KAMUS
  int X, idx, max, min, median;
  ListPos L;
  
  // ALGORITMA
  readList(&L);
  displayList(L);
  printf("\n");

  scanf("%d", &X);
  idx = indexOf(L,X);
  if (idx != IDX_UNDEF) {
    printf("%d\n", idx);
    extremes(L,&max,&min);
    findMedian(L,&median);
    if (X == max)
      printf("maksimum\n");
    if (X == min)
      printf("minimum\n");
    if (X == median)
      printf("median\n");
  }
  else
    printf("%d tidak ada\n",X);

  return 0;
}

void findMedian(ListPos l, ElType *median) {
  // KAMUS
  int len;
  ListPos copyL;
  
  // ALGORITMA
  copyL = l;
  sort(&copyL, true);
  len = length(copyL);
  if (len % 2 == 0) {
    *median = ELMT(copyL, (len/2) -1);
  }
  else {
    *median = ELMT(copyL, len/2);
  }
}