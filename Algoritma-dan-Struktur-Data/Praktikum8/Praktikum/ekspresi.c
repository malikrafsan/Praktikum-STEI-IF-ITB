#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "tokenmachine.h"
#include "stack.h"
#include <math.h>

int calculate(char operator, int op1, int op2) {
  int res;

  switch (operator) {
    case '+':
      printf("%d %c %d\n", op1, operator,op2);
      res = op1 + op2;
      break;
    case '-':
      printf("%d %c %d\n", op1, operator,op2);
      res = op1 - op2;      
      break;
    case '*':
      printf("%d %c %d\n", op1, operator,op2);
      res = op1 * op2;
      break;
    case '/':
      printf("%d %c %d\n", op1, operator,op2);
      res = op1 / op2;
      break;
    case '^':
      printf("%d %c %d\n", op1, operator,op2);
      res = pow(op1,op2);
      break;
  }
  return res;
}

int main() {
  Token tkn1, tkn2, tkn3;
  Stack s;
  int dump1, dump2, res;
  CreateStack(&s);

  startToken();

  if (endToken) {
    printf("Ekspresi kosong\n");
  } else {
    do {
      if (currentToken.val == -1) {
        pop(&s, &dump2);
        pop(&s, &dump1);
        res = calculate(currentToken.tkn, dump1, dump2);
        push(&s, res);
        printf("%d\n",res);
      } else {
        printf("%d\n", currentToken.val);
        push(&s, currentToken.val);
      }
      advToken();
    } while (!endToken);

    printf("Hasil=%d\n",res);
  }                                                      
  return 0;
}