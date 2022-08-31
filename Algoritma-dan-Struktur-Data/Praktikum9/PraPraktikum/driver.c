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

  printf("=============================\n");

  return 0;
}