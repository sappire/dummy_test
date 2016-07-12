#include <iostream>
#include <stdlib.h>
#include "ll.h"
#include <thread>

using namespace std;

node_t* 
ll::alloc_node(node_t **start, int value)
{
    node_t *n = static_cast<node_t*>(malloc(sizeof(node_t)));
    if (n == NULL)
        return n;
    n->value = value;
    n->next = NULL;

    if (*start == NULL) {
        *start = n;
    } else {
        (*start)->next = n;
    }
    return n;
}

node_t* 
ll::create_ll_with_duplicates(void)
{
    node_t *head = NULL;
    node_t *tmp = NULL;
    tmp = alloc_node(&head, 1);
    tmp = alloc_node(&tmp, 3);
    tmp = alloc_node(&tmp, 1);
    tmp = alloc_node(&tmp, 2);
    tmp = alloc_node(&tmp, 1);
    tmp = alloc_node(&tmp, 4);
    return head;
}

void 
ll::print_ll(const node_t * const head)
{
    const node_t *node = head;
    for (; node != NULL; node=node->next)
    {
        cout << node->value;
        if (node->next != NULL) 
            cout << " -> ";
    }
    cout << endl;
}

void 
ll::delete_duplicates_ll(node_t **head)
{
    if (*head == NULL)
        return;
    node_t *curr = *head;
    node_t *prev = NULL;
    while (curr) {
        prev = curr;
        node_t *next = curr->next;
        while(next) {
            if(curr->value == next->value) {
                node_t *tmp = next->next;
                prev->next = tmp;
                free(next);
                next = prev->next;
            } else {
                prev = next;
                next = next->next;
            }
        }
        curr = curr->next;
    }
}

void 
ll::delete_ll(node_t **head)
{
    node_t *node = *head;
    for (; node != NULL;)
    {
        node_t *tmp = node;
        node = node->next;
        free(tmp);
    }
}

size_t
ll::size(node_t **head)
{
    if (!head) 
        return 0;

    size_t i = 0;
    node_t *curr = *head;
    for (; curr != NULL; curr=curr->next)
    {
        i++;
    }
    cout << "size is " << i << endl;
    return i;
}

void
ll::reverse_ll(node_t **head, node_t *previous)
{
    if (size(head) < 2) return;

    node_t *curr = *head;
    node_t *prev = previous;
    while (curr->next != NULL) {
        node_t *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    curr->next = prev;
    *head = curr;
}

bool 
ll::is_palindrome(node_t **head)
{
    node_t *ptr1 = *head;
    node_t *ptr2 = *head;
    node_t *mid = *head;
    bool palin = false;
    for(; ptr2 != NULL; ptr1 = ptr1->next, ptr2 = ptr1->next->next)
    {
       mid = ptr1;
    }
    mid->next = NULL;
    reverse_ll(&ptr1,NULL);
    print_ll(ptr1);
    palin = __is_palindrome(head, &ptr1);
    reverse_ll(&ptr1,NULL);
    mid->next = ptr1;
    print_ll(*head);
    return palin; 
}

bool
ll::__is_palindrome(node_t **head1, node_t **head2)
{
    node_t *cur1 = *head1;
    node_t *cur2 = *head2;
    while(cur1 != NULL && cur2 != NULL) {
        if (cur1->value != cur2->value) {
            return false;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    if ((cur1 == NULL) && (cur2 == NULL)) {
        return true;
    } else if ((cur1 == NULL) && (cur2->next == NULL)) {
        return true;
    } else if ((cur2 == NULL) && (cur1->next == NULL)) {
        return true;
    }

    return false;
}
    

/*
int main()
{
   ll ll1;
   node_t *start = ll1.create_ll_with_duplicates(); 
   ll1.print_ll(start);
   ll1.size(&start);
   ll1.delete_duplicates_ll(&start);
   ll1.print_ll(start);
   ll1.size(&start);
   ll1.delete_ll(&start);
   return 1;
}*/
