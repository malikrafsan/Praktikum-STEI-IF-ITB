#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  BinTree b, left1, right1, left2, right2, left3;

  if (isTreeEmpty(b))
    printf("kosong\n");
  else
    printf("tidak kosong\n");

  CreateTree(9,NULL,NULL,&left3);
  CreateTree(11,NULL,left3,&left2);
  CreateTree(99,left2,NULL,&left1);
  CreateTree(2,NULL,NULL,&right2);
  CreateTree(-1,NULL,right2,&right1);
  CreateTree(5,left1,right1,&b);

  if (isOneElmt(b))
    printf("hanya satu\n");
  else
    printf("bukan satu\n");

  printPreorder(b);printf("\n");
  printInorder(b);printf("\n");
  printPostorder(b);printf("\n");
  printTree(b,2);printf("\n");

  return 0;
}