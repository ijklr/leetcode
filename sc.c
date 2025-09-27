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
// I start with 1024 items for t[0].
// For leetcodee, there is no way it will need to double 16 times or more.
sc_sstore_t *storage[16];
int i; // we're at the ith storage.
int j; // we're at the jth element in storage[i].
int capacity_at_i; // current capacity for storage[i].
} sc_sstore;

sc_sstore* sc_sstore_init() {
return calloc(1, sizeof(sc_sstore));
}

void sc_sstore_push(sc_sstore* s, sc_sstore_t t) {
if(s->j == s->capacity_at_i) {
s->i++;
s->j=0;
s->storage[s->i] = malloc(s->capacity_at_i * 2);
}

//store->t[i]


}

void sc_sstore_free(sc_sstore* store) {
if (!store) {
return;
}
for (int i=0; i<16; ++i) {
if (store->t[i]) {
free(store->t[i]);
}
}
}
