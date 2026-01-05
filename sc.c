#include "sc.h"

#include <stdio.h>
#include <stdlib.h> // qsort(), malloc(), calloc(), free()

void sc_print(const int arr[], int sz, const char *label) {
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

int sc_sort_uniq(int *arr, int sz) {
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

int sc_bsearch(const int arr[], int begin, int end, int e) {
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
                return sc_bsearch(arr, mid + 1, end, e);
            else
                return sc_bsearch(arr, begin, mid, e);
    }
}

typedef struct sc_vec {
    sc_vec_t **storage;     /* array of storage chunks */
    int i;                  /* current storage index */
    int j;                  /* next free slot in storage[i] */
    int capacity_at_i;      /* capacity for storage[i] */
    int max_chunks;         /* maximum number of chunks */
} sc_vec;

sc_vec *sc_vec_init(void) {
    sc_vec *v = calloc(1, sizeof(sc_vec));
    if (!v) return NULL;
    v->i = 0;
    v->j = 0;
    v->capacity_at_i = 1024;
    v->max_chunks = 16;
    v->storage = calloc(v->max_chunks, sizeof(sc_vec_t *));
    if (!v->storage) {
        free(v);
        return NULL;
    }
    v->storage[0] = malloc(sizeof(sc_vec_t) * v->capacity_at_i);
    if (!v->storage[0]) {
        free(v->storage);
        free(v);
        return NULL;
    }
    return v;
}

int sc_vec_push(sc_vec *v, sc_vec_t t) {
    if (!v) return -1;
    if (v->j == v->capacity_at_i) {
        if (v->i + 1 >= v->max_chunks) return -1; /* capacity limit */

        /* Try to allocate new chunk before modifying state */
        int new_capacity = v->capacity_at_i * 2;
        sc_vec_t *new_chunk = malloc(sizeof(sc_vec_t) * new_capacity);
        if (!new_chunk) return -1; /* allocation failed */

        /* Allocation succeeded, now update state */
        v->i++;
        v->j = 0;
        v->capacity_at_i = new_capacity;
        v->storage[v->i] = new_chunk;
    }
    v->storage[v->i][v->j++] = t;
    return 0; /* success */
}

void sc_vec_free(sc_vec *vec) {
    if (!vec) return;
    if (vec->storage) {
        for (int i = 0; i <= vec->i && i < vec->max_chunks; ++i) {
            free(vec->storage[i]);
        }
        free(vec->storage);
    }
    free(vec);
}
