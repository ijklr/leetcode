#ifndef SC_H
#define SC_H

// Make the elements in arr unique. Returns the resulting size.
int sc_uniq(int *arr, int sz);

// Binary search since `arr` is sorted in ascending order already.
// Returns the index where the matching element resides.
// The search includes `begin` but excludes `end`.
// Returns -1 if not found.
int sc_find(int arr[], int begin, int end, int e);

// print the array
void sc_print(int arr[], int sz, const char *label);


typedef struct sc_sstore sc_sstore;

#define sc_sstore_t int

// storage that grows 2X each time. No individual deletion provided.
sc_sstore *sc_sstore_init(void);
void sc_sstore_push(sc_sstore *store, sc_sstore_t t);
void *sc_sstore_find(sc_sstore *store);
void sc_sstore_free(sc_sstore *store);

#endif /* SC_H */
