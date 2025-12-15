#include "sc.h"

#include <stdio.h>
#include <stdlib.h>  // qsort()

void sc_print(int arr[], int sz, const char *label) {
    printf("%s:", label);
    for (int i = 0; i < sz; ++i) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

static int sc_compare_int(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    // avoids overflow
    return (x > y) - (x < y);
}

int sc_uniq(int *arr, int sz) {
    if (sz == 0 || sz == 1) {
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

int sc_find(int arr[], int begin, int end, int e) {
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
    sc_sstore_t *storage[16];
    int i;              // current storage index
    int j;              // next free slot in storage[i]
    int capacity_at_i;  // capacity for storage[i]
} sc_sstore;

sc_sstore *sc_sstore_init() {
    sc_sstore *s = calloc(1, sizeof(sc_sstore));
    if (!s) return NULL;
    s->i = 0;
    s->j = 0;
    s->capacity_at_i = 1024;
    s->storage[0] = malloc(sizeof(sc_sstore_t) * s->capacity_at_i);
    return s;
}

void sc_sstore_push(sc_sstore *s, sc_sstore_t t) {
    if (!s) return;
    if (s->j == s->capacity_at_i) {
        if (s->i + 1 >= 16) return; /* capacity limit */
        s->i++;
        s->j = 0;
        s->capacity_at_i *= 2;
        s->storage[s->i] = malloc(sizeof(sc_sstore_t) * s->capacity_at_i);
        if (!s->storage[s->i]) return;
    }
    s->storage[s->i][s->j++] = t;
}

void* sc_sstore_find(sc_sstore *s) {
    (void)s;
    return NULL;
}

void sc_sstore_free(sc_sstore *store) {
    if (!store) return;
    for (int i = 0; i <= store->i && i < 16; ++i) {
        if (store->storage[i]) free(store->storage[i]);
    }
    free(store);
}
