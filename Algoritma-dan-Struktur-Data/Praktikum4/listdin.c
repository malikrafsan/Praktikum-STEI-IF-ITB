#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
  CAPACITY(*l) = capacity;
  BUFFER(*l) = (ElType*)malloc(capacity * sizeof(ElType));
  NEFF(*l) = 0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocate(ListDin *l) {
  CAPACITY(*l) = 0;
  NEFF(*l) = 0;
  free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
  return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
  return (NEFF(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i) {
  return (i >= 0 && i < CAPACITY(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i) {
  return (i >= 0 && i <= NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
  return (NEFF(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
  return (NEFF(l) == CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
  int N,i,input;

  do {
    scanf("%d",&N);
  } while (N<0 || N>CAPACITY(*l));

  NEFF(*l) = N;
  if (N!=0) {
    for (i=0;i<N;i++) {
      scanf("%d",&input);
      ELMT(*l,i) = input;
    }
  }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ListDin l) {
  int i;
  
  printf("[");
  if (NEFF(l) != 0) {
    printf("%d",ELMT(l,0));
    for (i=1;i<NEFF(l);i++) 
      printf(",%d",ELMT(l,i));
  }
  printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
  int i;
  ListDin l3;
  
  CreateListDin(&l3,NEFF(l1));
  NEFF(l3) = NEFF(l1);

  if (plus) {
    for (i=0;i<NEFF(l3);i++) {
      ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
    }
  } else {
    for (i=0;i<NEFF(l3);i++) {
      ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
    }
  }
  return l3;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
  boolean equal;
  int i;

  equal = false;
  if (NEFF(l1) == NEFF(l2)) {
    i=0;
    equal = true;
    while (i<NEFF(l1) && equal) {
      if (ELMT(l1,i) != ELMT(l2,i))
        equal = false;
      else
        i++;
    }
  }
  return equal;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
  IdxType i;
  
  if (NEFF(l) == 0)
    i = IDX_UNDEF;
  else {
    i=0;
    while (ELMT(l,i) != val && i < NEFF(l))
      i++;
    if (i == NEFF(l))
      i = IDX_UNDEF;
  }
  return i;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min) {
  int i;

  *max = ELMT(l,0);
  *min = ELMT(l,0);
  for (i=1;i<NEFF(l);i++) {
    if (ELMT(l,i) > *max)
      *max = ELMT(l,i);
    if (ELMT(l,i) < *min)
      *min = ELMT(l,i);
  }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
  int i;

  CreateListDin(lOut,CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);

  for (i=0;i<NEFF(lIn);i++){
    ELMT(*lOut,i) = ELMT(lIn,i);
  }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l) {
  int i;
  ElType sum;

  sum = 0;
  for (i=0;i<NEFF(l);i++) {
    sum += ELMT(l,i);
  }
  return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
  int count,i;

  count = 0;
  for (i=0;i<NEFF(l);i++) {
    if (ELMT(l,i) == val)
      count++;
  }
  return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEven(ListDin l) {
  boolean allEven;
  int i;

  allEven = true;
  i=0;
  while (allEven && i<NEFF(l)) {
    if (ELMT(l,i) % 2 != 0)
      allEven = false;
    else
      i++;
  }
  return allEven;
}
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
  int len,i,j,swapIdx;
  ElType temp;
  
  len = length(*l);
  if (NEFF(*l) != 0) {
    if (asc) {
      for (i=0;i<len-1;i++) {
        swapIdx = i;
        for (j=i+1;j<len;j++) {
          if (ELMT(*l,j) < ELMT(*l,swapIdx))
            swapIdx = j;
        }
        temp = ELMT(*l,swapIdx);
        ELMT(*l,swapIdx) = ELMT(*l,i);
        ELMT(*l,i) = temp;
      }
    } else {
      for (i=0;i<len-1;i++) {
        swapIdx = i;
        for (j=i+1;j<len;j++) {
          if (ELMT(*l,j) > ELMT(*l,swapIdx))
            swapIdx = j;
        }
        temp = ELMT(*l,swapIdx);
        ELMT(*l,swapIdx) = ELMT(*l,i);
        ELMT(*l,i) = temp;
      }
    }
  }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val) {
  ELMT(*l,NEFF(*l)) = val;
  NEFF(*l) += 1;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
  *val = ELMT(*l,NEFF(*l)-1);
  NEFF(*l)--;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
  int i;
  ListDin tempList;

  CreateListDin(&tempList, CAPACITY(*l)+num);
  NEFF(tempList) = NEFF(*l);
  
  for(i=0;i<NEFF(tempList);i++) {
    ELMT(tempList,i) = ELMT(*l,i);
  }
  dealocate(l);
  BUFFER(*l) = BUFFER(tempList);
  CAPACITY(*l) = CAPACITY(tempList);
  NEFF(*l) = NEFF(tempList);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
  int i;
  ListDin tempList;

  CreateListDin(&tempList, CAPACITY(*l)-num);
  NEFF(tempList) = NEFF(*l);
  
  for(i=0;i<NEFF(tempList);i++) {
    ELMT(tempList,i) = ELMT(*l,i);
  }
  dealocate(l);
  CAPACITY(*l) = CAPACITY(tempList);
  BUFFER(*l) = BUFFER(tempList);
  NEFF(*l) = NEFF(tempList);
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListDin *l) {
  int i;
  ListDin tempList;

  CreateListDin(&tempList, NEFF(*l));
  NEFF(tempList) = NEFF(*l);
  
  for(i=0;i<NEFF(tempList);i++) {
    ELMT(tempList,i) = ELMT(*l,i);
  }
  dealocate(l);
  BUFFER(*l) = BUFFER(tempList);
  CAPACITY(*l) = CAPACITY(tempList);
  NEFF(*l) = NEFF(tempList);
}
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */