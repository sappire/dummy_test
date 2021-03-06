#include <iostream>
#include "ll.h"
#include "bm.h"
#include "list.h"
using namespace std;

int
test1(void)
{
   /* Delete dups */
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   node_t *start = ll1.create_ll_with_duplicates();
   ll1.print_ll(start);
   ll1.delete_duplicates_ll(&start);
   ll1.print_ll(start);
   ll1.delete_ll(&start);
   return 1;
}

int
test2(void)
{
   /* Reverse*/
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   node_t *start = ll1.create_ll_with_duplicates();
   ll1.print_ll(start);
   ll1.delete_duplicates_ll(&start);
   ll1.print_ll(start);
   ll1.reverse_ll(&start, NULL);
   ll1.print_ll(start);
   ll1.delete_ll(&start);
   return 1;
}

int
test3(void)
{
   /* palin */
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   node_t *start = ll1.create_ll_with_duplicates();
   ll1.print_ll(start);
   ll1.delete_duplicates_ll(&start);
   ll1.print_ll(start);
   ll1.is_palindrome(&start)? cout << "is a Palindrome\n":cout <<"Not a palindrome\n";
   ll1.delete_ll(&start);
   return 1;
}

int
test4(void)
{
   /* palin */
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   node_t *start = ll1.create_ll_palin();
   ll1.print_ll(start);
   ll1.is_palindrome(&start)? cout << "is a Palindrome\n":cout <<"Not a palindrome\n";
   ll1.delete_ll(&start);
   return 1;
}

void test5(void)
{
    /* Size of a structure */
    cout << "Started Test: " << __func__ << endl;
    btnode_t a[2];
    uint8_t *a_,*b_;
    a_ = (uint8_t*)&a[0];
    b_ = (uint8_t*)&a[1];
    cout << "Size of btnode_t is " << (b_ - a_) << endl;

    typedef struct sample1 {
        int h;
        char a;
        char b;
        void *x;
    } __attribute__ ((packed)) sample1_t;

    typedef struct sample2 {
        int h;
        char a;
        char b;
        void *x;
    } sample2_t;

    cout << "size of sample struct with packing is "<< sizeof(sample1_t) << endl;
    cout << "size of sample struct without packing but gets padded is "<< sizeof(sample2_t) << endl;
}

void test6(void)
{
    typedef struct sample3 {
        int h;
        char a;
        char b;
        void *x;
    } __attribute__ ((aligned(64))) sample3_t;

    cout << "size of cache aligned structure is "<< sizeof(sample3_t) << endl;
}

void test7(void)
{
   /* Delete target value */
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   node_t *start = ll1.create_ll_with_duplicates();
   ll1.print_ll(start);
   ll1.delete_target_nodes_with_value(&start, 10);
   ll1.print_ll(start);
   ll1.delete_ll(&start);
}

void test8(void)
{
   /* Delete target value */
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   //Even
   node_t *start = ll1.create_ll_even();
   ll1.print_ll(start);
   cout << "mid of ll is " << ll1.mid_ll(&start) << endl;
   ll1.delete_ll(&start);
   //Odd
   start = ll1.create_ll_odd();
   ll1.print_ll(start);
   cout << "mid of ll is " << ll1.mid_ll(&start) << endl;
   ll1.delete_ll(&start);
}

void test9()
{
    cout << "Test List class" << endl;
    List<int> L;
    int val = 11;
    L.push(val);
    val = 21;
    L.push(val);
    val = 31;
    L.push(val);
    auto head = L.head();
    cout << head;
}

void test10(void)
{
   /* Delete target value */
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   //Even
   node_t *start = ll1.create_ll_even();
   ll1.print_ll(start);
   int i=0;
   for(node_t *tmp = start; tmp != NULL; tmp = tmp->next) {
       i++;
       if (i==2) {
            ll1.delete_specific_node(tmp);
            break;
       }
   }
   ll1.print_ll(start);
}

void test11(void)
{
   /* Reorder list as mentioned in cc file */
   cout << "Started Test: " << __func__ << endl;
   ll ll1;
   node_t *start1 = ll1.create_ll_even();
   node_t *start2 = ll1.create_ll_odd();

   cout << "====Even: ";
   ll1.print_ll(start1);
   ll1.reorder_list(&start1);
   ll1.print_ll(start1);
   ll1.delete_ll(&start1);
   cout << "====Odd: ";
   ll1.print_ll(start2);
   ll1.reorder_list(&start2);
   ll1.print_ll(start2);
   ll1.delete_ll(&start2);
}

int main()
{
   test1();
   test2();
   test3();
   test4();
   test5();
   test6();
   test7();
   test8();
   test9();
   test10();
   test11();
   return 1;
} 
