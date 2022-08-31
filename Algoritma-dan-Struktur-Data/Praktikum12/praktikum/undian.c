#include "listrec.h"

List takeFlipFlop(List l, boolean take) {
    if (isEmpty(l)) {
        return l;
    } else {
        if (take) {
            return konso(takeFlipFlop(tail(l), !take), head(l));
        } else {
            return takeFlipFlop(tail(l), !take);
        }
    }
}

List takeEvenIndex(List l) {
  return takeFlipFlop(l, false);
}
List takeOddIndex(List l) {
  return takeFlipFlop(l, true);
}

List listBeforeX(List l, ElType x) {
  if (isEmpty(l)) {
    return l;
  } else if (head(l) == x) {
    return NULL;
  } else {
    return konso(listBeforeX(tail(l), x), head(l));
  }
}

List inverseList(List l) {
  if (isEmpty(l)) {
    return l;
  } else {
    return konsb(inverseList(tail(l)), head(l));
  }
}

int main() {
  List l;
  char input;
  ElType elmt;

  l = NULL;
  scanf("%c", &input);
  while (input != 'X') {
    switch (input) {
      case 'B':
        scanf("%d", &elmt);
        l = konsb(l, elmt);
        break;
      case 'F':
        scanf("%d", &elmt);
        l = konso(l, elmt);
        break;
      case 'R':
        l = inverseList(l);
        break;
      case 'P':
        scanf("%d", &elmt);
        l = listBeforeX(l, elmt);
        break;
      case 'O':
        l = takeOddIndex(l);
        break;
      case 'E':
        l = takeEvenIndex(l);
        break;
    }
    scanf("%c", &input);
  }
  if (isEmpty(l)) {
    printf("Semua gugur\n");
  } else {
    displayList(l);
  }


  return 0;
}