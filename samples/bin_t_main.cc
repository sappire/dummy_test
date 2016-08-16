#include "bin_t.h"
using namespace std;

void bint_test1() {
    cout << "Started bint test : " << __func__ << endl;
    BT bt;
    bt.insert(&(bt.root_), 20); 
    bt.insert(&(bt.root_), 10); 
    bt.insert(&(bt.root_), 30); 
    bt.insert(&(bt.root_), 7); 
    bt.insert(&(bt.root_), 3); 
    cout << "INORDER_RECURSIVE: ";
    bt.print_inorder(bt.root_);
    cout << "\nINORDER_NON_RECURSIVE: ";
    bt.print_inorder_non_recursive();
    cout << "\nPREORDER_RECURSIVE: ";
    bt.print_preorder(bt.root_);
    cout << "\nPREORDER_NON_RECURSIVE: ";
    bt.print_preorder_non_recursive();
    cout << "\nPOSTORDER_RECURSIVE: ";
    bt.print_postorder(bt.root_);
    cout << "\nPOSTORDER_NON_RECURSIVE: ";
    bt.print_postorder_non_recursive();
    cout << "\nHEIGHT: " << bt.height();
    cout << "\nNUM OF NODES: " << bt.size();
    cout << "\nIS BT BALANCED? " << status((enabled_t)bt.is_balanced_bt());
    cout << "\nHAS PATH SUM 40? " << bt.has_pathsum(40);
    bt.mirror_non_recursive();
    cout << "\nINORDER after MIRROR NON RECURSIVE: ";
    bt.print_inorder_non_recursive();
    bt.mirror();
    cout << "\nINORDER after 2 times MIRROR RECURSIVE: ";
    bt.print_inorder_non_recursive();
    cout << endl;
    bt.cleanup_bt(&(bt.root_));
}

int main() {
    bint_test1();
    return 1;
}
