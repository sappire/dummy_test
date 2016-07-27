#include <iostream>
#include <stdio.h>
#include <sys/types.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct btnode {
    int value;
    struct btnode *left;
    struct btnode *right;
} btnode_t;
