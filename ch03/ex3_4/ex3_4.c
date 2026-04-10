/* ex3_4.c — const-correct linked list
 * gcc -Wall -Wextra -Werror -std=c11 -o ex3_4 ex3_4.c && ./ex3_4
 */
#include <stdio.h>
#include <assert.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

/* Mutable traversal — head and return value are non-const. */
node_t *list_find(node_t *head, int val) {
    /* TODO: implement */
}

/* const traversal — const in, const out; no cast anywhere. */
const node_t *list_find_c(const node_t *head, int val) {
    /* TODO: implement */
}

int main(void) {
    /* Build list: 1 -> 2 -> 3 */
    node_t n3 = {3, NULL};
    node_t n2 = {2, &n3};
    node_t n1 = {1, &n2};

    /* Mutable traversal */
    node_t *m = list_find(&n1, 2);
    assert(m != NULL && m->val == 2);
    m->val = 99;   /* write through the non-const result — OK */
    m->val = 2;    /* restore */

    /* Miss */
    assert(list_find(&n1, 42) == NULL);

    /* const traversal with a const head — no cast needed */
    const node_t *head = &n1;
    const node_t *c = list_find_c(head, 3);
    assert(c != NULL && c->val == 3);

    /* const traversal with a non-const head — implicit conversion is fine */
    const node_t *c2 = list_find_c(&n1, 1);
    assert(c2 != NULL && c2->val == 1);

    /* Miss */
    assert(list_find_c(head, 42) == NULL);

    printf("All assertions passed.\n");
    return 0;
}
