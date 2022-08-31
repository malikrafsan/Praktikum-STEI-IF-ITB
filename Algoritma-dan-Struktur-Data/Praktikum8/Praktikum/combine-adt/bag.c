#include "bag.h"
#include <string.h>

void CreateBag(Bag *b) {
  CreateStack(&(b->s));
  b->capEff = 0;
}

char jenis[20];
