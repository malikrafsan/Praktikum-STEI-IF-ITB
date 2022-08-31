#include <stdio.h>
#include "list_linked.h"

int main() {
  List l, l1;
  int tempVal;

  // printf("size long: %llu\n", sizeof(long));

  CreateList(&l);
  CreateList(&l1);
  isEmpty(l) ? printf("kosong\n") : printf("tidak kosong\n");
  insertFirst(&l, 5);
  printf("here\n");
  displayList(l);printf("\n");
  insertLast(&l, 2);
  displayList(l);printf("\n");
  setElmt(&l, 1, 9);
  displayList(l);printf("\n");
  insertAt(&l, 10, 1);
  displayList(l);printf("\n");
  printf("length: %d\n",length(l));
  printf("==============\n");

  insertFirst(&l1,7);
  insertAt(&l1, 1, 1);
  displayList(l1);printf("\n");
  List gabung = concat(l, l1);
  displayList(gabung);printf("\n");
  displayList(l1);printf("\n");
  displayList(l);printf("\n");

  printf("==============\n");
  deleteAt(&gabung, 0, &tempVal);
  displayList(gabung);printf("\n");
  deleteAt(&gabung, 3, &tempVal);
  displayList(gabung);printf("\n");
  deleteAt(&gabung, 1, &tempVal);
  displayList(gabung);printf("\n");
  deleteLast(&gabung, &tempVal);
  displayList(gabung);printf("\n");
  deleteFirst(&gabung,&tempVal);
  displayList(gabung);printf("\n");
  printf("length: %d\n",length(gabung));
  printf("end\n");

  printf("============================\n");
  // insertFirst(&l, 5);
  // insertFirst(&l, -8);
  // insertFirst(&l, 2);
  delAll(&l);
  // CreateList(&l);
  insertFirst(&l, 10);

  printf("reset: ");
  displayList(l);printf("\n");

  if (fSearch(l, FIRST(l)))
    printf("address ketemu\n");
  else
    printf("ada yang salah sama fSearch\n");
  
  if (fSearch(l, searchPrec(l, 7)))
    printf("ada angka 7 di l\n");
  else
    printf("gaada angka 7 di l\n");
  
  printf("max: %d\n", max(l));
  printf("max lagi: %d\n", INFO(adrMax(l)));
  printf("min: %d\n", min(l));
  printf("min lagi: %d\n", INFO(adrMin(l)));

  printf("average: %f\n", average(l));
  printf("reversed: ");
  inverseList(&l);
  displayList(l); printf("\n");
  List invertedAgain = fInverseList(l);
  displayList(invertedAgain);
  printf("\n");

  // printf("here\n");
  List newlist;
  copyList(&invertedAgain, &newlist);
  displayList(newlist);printf("\n");

  // printf("here1\n");
  List newcopy = fCopyList(newlist);
  displayList(newcopy);printf("\n");

  // printf("here2\n");
  List newcopyagain;
  cpAllocList(newcopy, &newcopyagain);
  displayList(newcopyagain); printf("\n");

  List split1, split2;
  splitList(&split1, &split2, newcopyagain);
  displayList(split1); printf("\n");
  displayList(split2); printf("\n");

  return 0;
}