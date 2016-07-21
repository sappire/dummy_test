#include <iostream>
#include "ll.h"
#include "bm.h"

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

int
test5(void)
{
   /* bit mani */
   cout << "Started Test: " << __func__ << endl;
   uint32_t a[2] = {0,0};
   uint32_t *head[2];
   head[0] = &a[0];
   head[1] = &a[1];
   BM b;
   b.convert64_to_32(1,a);
   cout << "a[0]:" << a[0] << "and a[1]:" << a[1] << endl;
   return 1;
}

int main()
{
   test1();
   test2();
   test3();
   test4();
   test5();
   return 1;
} 
