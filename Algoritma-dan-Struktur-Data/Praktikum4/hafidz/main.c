#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin list, l1, l2;
    CreateListDin(&list, 5);
    printf("panjang list sekarang : %d\n", length(list));
    readList(&list);
    printf("List sekarang : ");
    displayList(list);
    printf("\n");
    printf("panjang list sekarang : %d\n", length(list));
    // if (isEmpty(list)) printf("Kosong\n");
    // else printf("Isi nihh\n");
    // if (isFull(list)) printf("Penuh\n");
    // else printf("Masih ada tempat sisa\n");

    printf("Anggota list terakhir : %d\n", getLastIdx(list));
    // int lastVal;
    // deleteLast(&list, &lastVal);
    // printf("List sekarang : ");
    // displayList(list);
    // printf("\n");

    // copyList(list, &l1);
    // if (isListEqual(list, l1)) printf("sama bro\n");
    // else printf("beda cuy\n");
    // l2 = plusMinusList(list, l1, true);
    // printf("L2 hasil list+l1 : ");
    // displayList(l2);
    // printf("\n");
    // l2 = plusMinusList(list, l1, false);
    // printf("L2 hasil list-l1 : ");
    // displayList(l2);
    // printf("\n");

    // printf("data 2 berada di urutan ke-%d\n", indexOf(list, 2));
    // printf("kemunculan angka 2 ada sebanyak %d kali\n", countVal(list, 2));
    // int max, min;
    // extremes(list, &max, &min);
    // printf("max: %d\nmin: %d\n", max, min);
    // printf("Jumlah: %d\n", sumList(list));
    // if (isAllEven(list)) printf("Semua genap\n");
    // else printf("Ada yang ganjil\n");

    insertLast(&list, 5);
    printf("List sekarang : ");
    displayList(list);
    printf("\n");

    // if (isFull(list)) printf("Penuh\n");
    // else printf("Masih ada tempat sisa\n");
    // growList(&list, 5);
    // printf("List setelah di growth : ");
    // displayList(list);
    // printf("\n");
    // if (isFull(list)) printf("Penuh\n");
    // else printf("Masih ada tempat sisa\n");
    // shrinkList(&list, 3);
    // printf("List setelah di shrink : ");
    // displayList(list);
    // printf("\n");
    // if (isFull(list)) printf("Penuh\n");
    // else printf("Masih ada tempat sisa\n");
    // compactList(&list);
    // printf("List setelah compact : ");
    // displayList(list);
    // printf("\n");
    // if (isFull(list)) printf("Penuh\n");
    // else printf("Masih ada tempat sisa\n");
}