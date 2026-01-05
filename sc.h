/**
 * SC.H - Utility functions for LeetCode solutions
 *
 * Provides common operations including:
 * - Array manipulation (unique elements, binary search, printing)
 * - Dynamic storage with exponential growth
 */

#ifndef SC_H
#define SC_H

/* ========================================================================
 * Array Utilities
 * ======================================================================== */

/**
 * Make the elements in an array unique by sorting and removing duplicates.
 *
 * @param arr  The array to process (will be modified in-place)
 * @param sz   The size of the array
 * @return     The resulting size after removing duplicates
 *
 * Note: The array will be sorted in ascending order after this operation.
 */
int sc_uniq(int *arr, int sz);

// Binary search since `arr` is sorted in ascending order already.
// Returns the index where the matching element resides.
// The search includes `begin` but excludes `end`.
// Returns -1 if not found or if arr is NULL.
int sc_find(const int arr[], int begin, int end, int e);

/**
 * Print an array with a label.
 *
 * @param arr    The array to print
 * @param sz     The size of the array
 * @param label  A label to print before the array elements
 *
 * Output format: "label: elem1 elem2 elem3 ... elemN\n"
 */
void sc_print(const int arr[], int sz, const char *label);

/* ========================================================================
 * Dynamic Storage (sc_sstore)
 * ======================================================================== */

/**
 * Opaque structure for dynamic storage that grows exponentially.
 * - Initial capacity: 1024 elements
 * - Growth strategy: 2X on each expansion
 * - Maximum capacity: ~2M elements (16 storage blocks)
 */
typedef struct sc_sstore sc_sstore;

/**
 * Type of elements stored in sc_sstore.
 * Currently defined as int, can be changed as needed.
 */
#define sc_sstore_t int

// storage that grows 2X each time. No individual deletion provided.
// Initial capacity: 1024, max chunks: 16 (total ~33.5M elements)
sc_sstore *sc_sstore_init(void);

// Push an element to the storage.
// Returns 0 on success, -1 on failure (NULL pointer, capacity limit, or allocation error).
int sc_sstore_push(sc_sstore *store, sc_sstore_t t);

// Free all storage and the store itself.
void sc_sstore_free(sc_sstore *store);

#endif /* SC_H */
