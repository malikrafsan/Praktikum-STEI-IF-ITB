#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"
#include "boolean.h"

int main() {
  ListDin L;
  CreateListDin(&L,5);
  printf("Length: %d\n", length(L));
  printf("Last Idx: %d\n", getLastIdx(L));
  if (isIdxValid())

  return 0;
}