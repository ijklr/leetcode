#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/
typedef struct Trie {
    struct Trie* children[26];
    char c;
    u_int8_t is_word;
} Trie;

/* Returns an initialized Trie */
Trie* trieCreate() { return calloc(1, sizeof(Trie)); }

void trieInsert(Trie* obj, char* word) {}

bool trieSearch(Trie* obj, char* word) { return true; }

bool trieStartsWith(Trie* obj, char* prefix) { return true; }

void trieFree(Trie* obj) {}

int main() {
    printf("0208 implement trie!\n");
    return 0;
}
