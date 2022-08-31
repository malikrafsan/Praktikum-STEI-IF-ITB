#include "list_circular.h"
#include <stdio.h>
#include "boolean.h"

void deleteRR (List *l, ElType tQ) {
    Address last, precLast;
    ElType dump;

    if (!isEmpty(*l)) {
        last = FIRST(*l);
        precLast = NULL;

        while (NEXT(last) != FIRST(*l)) {
            precLast = last;
            last = NEXT(last);
        }
        if (INFO(last) > tQ) {
            FIRST(*l) = last;
            INFO(last) = INFO(last) - tQ;
            printf("%d\n", tQ);
        } else {
            printf("%d\n", INFO(last));
            deleteLast(l, &dump);
        }
    } else {
        printf("List kosong\n");
    }
}
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last)=INFO(last)-tQ
- jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */

float average (List l) {
    float sum;
    int count;
    Address walker;

    sum = 0.0;
    count = 0;
    walker = FIRST(l);
    do {
        sum += INFO(walker);
        // printf("%d ", INFO(walker));
        count++;
        walker = NEXT(walker);
    } while (walker != FIRST(l));
    // printf("\n");

    return (sum / count);
}
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */

int main() {
    int tQ, input;
    char code;
    List L;

    CreateList(&L);

    do {
        scanf("%d", &tQ);
    } while (tQ <= 0);

    while (1) {
        scanf(" %c", &code);

        if (code == 'F') {
            // DELETE LATER
            // displayList(L);printf("\n");
            if (!isEmpty(L))
                printf("%.2f\n", average(L));
            else
                printf("Proses selesai\n");
            break;
        }
        else if (code == 'A') {
            scanf("%d", &input);
            if (input > 0) {
                insertFirst(&L, input);
            }
        } else if (code == 'D') {
            deleteRR(&L, tQ);
            // displayList(L);printf("\n");
        } else {
            printf("Kode salah\n");
        }
    }

    return 0;
}