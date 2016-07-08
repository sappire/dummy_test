#include <iostream>
#include <stdio.h>
#include <sys/types.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;
