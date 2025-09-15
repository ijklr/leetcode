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
