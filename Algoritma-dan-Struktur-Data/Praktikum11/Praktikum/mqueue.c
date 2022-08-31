#include "queue_linked.h"
#include <stdio.h>

int length5Min(Queue q, int startTime) {
    int len;
    Address walker;

    len = 0;
    walker = ADDR_HEAD(q);
    while (walker != NULL) {
        if (INFO(walker) >= (startTime - 300))
            len++;
        walker = NEXT(walker);
    }

    return len; 
}

int main() {
    int n, i;
    ElType input1;
    Queue q;

    CreateQueue(&q);

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        scanf("%d", &input1);
        enqueue(&q, input1);

        printf("%d\n", length5Min(q, input1));
    }

    return 0;
}