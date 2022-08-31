#include "stdio.h"
#include "boolean.h"
#include "queue.h"

float avgElmt (Queue Q) {
  float sum = 0.0;
  int len = length(Q);
  int dump;

  for (int i = 0; i <len; i++) {
    sum += HEAD(Q);
    dequeue(&Q,&dump);
    // printf("%d\n",dump);
  }
  return (sum / len);
}
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */

int main() {
  int choice, elmt;
  Queue Q;
  CreateQueue(&Q);

  while (1) {
    scanf("%d", &choice);
    if (choice == 1) {
      // printf("Here\n");
      scanf("%d", &elmt);
      if (isFull(Q))
        printf("Queue penuh\n");
      else
        enqueue(&Q,elmt);
    } 
    else if (choice == 2) {
      // printf("Here2\n");
      if (isEmpty(Q))
        printf("Queue kosong\n");
      else
        dequeue(&Q, &elmt);
    } 
    else {
      // printf("Here3\n");
      int len = length(Q);
      printf("%d\n",len);
      if (len == 0) {
        printf("Tidak bisa dihitung\n");
      } else {
        printf("%.2f\n",avgElmt(Q));
      }
      break;
    }
  }

  return 0;
}