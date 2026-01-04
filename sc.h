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

/**
 * Binary search for an element in a sorted array.
 *
 * @param arr    The sorted array to search (in ascending order)
 * @param begin  The starting index (inclusive)
 * @param end    The ending index (exclusive)
 * @param e      The element to find
 * @return       The index where the element is found, or -1 if not found
 *
 * Note: The array must be sorted in ascending order.
 *       The search range is [begin, end).
 */
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

/**
 * Initialize a new dynamic storage.
 *
 * @return  Pointer to the initialized storage, or NULL on allocation failure
 */
sc_sstore *sc_sstore_init(void);

/**
 * Push an element to the storage.
 *
 * @param store  The storage to push to
 * @param t      The element to push
 *
 * Note: If the storage is full (reached maximum capacity), the push is ignored.
 *       Silently fails on allocation errors.
 */
void sc_sstore_push(sc_sstore *store, sc_sstore_t t);

/**
 * Find an element in the storage (NOT IMPLEMENTED).
 *
 * @param store  The storage to search
 * @return       Currently always returns NULL (placeholder)
 *
 * TODO: Implement actual search functionality.
 */
void *sc_sstore_find(sc_sstore *store);

/**
 * Free the storage and all associated memory.
 *
 * @param store  The storage to free (safe to pass NULL)
 */
void sc_sstore_free(sc_sstore *store);

#endif /* SC_H */
