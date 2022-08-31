#include "list_dp.h"
#include <stdio.h>

int main() {
    List l1, l2;
    CreateList(&l1);
    CreateList(&l2);

    isEmpty(l1) ? printf("empty\n") : printf("must be empty but not\n");

    printf("Address %p\n", search(l1, 5));
    displayList(l1);printf("\n");
    displayList(l2);printf("\n");

    insertFirst(&l1, 5);
    insertLast(&l2, 8);
    displayList(l1);printf("\n");
    displayList(l2);printf("\n");

    printf("Address 5 %p : %d\n", search(l1, 5), INFO(search(l1,5)));
    printf("Address 9 %p : %d\n", search(l2, 9), search(l2,9) ? INFO(search(l2,9)) : 0);

    insertLast(&l1, 2);
    insertFirst(&l2, 4);
    displayList(l1);printf("\n");
    displayList(l2);printf("\n");

    insertFirst(&l1, 1);
    insertLast(&l2, 9);
    displayList(l1);printf("\n");
    displayList(l2);printf("\n");

    printf("Address 5 %p : %d\n", search(l1, 5), INFO(search(l1,5)));
    printf("Address 9 %p : %d\n", search(l2, 9), INFO(search(l2,9)));

    printf("========================\n");
    printf("TESTING SEARCH\n");
    List lsearch;
    CreateList(&lsearch);
    printf("test list kosong: %p\n", search(lsearch, 5));
    insertFirst(&lsearch, 5);
    printf("test list 1 elemen dan ketemu: %p : %d\n", search(lsearch, 5),INFO(search(lsearch, 5)));
    printf("test list 1 elemen dan tidak ketemu: %p\n", search(lsearch, 6));
    insertLast(&lsearch, 1);
    insertFirst(&lsearch, 4);
    displayList(lsearch);printf("\n");
    insertAfter(&lsearch, allocate(9), search(lsearch,1));
    displayList(lsearch);printf("\n");
    printf("test elemen banyak dan ketemu di depan: %p : %d\n", search(lsearch, 4), INFO(search(lsearch, 4)));
    printf("test elemen banyak dan ketemu di tengah: %p : %d\n", search(lsearch, 1), INFO(search(lsearch, 1)));
    printf("test elemen banyak dan ketemu di belakang: %p : %d\n", search(lsearch, 9), INFO(search(lsearch, 9)));
    printf("test elemen banyak dan ga ketemu: %p\n", search(lsearch, 3));
    displayListBackwards(lsearch);printf(":");displayList(lsearch);printf("\n");
    displayListBackwards(l1);printf(":");displayList(l1);printf("\n");
    displayListBackwards(l2);printf(":");displayList(l2);printf("\n");

    return 0;
}