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
    cout << "\nPREORDER: ";
    bt.print_preorder(bt.root_);
    cout << "\nPOSTORDER: ";
    bt.print_postorder(bt.root_);
    cout << "\nHEIGHT: " << bt.height();
    cout << "\nIS BT BALANCED: " << bt.is_balanced_bt();
    bt.cleanup_bt(&(bt.root_));
}

int main() {
    bint_test1();
    return 1;
}
