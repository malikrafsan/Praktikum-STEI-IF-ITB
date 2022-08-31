#include "queue_linked.h"
#include <stdio.h>

int length5Min(Queue q, int startTime) {
    int len;
    Address walker;

    len = 0;
    walker = ADDR_HEAD(q);
    while (walker != NULL) {
        walker = NEXT(walker);
        if (INFO(walker) > (startTime - 300))
            len++;
    }
    return len; 
}

int main() {
    int n, i, input;
    Queue q;

    CreateQueue(&q);

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        printf("N: %d\n", n);
        scanf("%d", &input);
        // scanf("%d", &input);
        // printf("INPUT=%d", input);
        enqueue(&q, input);
        // printf("input: %d\n", input);
        printf("%d\n", length5Min(q, input));
    }

    return 0;
}