// NIM              : 13520105
// Nama             : Malik Akbar Hashemi Rafsanjani 
// Tanggal          : 9 September 2021
// Topik praktikum  : ADT List
// Deskripsi        : Program yang dapat memeriksa apakah list tersebut merupakan Monotonic List atau bukan. 

#include <stdio.h>
#include "listpos.h"
#include "boolean.h"

void monotonicList(ListPos L) {
  // I.S. L terdefinisi
  // F.S. Ditampilkan ke layar apakah list tersebut merupakan Non-ascending Monotonic List atau Non-descending Monotonic List atau Static Monotonic List atau Non-monotonic List

  // KAMUS
  int i, len = length(L);
  ElType prevEl = ELMT(L,0);
  boolean staticMono=true, ascMono=true, descMono=true;

  // ALGORITMA
  for (i=1;i<len;i++) {
    if (ELMT(L,i) != prevEl) {
      staticMono = false;
      break;
    }
  }
  if (staticMono) {
    printf("Static Monotonic List\n");
    return;
  }
  
  for (i=1;i<len;i++) {
    if (ELMT(L,i) > ELMT(L,i-1)){
      descMono = false;
      break;
    }
  }
  if (descMono) {
    printf("Non-ascending Monotonic List\n");
    return;
  }

  for (i=1;i<len;i++) {
    if (ELMT(L,i) < ELMT(L,i-1)){
      ascMono = false;
      break;
    }
  }
  if (ascMono) {
    printf("Non-descending Monotonic List\n");
    return;
  }
  printf("Non-monotonic List\n");
}

// Main Driver
int main() {
  // KAMUS
  ListPos L;
  
  // ALGORITMA
  readList(&L);
  monotonicList(L);
  
  return 0;
}