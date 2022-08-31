#include <stdio.h>
#include "list_linked.h"

void manipulate(List * l, ElType input, int N) {
  int i;
  Address walker, prevWalker;
  ElType temp;

  // printf("here\n");
  i=0;
  walker = FIRST(*l);
  prevWalker = NULL;
  while (i<N && INFO(FIRST(walker)) != input) {
    prevWalker = walker;
    FIRST(walker) = NEXT(walker);
    i++;
  }
  if (i==N) {
    deleteLast(l, &temp);
    printf("miss ");
  } else {
    deleteAt(l, i, &temp);
    printf("hit ");
  }
  insertFirst(l, input);
  displayList(*l);
  printf("\n");
}

int main() {
  int N, opsNum, i;
  ElType input;
  List l;

  scanf("%d", &N);
  CreateList(&l);
  for (i=N;i>0;i--) {
    insertFirst(&l, i);
  }
  scanf("%d", &opsNum);

  // printf("(%d,%d)", N, opsNum);
  for (i=0;i<opsNum;i++) {
    scanf("%d", &input);
    manipulate(&l, input, N);
    // printf("=\n");
  }

  return 0;
}