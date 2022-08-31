#include "stack_linked.h"

/* Prototype manajemen memori */
Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s) {
    return ADDR_TOP(s) == NULL;
}
/* Mengirim true jika Stack kosong: ADDR_TOP(s) = NULL */
void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NULL;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
void push(Stack *s, ElType x) {
    Address added;

    added = newNode(x);
    if (added != NULL) {
        NEXT(added) = ADDR_TOP(*s);
        ADDR_TOP(*s) = added;
    }
}
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
void pop(Stack *s, ElType *x) {
    Address del;

    del = ADDR_TOP(*s);
    *x = INFO(del);
    ADDR_TOP(*s) = NEXT(del);
    free(del);
}
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
