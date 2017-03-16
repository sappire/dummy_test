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
