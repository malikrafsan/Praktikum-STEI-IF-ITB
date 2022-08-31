#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

// List representasi Eksplisit dan Dinamik

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
// Algoritma
    BUFFER(*l) = (ElType*)malloc(capacity*sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocate(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
    return NEFF(l);
}

/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (NEFF(l)-1);
}

/* ********** Test Indeks yang valid ********** */
// KEMUNGKINAN BESAR SALAH DI SINI (TESTCASE 5 dan 6)
boolean isIdxValid(ListDin l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

    return (!(i<0 || i>=CAPACITY(l)));
}

boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

    return (i>=0 && i<=NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

    return (NEFF(l) == 0);
}

/* *** Test list penuh *** */
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */

// Kamus lokal
// n, i, masukan : integer

// Algoritma
    int i,n, masukan;
    scanf("%d",&n);
    while (n<0 || n>CAPACITY(*l)){
        scanf("%d",&n);
    }
    NEFF(*l) = n;
    for (i=0; i<n; i++){
        scanf("%d",&masukan);
        ELMT(*l,i) = masukan;
    }
}

void displayList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

// Kamus lokal

// Algoritma
    int i;
    if (NEFF(l) == 0){
        printf("[]");
    } else {
        printf("[%d", ELMT(l,0));
        for (i=1; i<NEFF(l); i++){
            printf(",%d", ELMT(l,i));
        }
        printf("]");

    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

// Kamus lokal
// i : integer

// Algoritma
    ListDin listBaru;
    CreateListDin(&listBaru, NEFF(l1));
    NEFF(listBaru) = NEFF(l1);
    int i;
    if (plus) {
        for (i=0; i<NEFF(l1); i++){
            ELMT(listBaru, i) = ELMT(l1,i) + ELMT(l2,i);
        }
    } else {
        for (i=0; i<NEFF(l1); i++){
            ELMT(listBaru, i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }

    return listBaru;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    
    // Kamus lokal
    // status : boolean
    // i : integer

    // Algoritma
    int i=0;
    boolean status = true;
    if (NEFF(l1) != NEFF(l2)) status = false;
    else{
        while (i < NEFF(l1) && status){
            if (ELMT(l1,i) != ELMT(l2,i)) status = false;
            else i++;
        }
    }

    return status;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

    // Kamus lokal
    // i : integer

    // Algoritma
    int i=0;
    while (i<NEFF(l)){
        if (ELMT(l,i) == val) return i;
        else i++;
    }

    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

    // Kamus lokal
    // i : integer

    // Algoritma
    int i;
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for (i=1; i<NEFF(l); i++){
        if (ELMT(l,i) > *max) *max = ELMT(l,i);
        else if (ELMT(l,i) < *min) *min = ELMT(l,i); 
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

    // Kamus lokal
    // i : integer

    // Algoritma
    CreateListDin(lOut, CAPACITY(lIn));
    int i;
    for (i=0; i<NEFF(lIn); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
}

ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */

    // Kamus lokal
    // i, sum : integer

    // Algoritma
    int i, sum=0;
    for (i=0; i<NEFF(l); i++){
        sum += ELMT(l,i);
    }

    return sum;
}

int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

    // Kamus lokal
    // i, count : integer

    // Algoritma
    int i, count=0;
    for(i=0; i<NEFF(l); i++){
        if (ELMT(l,i) == val) count++;
    }

    return count;
}

boolean isAllEven(ListDin l){
/* Menghasilkan true jika semua elemen l genap. l boleh kosong */

    // Kamus lokal
    // status : boolean
    // i : integer

    // Algoritma
    int i=0;
    boolean status = true;

    while (i<NEFF(l) && status){
        if (ELMT(l,i)%2 == 1) status = false;
        else i++;
    }

    return status;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

    // Kamus lokal
    // i,j,idx : integer
    // temp : ElType

    // Algoritma
    int i, j, idx;
    ElType temp;

    if (asc){
        for (i = 0; i < (NEFF(*l)-1); i++){
            idx = i;
            for (j = i+1; j < NEFF(*l); j++){
                if (ELMT(*l, j) < ELMT(*l, idx)) idx = j;
            }

            temp = ELMT(*l, idx);
            ELMT(*l, idx) = ELMT(*l, i);
            ELMT(*l, i) = temp;
        }
    } else {
        for (i = 0; i < (NEFF(*l)-1); i++){
            idx = i;
            for (j = i+1; j < NEFF(*l); j++){
                if (ELMT(*l, j) > ELMT(*l, idx)) idx = j;
            }
            
            temp = ELMT(*l, idx);
            ELMT(*l, idx) = ELMT(*l, i);
            ELMT(*l, i) = temp;
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

    // Algoritma
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

    // Algoritma
    *val = ELMT(*l, NEFF(*l)-1);
    NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

// Kamus lokal
// i : integer
// lBaru : ListDin

// Algoritma
    ListDin lBaru;
    int i;
    CreateListDin(&lBaru, CAPACITY(*l)+num);
    NEFF(lBaru) = NEFF(*l);
    for (i=0; i< NEFF(lBaru); i++){
        ELMT(lBaru, i) = ELMT(*l, i);
    }
    dealocate(l);
    CAPACITY(*l) = CAPACITY(lBaru);
    BUFFER(*l) = BUFFER(lBaru);
    NEFF(*l) = NEFF(lBaru);
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

// Kamus lokal
// i : integer
// lBaru : ListDin

// Algoritma
    ListDin lBaru;
    int i;
    CreateListDin(&lBaru, CAPACITY(*l)-num);
    NEFF(lBaru) = NEFF(*l);
    for (i=0; i< NEFF(lBaru); i++){
        ELMT(lBaru, i) = ELMT(*l, i);
    }
    dealocate(l);
    CAPACITY(*l) = CAPACITY(lBaru);
    BUFFER(*l) = BUFFER(lBaru);
    NEFF(*l) = NEFF(lBaru);
}

void compactList(ListDin *l){
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */

// Kamus lokal
// i : integer
// lBaru : ListDin

// Algoritma
    ListDin lBaru;
    int i;
    CreateListDin(&lBaru, NEFF(*l));
    NEFF(lBaru) = NEFF(*l);
    for (i=0; i< NEFF(lBaru); i++){
        ELMT(lBaru, i) = ELMT(*l, i);
    }
    dealocate(l);
    CAPACITY(*l) = CAPACITY(lBaru);
    BUFFER(*l) = BUFFER(lBaru);
    NEFF(*l) = NEFF(lBaru);
}