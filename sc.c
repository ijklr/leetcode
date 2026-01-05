#include "sc.h"

#include <stdio.h>
#include <stdlib.h> // qsort(), malloc(), calloc(), free()

void sc_print(int arr[], int sz, const char *label) {
    if (!arr || !label) return;
    printf("%s:", label);
    for (int i = 0; i < sz; ++i) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

static int sc_compare_int(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int sc_uniq(int *arr, int sz) {
    if (!arr || sz <= 0) {
        return 0;
    }
    if (sz == 1) {
        return sz;
    }
    qsort(arr, sz, sizeof(int), sc_compare_int);
    int write_i = 1;
    int prev = arr[0];
    for (int read_i = 1; read_i < sz; ++read_i) {
        int read = arr[read_i];
        if (prev != read) {
            prev = read;
            arr[write_i++] = read;
        }
    }
    return write_i;
}

int sc_find(const int arr[], int begin, int end, int e) {
    if (!arr || begin < 0 || end < begin) {
        return -1;
    }
    int sz = end - begin;
    int mid;
    switch (sz) {
        case 0:
            return -1;
        case 1:
            return arr[begin] == e ? begin : -1;
        case 2:
            return arr[begin] == e ? begin
                                   : (arr[begin + 1] == e ? begin + 1 : -1);
        default:
            mid = begin + sz / 2;
            if (arr[mid] == e) return mid;
            if (arr[mid] < e)
                return sc_find(arr, mid + 1, end, e);
            else
                return sc_find(arr, begin, mid, e);
    }
}

typedef struct sc_sstore {
    sc_sstore_t **storage;  /* array of storage chunks */
    int i;                  /* current storage index */
    int j;                  /* next free slot in storage[i] */
    int capacity_at_i;      /* capacity for storage[i] */
    int max_chunks;         /* maximum number of chunks */
} sc_sstore;

sc_sstore *sc_sstore_init(void) {
    sc_sstore *s = calloc(1, sizeof(sc_sstore));
    if (!s) return NULL;
    s->i = 0;
    s->j = 0;
    s->capacity_at_i = 1024;
    s->max_chunks = 16;
    s->storage = calloc(s->max_chunks, sizeof(sc_sstore_t *));
    if (!s->storage) {
        free(s);
        return NULL;
    }
    s->storage[0] = malloc(sizeof(sc_sstore_t) * s->capacity_at_i);
    if (!s->storage[0]) {
        free(s->storage);
        free(s);
        return NULL;
    }
    return s;
}

int sc_sstore_push(sc_sstore *s, sc_sstore_t t) {
    if (!s) return -1;
    if (s->j == s->capacity_at_i) {
        if (s->i + 1 >= s->max_chunks) return -1; /* capacity limit */

        /* Try to allocate new chunk before modifying state */
        int new_capacity = s->capacity_at_i * 2;
        sc_sstore_t *new_chunk = malloc(sizeof(sc_sstore_t) * new_capacity);
        if (!new_chunk) return -1; /* allocation failed */

        /* Allocation succeeded, now update state */
        s->i++;
        s->j = 0;
        s->capacity_at_i = new_capacity;
        s->storage[s->i] = new_chunk;
    }
    s->storage[s->i][s->j++] = t;
    return 0; /* success */
}

void sc_sstore_free(sc_sstore *store) {
    if (!store) return;
    if (store->storage) {
        for (int i = 0; i <= store->i && i < store->max_chunks; ++i) {
            free(store->storage[i]);
        }
        free(store->storage);
    }
    free(store);
}
