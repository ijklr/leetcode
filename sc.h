// Make the elements in arr unique. Returns the resulting size.
int sc_uniq(int* arr, int sz);

// Binary search since arr is sorted in ascending order already.
// Returns the index that the matchig element resides.
// The search includes begin index but not the end index.
// if not found, returns -1;
int sc_find(int arr[], int begin, int end, int e);

// print the array
void sc_print(int arr[], int sz, const char* label);


typedef struct sc_sstore sc_store;

#define sc_sstore_t int

// storage that grows 2X each time. No individual deletion provided.
sc_sstore* sc_sstore_init();
void sc_sstore_push(sc_sstore* store, sc_sstore_t t);
void* sc_sstore_find(sc_sstore* store);
void sc_sstore_free(sc_sstore* store);
