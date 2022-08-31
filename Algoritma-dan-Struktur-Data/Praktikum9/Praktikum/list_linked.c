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

  walker = *l;
  new = newNode(val);
  if (FIRST(*l) == NULL)
    FIRST(*l) = new;
  else {
    while(NEXT(walker) != NULL) {
      FIRST(walker) = NEXT(walker);
    }
    NEXT(walker) = new;
  }
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
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
  if (idx == 0) 
    deleteFirst(l, val);
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

// KAMUS
  boolean found;

// ALGORITMA
  while (FIRST(L) != NULL && FIRST(L) != P) {
    FIRST(L) = NEXT(L);
  }
  return (FIRST(L) == P);
}

Address searchPrec(List L, ElType X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

// KAMUS
  Address prev;

// ALGORITMA
  prev = NULL;
  while (FIRST(L) != NULL && INFO(FIRST(L)) != X) {
    prev = FIRST(L);
    FIRST(L) = NEXT(L);
  }
  if (FIRST(L) == NULL)
    prev = NULL;
  
  return prev;
}


/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List l) {
/* Mengirimkan nilai info(P) yang maksimum */

// KAMUS
  ElType maxElmt;

// ALGORITMA
  maxElmt = INFO(FIRST(l));
  while (FIRST(l) != NULL) {
    if (INFO(FIRST(l)) > maxElmt) {
      maxElmt = INFO(FIRST(l));
    }
    FIRST(l) = NEXT(l);
  }
  return maxElmt;
}

Address adrMax(List l) {
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */

// KAMUS
  ElType maxElmt;
  Address adr;

// ALGORITMA
  maxElmt = INFO(FIRST(l));
  adr = FIRST(l);
  while (FIRST(l) != NULL) {
    if (INFO(FIRST(l)) > maxElmt) {
      maxElmt = INFO(FIRST(l));
      adr = FIRST(l);
    }
    FIRST(l) = NEXT(l);
  }
  return adr;
}

ElType min(List l) {
/* Mengirimkan nilai info(P) yang minimum */

// KAMUS
  ElType minElmt;

// ALGORITMA
  minElmt = INFO(FIRST(l));
  while (FIRST(l) != NULL) {
    if (INFO(FIRST(l)) < minElmt) {
      minElmt = INFO(FIRST(l));
    }
    FIRST(l) = NEXT(l);
  }
  return minElmt;
}

Address adrMin(List l) {
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
  
// KAMUS
  ElType minElmt;
  Address adr;

// ALGORITMA
  minElmt = INFO(FIRST(l));
  adr = FIRST(l);
  while (FIRST(l) != NULL) {
    if (INFO(FIRST(l)) < minElmt) {
      minElmt = INFO(FIRST(l));
      adr = FIRST(l);
    }
    FIRST(l) = NEXT(l);
  }
  return adr;
}

float average(List l) {
/* Mengirimkan nilai rata-rata info(P) */

// KAMUS
  float sum;
  int count;

// ALGORITMA
  sum = 0.;
  count = 0;
  while (FIRST(l) != NULL) {
    sum += INFO(FIRST(l));
    FIRST(l) = NEXT(l);
    count++;
  }
  return (sum / count);
}


/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

// KAMUS
  List l3, walker;
  Address new;

// ALGORITMA
  CreateList(&l3);
  walker = l1;

  while (FIRST(walker) != NULL) {
    insertLast(&l3, INFO(FIRST(walker)));
    FIRST(walker) = NEXT(walker);
  }
  walker = l2;
  while (FIRST(walker) != NULL) {
    // printf("tes\n");
    insertLast(&l3, INFO(FIRST(walker)));
    FIRST(walker) = NEXT(walker);
  }
  return l3;
}

void delAll(List *l) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */

// KAMUS
  Address temp, walker;

// ALGORITMA
  walker = FIRST(*l);
  while (FIRST(walker) != NULL) {
    temp = FIRST(walker);
    FIRST(walker) = NEXT(walker);
    free(temp);
  }
  FIRST(*l) = NULL;
}

void inverseList(List *l) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

// KAMUS
  Address walker1, walker2, walker3;

// ALGORITMA
  walker1 = FIRST(*l);
  walker2 = NULL;

  if (walker1 != NULL) {
    do {
      walker3 = walker2;
      walker2 = walker1;
      walker1 = NEXT(walker1);
      NEXT(walker2) = walker3;
    } while (walker1 != NULL);
    // NEXT(walker2) = walker3;
    FIRST(*l) = walker2;
  }
}

List fInverseList(List l) {
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

// KAMUS
  boolean alwaysSuccess;
  Address new;
  List lout;

// ALGORITMA
  alwaysSuccess = true;
  CreateList(&lout);

  while (alwaysSuccess && FIRST(l) != NULL) {
    new = newNode(INFO(FIRST(l)));
    if (new == NULL) {
      delAll(&lout);
      alwaysSuccess = false;
    } else {
      // insertFirst(&lout, new);
      NEXT(new) = FIRST(lout);
      FIRST(lout) = new;
    }
    FIRST(l) = NEXT(l);
  }
  return lout;
}


void copyList(List *l1, List *l2) {
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

// ALGORITMA
  // printf("1");
  FIRST(*l2) = FIRST(*l1);
  // printf("1\n");
}


List fCopyList(List l) {
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

// KAMUS
  boolean alwaysSuccess;
  Address new;
  List lout, walker;
  int counter=0;

// ALGORITMA
  alwaysSuccess = true;
  CreateList(&lout);

  while (alwaysSuccess && FIRST(l) != NULL) {
    new = newNode(INFO(FIRST(l)));
    if (new == NULL) {
      delAll(&l);
      alwaysSuccess = false;
      // printf("here: %d\n", counter);
    } else {
      // insertLast(&l, new);
      // printf("%d ", counter);
      walker = lout;
      if (FIRST(lout) == NULL)
        FIRST(lout) = new;
      else {
        while (NEXT(walker) != NULL) {
          FIRST(walker) = NEXT(walker);
        }
        NEXT(walker) = new;
      }
    }
    FIRST(l) = NEXT(l);
    counter++;
  }
  return lout;
}

void cpAllocList(List lIn, List *lOut) {
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil, maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */

// KAMUS
  boolean alwaysSuccess;
  Address new;
  List walker;
  int counter=0;

// ALGORITMA
  alwaysSuccess = true;
  // displayList(lIn);printf("\n");
  CreateList(lOut);

  // printf("here\n");
  while (alwaysSuccess && FIRST(lIn) != NULL) {
    // printf("tes\n");
    new = newNode(INFO(FIRST(lIn)));
    if (new == NULL) {
      delAll(lOut);
      *lOut = NULL; 
      alwaysSuccess = false;
    } else {
      // insertLast(lOut, new);
      // printf("tes1\n");
      walker = *lOut;
      if (FIRST(*lOut) == NULL)
        FIRST(*lOut) = new;
      else {
        while(NEXT(walker) != NULL) {
          FIRST(walker) = NEXT(walker);
        }
        NEXT(walker) = new;
      }
      // printf("tes2\n");
    }
    FIRST(lIn) = NEXT(lIn);
    counter++;
  }
}


void splitList(List *l1, List *l2, List l) {
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */

// KAMUS
  int l1Len, i;

// ALGORITMA
  l1Len = length(l) / 2;
  CreateList(l1);
  CreateList(l2);

  for (i=0; i< l1Len; i++) {
    insertLast(l1, INFO(FIRST(l)));
    FIRST(l) = NEXT(l);
  }
  while (FIRST(l) != NULL) {
    insertLast(l2, INFO(FIRST(l)));
    FIRST(l) = NEXT(l);
  }
}
