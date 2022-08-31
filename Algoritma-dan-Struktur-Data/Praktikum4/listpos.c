// NIM              : 13520105
// Nama             : Malik Akbar Hashemi Rafsanjani 
// Tanggal          : 9 September 2021
// Topik praktikum  : ADT List
// Deskripsi        : Implementasi dari fungsi dan prosedur pada listpos.h

#include <stdio.h>
#include "listpos.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l) {
  // KAMUS
  int i;

  // ALGORITMA
  for (i=0;i<CAPACITY;i++) {
    ELMT(*l,i) = VAL_UNDEF;
  }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l) {
  int i, count = 0;

  for (i=0;i<CAPACITY;i++) {
    if (ELMT(l,i) != VAL_UNDEF)
      count += 1;
  }
  return count;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i) {
  if (i >= CAPACITY || i < 0)
    return false;
  
  return true;
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListPos l, int i) {
  if (isIdxValid(l,i)) {
    if (ELMT(l,i) == VAL_UNDEF)
      return false;
    
    return true;
  }
  return false;
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l) {
  if (ELMT(l,0) == VAL_UNDEF)
    return true;
  
  return false;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListPos l) {
  if (ELMT(l,CAPACITY-1) == VAL_UNDEF)
    return false;
  
  return true;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l) {
  int n;

  do {
    scanf("%d", &n);
  } while (n < 0 || n > CAPACITY);
  
  CreateListPos(l);
  if (n != 0) {
    int i, input;
    for (i=0;i<n;i++) {
      do {
        scanf("%d", &input);
      } while (input <= 0);
      ELMT(*l,i) = input;
    }
  }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void displayList(ListPos l) {
  int i;
  
  printf("[");
  if (ELMT(l,0) == VAL_UNDEF) {
    printf("]");
    return;
  }
  printf("%d",ELMT(l,0));
  for (i=1;i<CAPACITY;i++) {
    if (ELMT(l,i) == VAL_UNDEF)
      break;
    printf(",%d",ELMT(l,i));
  }
  printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus) {
  int i;
  ListPos l3;
  CreateListPos(&l3);
  
  if (plus) {
    for(i=0;i<length(l1);i++) {
      ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
    }
    return l3;
  }

  for (i=0;i<length(l1);i++) {
    ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
  }
  return l3;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2) {
  if (length(l1) == length(l2)) {
    int i;
    for (i=0;i<length(l2);i++) {
      if (ELMT(l1,i) != ELMT(l2,i))
        return false;
    }
    return true;
  }
  return false;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val) {
  int i;
  for (i=0;i<CAPACITY;i++) {
    if (ELMT(l,i) == val)
      return i;
    if (ELMT(l,i) == VAL_UNDEF)
      return IDX_UNDEF;
  }
  return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min) {
  int i;

  *max = ELMT(l,0);
  *min = ELMT(l,0);

  for (i=1;i<CAPACITY;i++) {
    if (ELMT(l,i) == VAL_UNDEF)
      return;
    if (ELMT(l,i) > *max)
      *max = ELMT(l,i);
    if (ELMT(l,i) < *min)
      *min = ELMT(l,i);
  }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l) {
  int i;
  boolean isThereEven = false;

  for (i=0;i<CAPACITY;i++) {
    if (ELMT(l,i) == VAL_UNDEF)
      return isThereEven;
    if (ELMT(l,i) % 2 != 0) 
      return false;
    
    isThereEven = true;
  }
}
/* Menghailkan true jika semua elemen l genap */

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc) {
  int i,j,swap_idx,len;
  ElType temp;

  len = length(*l);
  if (asc) {
    for (i=0;i<len;i++) {
      swap_idx = i;
      for (j=i+1;j<len;j++) {
        if (ELMT(*l,j) < ELMT(*l,swap_idx))
          swap_idx = j;
      }
      temp = ELMT(*l,swap_idx);
      ELMT(*l,swap_idx) = ELMT(*l,i);
      ELMT(*l,i) = temp;
    }
    return;
  }

  for (i=0;i<len;i++) {
    swap_idx = i;
    for (j=i+1;j<len;j++) {
      if (ELMT(*l,j) > ELMT(*l,swap_idx))
        swap_idx = j;
    }
    temp = ELMT(*l,swap_idx);
    ELMT(*l,swap_idx) = ELMT(*l,i);
    ELMT(*l,i) = temp;
  }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val) {
  for (int i = 0; i < CAPACITY;i++) {
    if (ELMT(*l,i) == VAL_UNDEF) {
      ELMT(*l,i) = val;
      return;
    }
  }
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val) {
  for (int i = 0; i <CAPACITY;i++) {
    if (ELMT(*l,i) == VAL_UNDEF) {
      *val = ELMT(*l,i-1);
      ELMT(*l,i-1) = VAL_UNDEF;
      return;
    }
  }
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */