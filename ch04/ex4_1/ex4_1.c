/* ex4_1.c — Valgrind-clean linked list
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex4_1 ex4_1.c && ./ex4_1
 * valgrind --leak-check=full ./ex4_1
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int         val;
    struct Node *next;
} Node;

Node *node_new(int val) {
    /* TODO: implement */
}

void list_free(Node *head) {
    /* TODO: implement */
}

int main(void) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < 10; i++) {
        Node *n = node_new(i);
        if (!tail) head = tail = n;
        else { tail->next = n; tail = n; }
    }

    for (Node *p = head; p; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    list_free(head);
    return 0;
}
