#include "listrec.h"
#include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x) {
    Address P;
    P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
    return (l == NULL);
}
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
int isOneElmt(List l) {
    return isEmpty(l) ? false : isEmpty(NEXT(l));
}
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
    return INFO(l);
}
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l) {
    return NEXT(l);
}
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e) {
    Address P = newNode(e);
    if (P != NULL) {
        NEXT(P) = l;
        return P;
    } else {
        return l;
    }
}
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e) {
    return isEmpty(l) ? konso(l, e) : konso(konsb(tail(l), e), head(l));
}
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* Fungsi dan Prosedur Lain */
int length(List l) {
    return isEmpty(l) ? 0 : 1 + length(tail(l));
}
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

ElType maxList (List l) {
    ElType max = head(l);
    ElType temp;

    if (isOneElmt(l)) {
        return max;
    } else {
        temp = maxList(tail(l));
        if (temp > max) {
            max = temp;
        }
        return max;
    }
}

ElType minList (List l) {
    ElType min = head(l);
    ElType temp;

    if (isOneElmt(l)) {
        return min;
    } else {
        temp = minList(tail(l));
        if (temp < min) {
            min = temp;
        }
        return min;
    }
}

ElType sumList (List l) {
    ElType sum = head(l);
    ElType temp;

    if (isOneElmt(l)) {
        return sum;
    } else {
        temp = sumList(tail(l));
        sum = sum + temp;
        return sum;
    }
}

float averageList (List l) {
    float avg = sumList(l) / (float) length(l);
    return avg;
}

List inverseList(List l) {
    if (isEmpty(l)) {
        return l;
    } else {
        return konsb(inverseList(tail(l)), head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2) {
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else if (isOneElmt(l)) {
        *l1 = *l2 = NULL;
        if (head(l) >= 0)
            *l1 = konso(*l1, head(l));
        else
            *l2 = konso(*l2, head(l));
    } else {
        if (head(l) >= 0) {
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }   
}

void splitOnX(List l, ElType x, List *l1, List *l2) {
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else if (isOneElmt(l)) {
        *l1 = *l2 = NULL;
        if (head(l) < x)
            *l1 = konso(*l1, head(l));
        else
            *l2 = konso(*l2, head(l));
    } else {
        if (head(l) < x) {
            splitOnX(tail(l), x, l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitOnX(tail(l), x, l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

boolean isExist(ElType x, List l) {
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return isExist(x, tail(l));
    }
}

boolean isAllExist(List l1, List l2) {
    if (isEmpty(l1)) {
        return false;
    } else if (isOneElmt(l1)) {
        return isExist(head(l1), l2);
    } else {
        return isExist(head(l1), l2) && isAllExist(tail(l1), l2);
    }
}

List listBeforeX(List l, ElType x) {
    if (isEmpty(l)) {
        return l;
    } else if (head(l) == x) {
        return NULL;
    } else {
        return konso(listBeforeX(tail(l), x), head(l));
    }
}

List takeFlipFlop(List l, boolean take) {
    if (isEmpty(l)) {
        return l;
    } else {
        if (take) {
            return konso(takeFlipFlop(tail(l), !take), head(l));
        } else {
            return takeFlipFlop(tail(l), !take);
        }
    }
}

List takeEvenIndex(List l) {
    return takeFlipFlop(l, false);
}
List takeOddIndex(List l) {
    return takeFlipFlop(l, true);
}

boolean isSameList(List l1, List l2) {
    if (length(l1) != length(l2)) {
        return false;
    } else {
        if (isEmpty(l1)) {
            return true;
        } else {
            return (head(l1) == head(l2)) && isSameList(tail(l1), tail(l2));
        }
    }
}

boolean isLessThan(List l1, List l2) {
    if (isEmpty(l1) && isEmpty(l2)) {
        return false;
    } else if (isEmpty(l1)) {
        return true;
    } else if (isEmpty(l2)) {
        return false;
    } else {
        if (head(l1) < head(l2)) {
            return true;
        } else if (head(l1) > head(l2)) {
            return false;
        } else {
            return isLessThan(tail(l1), tail(l2));
        }
    }
}

int compareList(List l1, List l2) {
    if (isSameList(l1, l2)) {
        return 0;
    } else if (isLessThan(l1,l2))
        return -1;
    else {
        return 1;
    }
}