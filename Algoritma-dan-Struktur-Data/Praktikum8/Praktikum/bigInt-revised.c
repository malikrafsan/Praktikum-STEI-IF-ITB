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

int main() {
  Stack S1, S2;
  long long numS1=0, numS2=0;

  CreateStack(&S1);
  CreateStack(&S2);
  
  char temp;
  // // int temp1;
  // while (true) {
  //   scanf("%c", &temp);
  //   // printf("%c\n", temp);
  //   if (temp == '#')
  //     break;
  //   else {
  //     // temp1 = temp;
  //     // printf("%d\n", temp-48);
  //     push(&S1, temp-48);
  //   }
  // }
  // printStack(S1);

  scanf("%c", &temp);
  while (temp != '#') {
    push(&S1, temp-48);
    scanf("%c", &temp); 
  }
  printStack(S1);

  printf(">>>>>>>>>>>>>>>>>\n");
  
  // scanf("%c", &temp);
  temp = '0';
  while (temp != '#') {
    scanf("%c", &temp); 
    push(&S2, temp-48);
  }
  printStack(S2);

  // while (true) {
  //   scanf("%c", &temp);
  //   // printf("%c\n", temp);
  //   if (temp == '#') {
  //     printf("\n");
  //     printStack(S2);      
  //     break;
  //   }
  //   else {
  //     // temp1 = temp;
  //     printf("%d", temp-48);
  //     push(&S2, temp-48);
  //   }
  // }

  printf("<<<<<<<<<<<<\n");

  int dump, count;
  long long plus;
  count = 0;
  while (!isEmpty(S1)) {
    pop(&S1, &dump);
    printf("%d- %d\n", count, dump);
    plus = dump * pow(10,count);
    numS1 += plus;
    count++;
  }
  printf("==================\n");
  count = 0;
  while (!isEmpty(S2)) {
    pop(&S2, &dump);
    printf("%d- %d\n", count, dump);
    plus = dump * pow(10,count);
    numS2 += plus;
    count++;
  }

  printf("%lld : %lld\n", numS1, numS2);

  // do {
  //   scanf("%c",&temp);
  // } while (temp != '#');


  return 0;
}