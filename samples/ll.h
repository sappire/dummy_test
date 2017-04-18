#pragma once
#include "data_structures.h"

class ll {
public:
    ll(void) { }
    node_t* create_ll_even(void);
    node_t* create_ll_odd(void);
    node_t* create_ll_with_duplicates(void);
    node_t* create_ll_palin(void);
    void print_ll(const node_t * const head);
    void delete_duplicates_ll(node_t **head);
    void reverse_ll(node_t **head, node_t *previous);
    void delete_ll(node_t **head);
    void delete_target_nodes_with_value(node_t **head, int target);
    void delete_specific_node(node_t *node); //but not tail
    bool is_palindrome(node_t **head);
    size_t size(node_t **head);
    int mid_ll(node_t **head);
private:
    node_t* alloc_node(node_t **start, int value);
    bool __is_palindrome(node_t **head1, node_t **head2);
};
