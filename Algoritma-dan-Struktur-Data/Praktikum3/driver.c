#include "listpos.h"
#include <stdio.h>

int main() {
  ListPos L;
  CreateListPos(&L);
  readList(&L);

  displayList(L);
  printf("LENGTH: %d\n", length(L));

  return 0;
}