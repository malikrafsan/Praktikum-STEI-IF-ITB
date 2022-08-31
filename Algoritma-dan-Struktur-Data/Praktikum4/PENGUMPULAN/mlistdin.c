#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main() {
  int op,num,Q,i,capacity;
  ListDin L;

  scanf("%d", &capacity);
  CreateListDin(&L,capacity);
  // printf("CheckPoint1\n");
  readList(&L);
  // printf("CheckPoint2\n");
  
  // printf("CheckPoint3\n");
  scanf("%d", &Q);
  for(i=0;i<Q;i++) {
    // printf("putaran ke-%d",i);
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &num);
      if (isFull(L))
        printf("list sudah penuh\n");
      else {
        insertLast(&L, num);
        printf("%d ", CAPACITY(L));
        displayList(L);
        printf("\n");
      }
    }
    else if (op == 2) {
      scanf("%d", &num);
      growList(&L, num);
      printf("%d ", CAPACITY(L));
      displayList(L);
      printf("\n");
    }
    else if (op == 3) {
      scanf("%d", &num);
      if (length(L) < num)
        printf("list terlalu kecil\n");
      else {
        shrinkList(&L,num);
        printf("%d ", CAPACITY(L));
        displayList(L);
        printf("\n");
      }
    }
    else if (op == 4) {
      compactList(&L);
      printf("%d ", CAPACITY(L));
      displayList(L);
      printf("\n");
    }
  }

  return 0;
}