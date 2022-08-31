#include "listrec.h"

int main(){
    List l;
    l = newNode(13);
    l = konsb(l, 87);
    l = konsb(l, 88);
    l = konso(l, 89);
    l = konso(l, 90);
    l = konso(l, 91);
    l = konso(l, 92);
    l = konsb(l, -87);
    List lp, ln;
            //lp = NULL;
        //ln = NULL;
    displayList(l);
    printf("===============\n");
    splitOnX(l, 90,&lp, &ln);
    displayList(ln);
    printf("avg %f\n", averageList(l));

    List l2;
    l2 = newNode(13);
    l2 = konsb(l2, 87);
    l2 = konsb(l2, 90);
    l2 = konsb(l2, -87);
    l2 = konsb(l2, 88);
    //l2 = konsb(l2, 87);
    List list1, list2;
    list1 = NULL;
    list2 = NULL;
    list1 = konsb(list1, 12);
    list1 = konsb(list1, 13);
    list1 = konsb(list1, 14);
    list1 = konsb(list1, 15);

    list2 = konsb(list2, 12);
    list2 = konsb(list2, 13);
    list2 = konsb(list2, 2);
    list2 = konsb(list2, 5);
    list2 = konsb(list2, 11);
    printf("iae %d\n", isAllExist(list1, list2));
}