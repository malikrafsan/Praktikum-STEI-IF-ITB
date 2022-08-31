#include "bintree.h"

void invertBtree(BinTree *p) {
  if (!(isTreeEmpty(*p) || isOneElmt(*p))) {
    BinTree left, right;
    left = LEFT(*p);
    LEFT(*p) = RIGHT(*p);
    RIGHT(*p) = left;
    invertBtree(&LEFT(*p));
    invertBtree(&RIGHT(*p));
  }
}