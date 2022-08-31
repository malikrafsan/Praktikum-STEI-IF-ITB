#include "listrec.h"

int main() {
  List la, lb, lc, ld;
  la = lb = lc = ld = NULL;

  la = konso(la, 3);
  la = konso(la, -2);
  la = konso(la, 1);

  lb = konso(lb, -4);
  lb = konso(lb, 3);
  lb = konso(lb, -2);
  lb = konso(lb, 8);

  lc = konso(lc,-1);

  // printf("max: %d\n", maxList(la));
  // printf("max: %d\n", maxList(lb));
  // printf("max: %d\n", maxList(lc));

  // printf("\n\n");

  // printf("min: %d\n", minList(la));
  // printf("min: %d\n", minList(lb));
  // printf("min: %d\n", minList(lc));

  // printf("\n\n");

  // printf("sum: %d\n", sumList(la));
  // printf("sum: %d\n", sumList(lb));
  // printf("sum: %d\n", sumList(lc));

  // printf("\n\n");

  // printf("average: %f\n", averageList(la));
  // printf("average: %f\n", averageList(lb));
  // printf("average: %f\n", averageList(lc));

  // printf("\n\n");

  // printf("====\n");
  // displayList(la);
  // printf("\n");
  // displayList(inverseList(la));
  // printf("====\n");

  // printf("====\n");
  // displayList(lb);
  // printf("\n");
  // displayList(inverseList(lb));
  // printf("====\n");

  // printf("====\n");
  // displayList(lc);
  // printf("\n");
  // displayList(inverseList(lc));
  // printf("====\n");

  // printf("====\n");
  // displayList(ld);
  // printf("\n");
  // displayList(inverseList(ld));
  // printf("====\n");

  // displayList(la);
  // printf("\n");
  // displayList(lb);
  // printf("\n");
  // displayList(lc);
  // printf("\n");

  // List l1, l2;
  // l1 = l2 = NULL;
  // printf("====\n");
  // splitPosNeg(la, &l1, &l2);
  // displayList(l1);
  // printf("\n");
  // displayList(l2);
  // printf("====\n");

  // printf("====\n");
  // splitPosNeg(lb, &l1, &l2);
  // displayList(l1);
  // printf("\n");
  // displayList(l2);
  // printf("====\n");

  // printf("====\n");
  // splitPosNeg(lc, &l1, &l2);
  // displayList(l1);
  // printf("\n");
  // displayList(l2);
  // printf("====\n");

  // printf("====\n");
  // splitPosNeg(ld, &l1, &l2);
  // displayList(l1);
  // printf("\n");
  // displayList(l2);
  // printf("====\n");  

  displayList(la);
  printf("\n");
  displayList(lb);
  printf("\n");
  displayList(lc);
  printf("\n");

  List l1, l2;
  l1 = l2 = NULL;
  splitOnX(lb, 8, &l1, &l2);
  printf("====\n");
  displayList(l1);
  printf("===\n");
  displayList(l2);
  printf("====\n");

  List lx, lz;
  lx = lz = NULL;
  lx = konso(lx, 1);
  lx = konso(lx, 2);
  lx = konso(lx, 3);

  lz = konso(lz, -1);
  lz = konso(lz, 2);
  lz = konso(lz, 3);
  lz = konso(lz, 1);

  if (isAllExist(lx,lz)) {
    printf("All Exist\n");
  } else {
    printf("Not All Exist\n");
  }
  lz = konso(lz, -4);
  lz = konsb(lz, -1);
  if (isAllExist(lx,lz)) {
    printf("All Exist\n");
  } else {
    printf("Not All Exist\n");
  }
  lz = konso(lz, 7);
  displayList(lx);
  printf("><\n");
  displayList(lz);
  List ly = NULL;
  ly = konso(ly, 1);
  ly = konso(ly, 2);
  ly = konso(ly, 3);
  ly = konsb(ly, 4);
  
  lx = konsb(lx,5);
  List l11, l12;
  l11 = l12 = NULL;

  // printf("res: %d\n", compareList(lx, lx));
  // printf("res: %d\n",compareList(lx, lz));
  // printf("res: %d\n",compareList(lz, lx));
  // printf("res: %d\n", compareList(ly, ly));
  // printf("res: %d\n",compareList(lx, ly));
  // printf("res: %d\n",compareList(ly, lx));
  // printf("res: %d\n",compareList(l12, l11));

// [-1, 2] < [1,2,3]
// [1] = [2]
// [1,2] > [9]
// [1,2,3] > [1,2,1]

  List ln1, ln2;
  ln1 = ln2 = NULL;

  ln1 = konso(ln1, 2);
  ln1 = konso(ln1, -1);
  ln2 = konso(ln2,3);
  ln2 = konso(ln2,2);
  ln2 = konso(ln2,1);

  printf("res: %d\n", compareList(ln1, ln2));

  ln1 = ln2 = NULL;
  ln1 = konso(ln1, 1);
  ln2 = konso(ln2, 1);
  printf("res: %d\n", compareList(ln1, ln2));

  ln1 = ln2 = NULL;
  ln1 = konso(ln1, 2);
  ln1 = konso(ln1, 1);
  ln2 = konso(ln2, 9);
  printf("res: %d\n", compareList(ln1, ln2));

  ln1 = ln2 = NULL;
  ln1 = konso(ln1, 1);
  ln2 = konso(ln2, 1);
  printf("res: %d\n", compareList(ln1, ln2));

  return 0;
}