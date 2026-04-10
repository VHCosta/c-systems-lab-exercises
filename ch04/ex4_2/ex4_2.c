/* ex4_2.c — Fixed-size slab allocator with embedded free list
 * gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address -g \
 *     -o ex4_2 ex4_2.c && ./ex4_2
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    void   *buf;
    void   *free_list;
    size_t  obj_size;
    size_t  capacity;
    size_t  in_use;
} slab_t;

slab_t *slab_init(size_t obj_size, size_t capacity) {
    /* TODO: implement */
}

void *slab_alloc(slab_t *s) {
    /* TODO: implement */
}

void slab_free(slab_t *s, void *obj) {
    /* TODO: implement */
}

void slab_destroy(slab_t *s) {
    /* TODO: implement */
}

typedef struct { int x, y, z; } Point;

int main(void) {
    const size_t CAP = 10;
    slab_t *s = slab_init(sizeof(Point), CAP);
    assert(s);

    Point *ptrs[10];
    for (size_t i = 0; i < CAP; i++) {
        ptrs[i] = slab_alloc(s);
        assert(ptrs[i]);
        ptrs[i]->x = (int)i;
        ptrs[i]->y = (int)i * 2;
        ptrs[i]->z = (int)i * 3;
    }
    assert(slab_alloc(s) == NULL);
    assert(s->in_use == CAP);

    for (size_t i = CAP; i-- > CAP / 2;)
        slab_free(s, ptrs[i]);

    for (size_t i = CAP / 2; i < CAP; i++) {
        ptrs[i] = slab_alloc(s);
        assert(ptrs[i]);
        ptrs[i]->x = (int)i + 100;
    }

    for (size_t i = 0; i < CAP / 2; i++) {
        assert(ptrs[i]->x == (int)i);
        assert(ptrs[i]->y == (int)i * 2);
    }

    printf("slab test passed — %zu objects, no corruption\n", CAP);
    slab_destroy(s);
    return 0;
}
