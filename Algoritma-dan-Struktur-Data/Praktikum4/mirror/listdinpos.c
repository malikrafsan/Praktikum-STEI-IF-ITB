#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
  CAPACITY(*l) = capacity;
  BUFFER(*l) = (ElType*)malloc(capacity * sizeof(ElType));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocate(ListDin *l) {
  CAPACITY(*l) = 0;
  free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
  IdxType i;
  
  i = 0;
  while (i < CAPACITY(l) && ELMT(l,i) != VAL_UNDEF) {
    i++;
  }
  return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
  return length(l)-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
  boolean status;
  
  if (i >= CAPACITY(l) || i < 0) 
    status = false;
  else
    status = true;

  return status;
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i) {
  boolean status;
  
  status  = false;
  if (isIdxValid(l,i))
    if (ELMT(l,i) != VAL_UNDEF)
      status = true;

  return status;
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
  boolean status;

  if (ELMT(l,0) == VAL_UNDEF)
    status = false;
  else
    status = true;

  return status; 
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
  boolean status;

  if (ELMT(l,CAPACITY(l)-1) == VAL_UNDEF)
    status = true;
  else
    status = false;

  return status; 
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
  int N;
  IdxType i;
  ElType input;

  do {
    scanf("%d", &N);
  } while (N < 0 || N > CAPACITY(*l));

  if (N != 0) {
    for(i=0;i<N;i++){
      // CHECK WHETHER ELEMENT MUST BE POSITIVE
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
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ListDin l) {
  IdxType i;

  printf("[");
  if (ELMT(l,0) != VAL_UNDEF) {
    printf("%d",ELMT(l,0));
    i=1;
    while (ELMT(l,i) != VAL_UNDEF){
      printf(",%d",ELMT(l,i));
      i++;
    }
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
  IdxType i;
  ListDin l3;
  CreateListDin(&l3,CAPACITY(l1));

  i=0;
  if (plus) {
    while ((i<CAPACITY(l1)) && ELMT(l1,i) != VAL_UNDEF){
      ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
      i++;
    }
  } else {
    while ((i<CAPACITY(l1)) && ELMT(l2,i) != VAL_UNDEF) {
      ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
      i++;
    }
  }
  return l3;
}
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
  IdxType i;
  boolean status;

  i=0;
  status = true;
  while((i<CAPACITY(l1)) && status && ELMT(l1,i) != VAL_UNDEF) {
    if (ELMT(l1,i) != ELMT(l2,i)) 
      status = false;
    else
      i++;
  }
  return status;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
  IdxType i;
  int len;

  i=0;
  len = length(l);
  while((i<len && (ELMT(l,i) != val)){
    i++;
  }
  if (ELMT(l,i) == VAL_UNDEF || i == CAPACITY(l))
    i = VAL_UNDEF;
    // CHECK WHETHER ITS VAL_UNDEF OR IDX_UNDEF 
  return i;
}
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan nilai tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */

// ABOVE THIS 
// CHECK AGAIN
// CHECK AGAIN
// CHECK AGAIN

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min) {
  IdxType i;
  int len;
  
  *max = ELMT(l,0);
  *min = ELMT(l,0);

  len = length(l);
  for (i=0; i<len; i++) {
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
  int i,len;

  CreateListDin(lOut,CAPACITY(lIn));
  len = length(lIn);

  for (i=0;i<len;i++) {
    ELMT(*lOut,i) = ELMT(lIn,i);
  }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l) {
  int i,len;
  ElType sum;

  sum = 0;
  len = length(l);
  for (i=0;i<len;i++) {
    sum += ELMT(l,i);
  }
  return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
  int count,i,len;

  count=0;
  len = length(l);
  
  for (i=0;i<len;i++){
    if (ELMT(l,i) == val)
      count++;
  }
  return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEven(ListDin l) {
  int i,len;
  boolean status;

  status=true;
  i=0;
  len = length(l);

  while(status && i<len) {
    if (ELMT(l,i) % 2 != 0)
      status = false;
    else
      i++;
  }
  return status;
}
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
  int len,i,j,swapIdx;
  ElType temp;
  
  len = length(*l);
  if (len != 0) {
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
  ELMT(*l,length(*l)) = val;
}
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
  int len;
  
  len = length(*l);
  *val = EMLT(*l,len-1);
  ELMT(*l,len-1) = VAL_UNDEF;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
  int i,len;
  ListDin tempList;

  CreateListDin(&tempList, CAPACITY(*l)+num);
  
  len = length(*l);
  for(i=0;i<len;i++) {
    ELMT(tempList,i) = ELMT(*l,i);
  }
  dealocate(l);
  BUFFER(*l) = BUFFER(tempList);
  CAPACITY(*l) = CAPACITY(tempList);
}
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
  int i;
  ListDin tempList;

  CreateListDin(&tempList, CAPACITY(*l)-num);
  
  for(i=0;i<length(*l);i++) {
    ELMT(tempList,i) = ELMT(*l,i);
  }
  dealocate(l);
  CAPACITY(*l) = CAPACITY(tempList);
  BUFFER(*l) = BUFFER(tempList);
}
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListDin *l) {
  int i,len;
  ListDin tempList;

  len = length(*l);
  CreateListDin(&tempList, len);
  
  for(i=0;i<len;i++) {
    ELMT(tempList,i) = ELMT(*l,i);
  }
  dealocate(l);
  BUFFER(*l) = BUFFER(tempList);
  CAPACITY(*l) = CAPACITY(tempList);
}
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
