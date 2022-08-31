#include <stdio.h>
#include "prioqueue.h"

void displayElType(ElType el) {
  printf("<%d,%d,%d,%d>", el.id,el.tArrival,el.score,el.dService);
}

void displayQueue(PrioQueue q) {
  ElType dump;
  
  printf("[");
  int len = length(q);

  if (len > 0) {
    // printf("%d",HEAD(q));
    displayElType(HEAD(q));
    dequeue(&q,&dump);
    for (int i = 1;i<len;i++) {
      printf(",");
      displayElType(HEAD(q));
      dequeue(&q,&dump);
    }
  }
  printf("]");
}

int main() {
  int N;
  int id, tArr, scr, dSrv;
  ElType mhs, mhsNow;
  PrioQueue pq;
  int time = 0, next;
  boolean empty = true;

  scanf("%d", &N);

  if (N == 0) {
    printf("Tidak ada layanan\n");
    return 0;
  }

  scanf("%d %d %d %d", &tArr, &id, &scr, &dSrv);
  mhs.id = id;
  mhs.tArrival = tArr;
  mhs.score = scr;
  mhs.dService = dSrv;

  while (time < tArr) {
    time++;
  }
  next = time + mhs.dService;
  printf("nexttt: %d\n", next);
  printf("%d %d 0\n", mhs.tArrival, mhs.id);

  for (int i = 0; i < (N-1); i++) {
    scanf("%d %d %d %d", &tArr, &id, &scr, &dSrv);
    mhs.id = id;
    mhs.tArrival = tArr;
    mhs.score = scr;
    mhs.dService = dSrv;

    while (time < mhs.tArrival) {
      time++;
      // printf("time: %d\n", time);

      if (time == next) {
        if (!isEmpty(pq)) {
          dequeue(&pq,&mhsNow);
          next += mhsNow.dService;
          printf("oyyy next: %d\n", next);
          printf("%d %d %d\n", time, mhsNow.id, time - mhsNow.tArrival);
        }
      }
      printf("time: %d\n", time);
      displayQueue(pq);
      printf("\n");
    }
    enqueue(&pq, mhs);
  }
  printf("=============\n");
  while (time < next) {
    printf("next: %d\n time: %d\n", next, time);
    time++;
    // printf("time: %d\n", time);
  }
  while (!isEmpty(pq)) {
    dequeue(&pq,&mhsNow);
    next += mhsNow.dService;
    printf("next: %d\n", next);
    printf("%d %d %d\n", time, mhsNow.id, time - mhsNow.tArrival);
    while (time < next) {
      time++;
      // printf("time: %d\n", time);
    }
  }
  displayQueue(pq);

// Baris kedua sampai N+1: terdiri atas 4 buah bilangan, misalnya T, I, M, D yang masing-masing merepresentasikan: T: waktu kedatangan ke kantin, I: id mahasiswa, M: nilai Daspro, dan D: durasi layanan/lama persiapan makanan untuk mahasiswa I.

  return 0;
}