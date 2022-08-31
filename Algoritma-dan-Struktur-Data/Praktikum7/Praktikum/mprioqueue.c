#include <stdio.h>
#include "prioqueue.h"

ElType CreateElType() {
  ElType mhsIn;
  int id, tArrival, score, dService;

  scanf("%d %d %d %d", &tArrival, &id, &score, &dService);
  mhsIn.id = id;
  mhsIn.tArrival = tArrival;
  mhsIn.score = score;
  mhsIn.dService = dService;

  return mhsIn;
}

int main() {
  int time = 0, output = 0, next=0, input=0;
  ElType mhsIn, mhsOut;
  PrioQueue pq;
  boolean empty = true, dumpEmpty = true;

  CreatePrioQueue(&pq);
  int N;
  scanf("%d", &N);

  if (N == 0) {
    printf("Tidak ada layanan\n");
    return 0;
  }

  mhsOut = CreateElType();
  input++;
  while (time < mhsOut.tArrival) {
    time++;
  }
  printf("%d %d 0\n", time, mhsOut.id);
  next = mhsOut.tArrival + mhsOut.dService;
  empty = false;
  output++;
  // enqueue(&pq, mhsIn);

  if (N > 1) {
    mhsIn = CreateElType();
    input++;
    while (output < N) {
      if (time == mhsIn.tArrival) {
        enqueue(&pq, mhsIn);
        if (input < N) {
          mhsIn = CreateElType();
          input++;
        }
        // printf("Here\n");
        // dumpEmpty = true;
      }
      // if (dumpEmpty) {
      //   mhsIn = CreateElType();
      //   dumpEmpty = false;
      // }
      if (time == next) {
        empty = true;
        // printf("there\n");
      }
      if (empty && (!isEmpty(pq))) {
        // printf("this\n");
        dequeue(&pq, &mhsOut);
        // printf("<%d,%d,%d,%d>\n",mhsOut.id,mhsOut.tArrival,mhsOut.score,mhsOut.dService);
        // printf("this1\n");
        next = time + mhsOut.dService;
        printf("%d %d %d\n", time, mhsOut.id, time - mhsOut.tArrival);
        empty = false;
        // printf("this2\n");
        output++;
      }
      // printf("IDX_HEAD(pq): %d\n", IDX_HEAD(pq));
      // printf("time: %d\n", time);
      time++;
    }
    // printf("output: %d\n", output);
  }

  return 0;
}