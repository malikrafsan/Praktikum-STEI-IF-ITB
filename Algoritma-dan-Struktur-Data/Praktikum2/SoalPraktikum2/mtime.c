#include <stdio.h>
#include "time.h"
#include "boolean.h"

TIME FirstTime, LastTime;

void solve();

int main() {
  // KAMUS
  int N, i;

  // ALGORITMA
  FirstTime = MakeTIME(23,59,59);
  LastTime = MakeTIME(0,0,0);

  scanf("%d", &N);

  for (i=0;i<N;i++) {
    printf("[%d]\n",i+1);
    solve();
  }

  TulisTIME(FirstTime);
  printf("\n");
  TulisTIME(LastTime);
  printf("\n");

  return 0;
}

void solve(){
  // KAMUS
  TIME T1, T2;

  // ALGORITMA
  BacaTIME(&T1);
  BacaTIME(&T2);
  if (TEQ(T1,T2))
    printf("0\n");
  else if (TLT(T1,T2))
    printf("%d\n",Durasi(T1,T2));
  else
    printf("%d\n",Durasi(T2,T1));  

  if (TLT(T1,T2)) {
    if (TLT(T1,FirstTime))
      FirstTime = T1;
    if (TGT(T2,LastTime))
      LastTime = T2;
  }
  else {
    if (TLT(T2,FirstTime))
      FirstTime = T2;
    if (TGT(T1,LastTime))
      LastTime = T1;
  }
}