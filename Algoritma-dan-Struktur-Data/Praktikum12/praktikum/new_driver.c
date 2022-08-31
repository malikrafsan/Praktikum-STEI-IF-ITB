#include "listrec.h"

int main() {
  List la, lb, lc, ld;

  la = lb = lc = ld = NULL;
  la = konso(la, 3);
  la = konso(la, -2);
  lb = konso(lb,3);
  lb = konso(lb, -2);
  

  printf("%d\n", isAllExist(la, lb));
  lb = konso(lb, 1);
  la = konso(lb,-1);
  printf("%d\n", isAllExist(la, lb));

  return 0;
}