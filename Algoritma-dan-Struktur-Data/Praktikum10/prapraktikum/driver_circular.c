#include <stdio.h>
#include "list_circular.h"

int main() {
    List l1;
    int dump;

    CreateList(&l1);

    insertFirst(&l1, 4);
    insertFirst(&l1,6);
    insertFirst(&l1,9);
    displayList(l1);printf("\n");
    deleteLast(&l1, &dump);
    displayList(l1);printf("\n");
    deleteLast(&l1, &dump);
    displayList(l1);printf("\n");
    deleteLast(&l1, &dump);
    displayList(l1);printf("\n");

    return 0;
}