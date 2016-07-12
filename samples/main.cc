#include <iostream>
#include "ll.h"

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

int main()
{
   test1();
   test2();
   test3();
   return 1;
} 
