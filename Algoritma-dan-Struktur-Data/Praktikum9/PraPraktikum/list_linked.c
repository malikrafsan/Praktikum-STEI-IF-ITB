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
  List walker;

  // CreateList(&walker);
  walker = *l;
  while (idx--) {
    FIRST(walker) = NEXT(walker);
  }
  INFO(walker) = val; 
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
  Address new;

  new = newNode(val);
  NEXT(new) = FIRST(*l);
  FIRST(*l) = new;
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val) {
  Address new;
  List walker;

  // CreateList(&walker);
  walker = *l;

  // printf("tes\n");
  new = newNode(val);
  if (FIRST(*l) == NULL)
    FIRST(*l) = new;
  else {
    // printf("tes\n");
    while(NEXT(walker) != NULL) {
      // printf("tes\n");
      FIRST(walker) = NEXT(walker);
      // printf("tes\n");
    }
    // printf("tes\n");
    NEXT(walker) = new;
  }
  // printf("tes\n");
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx) {
  Address new;
  List walker;
  
  if (idx == 0) {
    insertFirst(l, val);
  } else {
    walker = *l;
    new = newNode(val);

    idx--;
    while (idx--) {
      FIRST(walker) = NEXT(walker);
    }
    // printf("tes\n");
    NEXT(new) = NEXT(walker);
    // printf("tes\n");
    NEXT(walker) = new;
    // printf("tes\n");
  }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
  List walker;

  *val = INFO(FIRST(*l));
  walker = *l;
  FIRST(*l) = NEXT(*l);
  free(FIRST(walker));
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val) {
  List walker, loc;

  walker = *l;
  loc = NULL;

  while (NEXT(walker) != NULL) {
    loc = walker;
    walker = NEXT(walker);
  }

  if (loc == NULL) {
    *l = NULL;
  } else {
    NEXT(loc) = NULL;
  }

  *val = INFO(walker);
  free(walker);

  // if (NEXT(*l) == NULL) {
  //   free(FIRST(*l));
  //   FIRST(*l) = NULL;
  // } else {
  //   while (NEXT(NEXT(walker)) != NULL) {
  //     FIRST(walker) = NEXT(walker);
  //   }
  //   *val = INFO(NEXT(walker));
  //   free(NEXT(walker));
  //   NEXT(walker) = NULL;
  // }
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

// ctr ← 0
// loc ← l
// while ctr<idx-1 do
// ctr ← ctr+1
// loc ← loc↑.next
// {ctr=idx-1}
// p ← loc↑.next
// val ← p↑.info
// loc↑.next ← p↑.next
// dealokasi(p)

    // if (NEXT(NEXT(walker)) == NULL) {
    //   free(NEXT(walker));
    //   NEXT(walker) = NULL;
    // } else {
    //   temp = NEXT(NEXT(walker));      
    // }

    // printf("tos\n");
    // temp = NEXT(NEXT(walker));
    // printf("tos\n");
    // *val = INFO(NEXT(walker));
    // printf("tos\n");
    // free(NEXT(walker));
    // printf("tos\n");
    // NEXT(walker) = temp;
    // printf("tos\n");
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
  printf("[");
  if (FIRST(l) != NULL) {
    printf("%d", getElmt(l,0));
    FIRST(l) = NEXT(l);
    while (FIRST(l) != NULL) {
      printf(",%d", getElmt(l,0));
      FIRST(l) = NEXT(l);
    }
  }
  printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l) {
  int count;

  count = 0;
  while (FIRST(l) != NULL) {
    FIRST(l) = NEXT(l);
    count++;
  }

  return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
  List l3, walker;
  Address new;

  CreateList(&l3);
  walker = l1;
  // walker1 = l1;

  // printf("tos\n");
  while (FIRST(walker) != NULL) {
    // printf("tes\n");
    // printf("inserted: %d\n",INFO(FIRST(walker)));
    insertLast(&l3, INFO(FIRST(walker)));
    FIRST(walker) = NEXT(walker);
  }
  // printf("in func: ");
  // displayList(l3);printf("\n");
  // printf("tos\n");
  walker = l2;
  while (FIRST(walker) != NULL) {
    // printf("tes\n");
    insertLast(&l3, INFO(FIRST(walker)));
    FIRST(walker) = NEXT(walker);
  }

  return l3;

  // while (NEXT(walker1) != NULL) {
  //   printf("tes\n");
  //   new = newNode(INFO(FIRST(walker1)));
  //   NEXT(walker) = new;
  //   FIRST(walker) = NEXT(walker);
  //   FIRST(walker1) = NEXT(walker1); 
  //   printf("tes\n");
  // }

  // printf("tos\n");
  // walker1 = l2;
  // while (NEXT(walker1) != NULL) {
  //   printf("tes\n");
  //   new = newNode(INFO(FIRST(walker1)));
  //   NEXT(walker) = new;
  //   FIRST(walker) = NEXT(walker);
  //   FIRST(walker1) = NEXT(walker1); 
  //   printf("tes\n");
  // }
  // printf("tos\n");

  // return l3;
}

  // FIRST(l3) = FIRST(l1);
  // FIRST(l1) = NULL;
  // walker = l3;
  // while (NEXT(walker) != NULL) {
  //   // printf("%d\n", INFO(FIRST(walker)));
  //   FIRST(walker) = NEXT(walker);
  // }
  // NEXT(walker) = FIRST(l2);
  // FIRST(l2) = NULL;

/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */