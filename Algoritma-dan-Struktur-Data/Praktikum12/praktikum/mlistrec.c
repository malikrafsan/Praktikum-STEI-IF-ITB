#include "listrec.h"

int main() {
  // List l;

  // if (isEmpty(l)) {
  //   printf("List is empty\n");
  // } else {
  //   printf("List is not empty\n");
  // }
  
  // l = konso(l,1);
  // if (isOneElmt(l)) {
  //   printf("List has one element\n");
  // } else {
  //   printf("List has more than one element\n");
  // }
  // displayList(l);
  // l = konso(l,2);
  // l = konso(l,3);
  // displayList(l);

  // printf("===\n");
  // l = konsb(l,4);
  // displayList(l);

  // printf("===\n");
  // List l1 = NULL;
  // l1 = konsb(l1,5);
  // displayList(l1);

  // printf("===\n");
  // List linverse = inverseList(l);
  // displayList(linverse);

  // printf("max: %d\n", maxList(linverse));
  // printf("min: %d\n", minList(linverse));
  // printf("sum: %d\n", sumList(linverse));
  // printf("avg: %.2f\n", averageList(linverse));

  // linverse = konso(linverse, -1);
  // linverse = konsb(linverse, -5);
  // linverse = konsb(linverse, -2);
  // linverse = konso(linverse, 5);
  // linverse = konsb(linverse, 9);
  // linverse = konsb(linverse, -3);

  // displayList(linverse);
  // List Pos, Neg;
  // Pos = Neg = NULL;
  // splitPosNeg(linverse, &Pos, &Neg);
  // printf("===\n");
  // displayList(Pos);
  // printf("===\n");
  // displayList(Neg);

  // List lminX, lmaxX;
  // lminX = lmaxX = NULL;
  // splitOnX(linverse, 3, &lminX, &lmaxX);
  // printf("===\n");
  // displayList(lminX);
  // printf("===\n");
  // displayList(lmaxX);

  // printf("===\n");
  // displayList(listBeforeX(linverse, -5));
  // printf("===\n");
  // printf("ORIGINAL LIST: \n");
  // displayList(linverse);
  // printf("===\n");
  // displayList(takeEvenIndex(linverse));
  // printf("===\n");
  // displayList(takeOddIndex(linverse));
  // printf("===\n");

  List la, lb;
  la = lb = NULL;

  // la = konso(la,7);
  // la = konso(la,6);
  // la = konso(la,5);
  // la = konso(la,3);

  // lb = konso(lb,6);
  // lb = konso(lb,5);
  // lb = konso(lb,4);
  // lb = konso(lb,4);

  la = konso(la, 3);
  la = konso(la, 2);
  la = konso(la, 1);

  lb = konso(lb, 4);
  lb = konso(lb, 3);
  lb = konso(lb, 2);
  lb = konso(lb, 1);

  displayList(la);
  displayList(lb);

  if (compareList(la, lb) == 0) {
    printf("List la and lb are equal\n");
  } else {
    if (compareList(la, lb) < 0) {
      printf("List la is smaller than lb\n");
    } else {
      printf("List la is larger than lb\n");
    }
  }

  return 0;
}