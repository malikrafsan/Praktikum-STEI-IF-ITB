#include "listrec.h"

int main() {
  List l;

  if (isEmpty(l)) {
    printf("List is empty\n");
  } else {
    printf("List is not empty\n");
  }
  
  l = konso(l,1);
  if (isOneElmt(l)) {
    printf("List has one element\n");
  } else {
    printf("List has more than one element\n");
  }
  displayList(l);
  l = konso(l,2);
  l = konso(l,3);
  displayList(l);

  printf("===\n");
  l = konsb(l,4);
  displayList(l);

  List l1 = NULL;
  l1 = konsb(l1,5);
  displayList(l1);

  return 0;
}