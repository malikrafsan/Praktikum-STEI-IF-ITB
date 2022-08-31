#include "prioqueue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq) {
  IDX_HEAD(*pq) = IDX_UNDEF;
  IDX_TAIL(*pq) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmpty(PrioQueue pq) {
  return (IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF);
}
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFull(PrioQueue pq) {
  return (IDX_HEAD(pq) == 0) && (IDX_TAIL(pq) == (CAPACITY-1));
}
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int length(PrioQueue pq) {
  if (isEmpty(pq))
    return 0;
  else
    return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val) {
  if (isEmpty(*pq)) {
    IDX_HEAD(*pq) = 0;
    IDX_TAIL(*pq) = 0;
    TAIL(*pq) = val;
  }
  else {
    if (IDX_TAIL(*pq) == (CAPACITY-1)) {
      for (int i=IDX_HEAD(*pq);i<=IDX_TAIL(*pq);i++) {
        (*pq).buffer[i-IDX_HEAD(*pq)] = (*pq).buffer[i];
      }
      IDX_TAIL(*pq) -= IDX_HEAD(*pq);
      IDX_HEAD(*pq) = 0;
    }

    boolean ketemu = false;
    for (int i=IDX_HEAD(*pq);i<=IDX_TAIL(*pq);i++) {
      if ((*pq).buffer[i].score < val.score) {
        for (int j=IDX_TAIL(*pq);j>=i;j--) {
          (*pq).buffer[j+1] = (*pq).buffer[j];
        }
        (*pq).buffer[i] = val;
        ketemu = true;
      }
    }
    IDX_TAIL(*pq)++;

    if (!ketemu) {
      TAIL(*pq) = val;
    }
  }
}
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(PrioQueue * pq, ElType *val) {
  // printf("0 ");
  // printf("IDX_HEAD: %d\n", IDX_HEAD(*pq));
  // printf("HEAD: %d", HEAD(*pq).id);
  *val = HEAD(*pq);
  // printf("1 ");

  if (length(*pq) == 1) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
  } else {
    IDX_HEAD(*pq)++;
  }
  // printf("2 \n");
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */
