#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "tokenmachine.h"

void displayToken(Token input) {
  printf("<'%c',%d>",input.tkn,input.val);
}

int main() {
  startToken();

  while (!endToken) {
    displayToken(currentToken);
    printf("\n");
    advToken();
  }
  return 0;
}