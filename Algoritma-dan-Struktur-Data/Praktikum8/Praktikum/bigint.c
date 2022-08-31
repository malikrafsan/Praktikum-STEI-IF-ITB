#include <stdio.h>
#include "boolean.h"
#include "stack.h"
#include <math.h>

void printStack(Stack S) {
  int dump;
  while (!isEmpty(S)) {
    pop(&S, &dump);
    printf("%d", dump);
  }
  printf("\n");
}

void defineStack(Stack *S, const char* str) {
  int i = 0;
  while (str[i] != '#') {
    push(S, str[i]-48);
    i++;
  }
}

Stack plusStack(Stack S1, Stack S2) {
  Stack res;
  CreateStack(&res);

  int dump1, dump2,carry,plus;
  carry = 0;
  while (!isEmpty(S1) && !isEmpty(S2)) {
    pop(&S1, &dump1);
    pop(&S2, &dump2);
    plus = (dump1+dump2+carry);
    push(&res, plus%10);
    // printf("%d", plus);
    if (plus >= 10) {
      carry = 1;
    } else {
      carry = 0;
    }
  }
  while (!isEmpty(S1)){
    pop(&S1,&dump1);
    plus = (dump1+carry);
    push(&res, plus%10);
    if (plus >= 10){
      carry = 1;
    } else {
      carry = 0;
    }
  }
  while (!isEmpty(S2)){
    pop(&S2,&dump2);
    plus = (dump2+carry);
    push(&res, plus%10);
    if (plus >= 10){
      carry = 1;
    } else {
      carry = 0;
    }
  }
  if (carry != 0){
    push(&res, carry);
  }
  // printf("\n");
  return res;
}

int main() {
  Stack S1, S2, S3;

  CreateStack(&S1);
  CreateStack(&S2);
  CreateStack(&S3);

  char str1[150];
  fgets(str1, 150, stdin);
  // printf("string: %s\n", str1);
  defineStack(&S1, str1);
  
  char str2[150];
  fgets(str2, 150, stdin);
  // printf("string: %s\n", str2);
  defineStack(&S2, str2);

  // printf("Stack\n");
  // printStack(S1);
  // printStack(S2);

  S3 = plusStack(S1, S2);
  // printf("Res Stack\n");
  printStack(S3);

  return 0;
}