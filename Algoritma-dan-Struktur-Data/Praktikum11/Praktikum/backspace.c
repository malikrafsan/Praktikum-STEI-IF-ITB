#include "stack_linked.h"
#include <stdio.h>

int main() {
    int n, m, i, input, dump1, dump2;
    boolean stillTrue, allEmpty;
    Stack S1, S2;

    CreateStack(&S1);
    CreateStack(&S2);

    scanf("%d", &n);
    scanf("%d", &m);

    for (i=0;i<n;i++) {
        scanf("%d", &input);
        if (input != 0)
            push(&S1, input);
        else if (!isEmpty(S1))
            pop(&S1, &dump1);
    }
    for (i=0;i<m;i++) {
        scanf("%d", &input);
        if (input != 0)
            push(&S2, input);
        else if (!isEmpty(S2))
            pop(&S2, &dump2);
    }

    stillTrue = true;
    while (!isEmpty(S1) && !isEmpty(S2) && stillTrue) {
        pop(&S1, &dump1);
        pop(&S2, &dump2);

        if (dump1 != dump2)
            stillTrue = false;
    }
    allEmpty = isEmpty(S1) && isEmpty(S2);

    if (stillTrue && allEmpty)
        printf("Sama\n");
    else
        printf("Tidak sama\n");

    return 0;
}