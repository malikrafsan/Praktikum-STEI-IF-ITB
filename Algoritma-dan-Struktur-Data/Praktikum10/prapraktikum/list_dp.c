#include "list_dp.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return (FIRST(l) == NULL && LAST(l) == NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
void deallocate (Address p) {
    free(p);
}
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
    Address walker;

    walker = FIRST(l);
    while (walker != NULL && INFO(walker) != val) {
        walker = NEXT(walker);
    }
    return walker;
}
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address new;

    new = allocate(val);
    if (new != NULL) {
        NEXT(new) = FIRST(*l);

        if (!isEmpty(*l)) {
            PREV(FIRST(*l)) = new;
        } else {
            LAST(*l) = new;
        }
        FIRST(*l) = new;
    }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void insertLast(List *l, ElType val) {
    Address new;

    new = allocate(val);
    if (new != NULL) {
        PREV(new) = LAST(*l);
        if (!isEmpty(*l)) {
            NEXT(LAST(*l)) = new;
        } else {
            FIRST(*l) = new;
        }
        LAST(*l) = new;
    }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertAfter(List *L, Address p, Address pRec) {
    NEXT(p) = NEXT(pRec);
    PREV(p) = pRec;

    if (NEXT(p) != NULL)
        PREV(NEXT(p)) = p;
    else
        LAST(*L) = p;
    NEXT(pRec) = p;
}
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    Address del;

    *val = INFO(FIRST(*l));
    del = FIRST(*l);

    if (FIRST(*l) == LAST(*l))
        LAST(*l) = NULL;
    else
        PREV(NEXT(FIRST(*l))) = NULL;

    FIRST(*l) = NEXT(FIRST(*l));
    deallocate(del);
    // FIRST(*l) = NEXT(FIRST(*l));
    // deallocate(PREV(FIRST(*l)));
    // if (FIRST(*l) != NULL)
    //     PREV(FIRST(*l)) = NULL;
    // else
    //     LAST(*l) = NULL;
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val) {
    Address del;

    del = LAST(*l);
    *val = INFO(del);
    if (FIRST(*l) == LAST(*l))
        FIRST(*l) = NULL;
    else
        NEXT(PREV(LAST(*l))) = NULL;
    
    LAST(*l) = PREV(LAST(*l));
    deallocate(del);
}
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
void deleteAfter(List *l, Address *pDel, Address pRec) {
    *pDel = NEXT(pRec);

    if (NEXT(pRec) != NULL) {
        NEXT(pRec) = NEXT(NEXT(pRec));
        
        if (NEXT(pRec) != NULL)
            PREV(NEXT(*pDel)) = pRec;
        else
            LAST(*l) = pRec;
    }
    // deallocate(*pDel);
    PREV(*pDel) = NULL;
    NEXT(*pDel) = NULL;
}
/* I.S. List tidak kosong. pRec adalah anggota list. 
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    Address walker;

    walker = FIRST(l);
    printf("[");
    if (!isEmpty(l)) {
        printf("%d", INFO(walker));
        walker = NEXT(walker);

        while (walker != NULL) {
            printf(",%d", INFO(walker));
            walker = NEXT(walker);
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void displayListBackwards(List l) {
    Address walker;

    walker = LAST(l);
    printf("[");
    if (!isEmpty(l)) {
        printf("%d", INFO(walker));
        walker = PREV(walker);

        while (walker != NULL) {
            printf(",%d", INFO(walker));
            walker = PREV(walker);
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */