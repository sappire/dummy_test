#pragma once
#include "data_structures.h"

class ll {
public:
    ll(void) { }
    node_t* create_ll_with_duplicates(void);
    node_t* create_ll_palin(void);
    void print_ll(const node_t * const head);
    void delete_duplicates_ll(node_t **head);
    void reverse_ll(node_t **head, node_t *previous);
    void delete_ll(node_t **head);
    bool is_palindrome(node_t **head);
    bool __is_palindrome(node_t **head1, node_t **head2);
    size_t size(node_t **head);
private:
    node_t* alloc_node(node_t **start, int value);
};
