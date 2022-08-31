#include <stdio.h>
#include "list_linked.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
  return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
  while(idx--) {
    FIRST(l) = NEXT(l); 
  }
  return INFO(l);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val) {
  while (idx--) {
    FIRST(*l) = NEXT(*l);
  }
  INFO(*l) = val; 
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val) {
  int res, count=0;

  while (NEXT(l) != NULL && INFO(l) != val) {
    FIRST(l) = NEXT(l);
    count++;
  }
  if (INFO(l) == val)
    res = count;
  else
    res = IDX_UNDEF;

  return res;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
  Node add;
  INFO(&add) = val;
  NEXT(&add) = FIRST(*l);

  FIRST(*l) = &add;
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void deleteLast(List *l, ElType *val){
    Address P = FIRST(*l);
    Address loc = NULL;
    while (NEXT(P) != NULL){
        loc = P;
        P = NEXT(P);
    }
    if (loc == NULL){
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(P);
    free(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    if (idx == 0) deleteFirst(l, val);
    else {
        int i = 0;
        Address loc = FIRST(*l);
        while (i < (idx-1)){
            i++;
            loc = NEXT(loc);
        }
        Address P = NEXT(loc);
        *val = INFO(P);
        NEXT(loc) = NEXT(P);
        free(P);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    if (isEmpty(l)) 
      printf("[]");
    else {
        Address P = FIRST(l);
        printf("[%d", INFO(P));
        while (NEXT(P) != NULL){
            P = NEXT(P);
            printf(",%d", INFO(P));
        }
        printf("]");
    }
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    if (isEmpty(l)) return 0;
    else {
        Address P = FIRST(l);
        int i=1;
        while (NEXT(P) != NULL){
            P = NEXT(P);
            i++;
        }
        return i;
    }
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address P = FIRST(l1);
    while (P != NULL){
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }

    P = FIRST(l2);
    while (P != NULL){
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }

    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */