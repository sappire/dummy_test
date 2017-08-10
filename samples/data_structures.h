#include <iostream>
#include <stdio.h>
#include <sys/types.h>

#define NUM_OF_CHILDREN 2

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct btnode {
    int value;
    struct btnode *left;
    struct btnode *right;
} btnode_t;

typedef struct tnode {
    int value;
    struct tnode *children[NUM_OF_CHILDREN];
} tnode_t;

enum enabled_t{
    FALSE = 0,
    TRUE
};

static inline const char* 
status(enabled_t var) {
    return (var == FALSE)?"FALSE":"TRUE";
}

class TrieNode {
private:
    bool _is_word;
public:
    TrieNode *arr[26];
    TrieNode(bool is_word=false) {
        _is_word = is_word;
        for(int i=0; i < 26; i++) arr[i] = NULL;
    }
    void set_is_word(bool val) { _is_word = val; }
    bool is_word(void) { return _is_word; }
};

class Trie {
public:
    TrieNode& get_root(void) { return _root; }
private:
    TrieNode _root;
};
