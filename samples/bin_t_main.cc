#include "bin_t.h"
using namespace std;

void bint_test1() {
    cout << "Started bint test : " << __func__ << endl;
    BT bt;
    bt.create_tree1();
    bt.create_tree2();

    /* Non Modifying Trees */
    cout << "INORDER_RECURSIVE: ";
    bt.print_inorder(bt.root1_);
    cout << "\nINORDER_NON_RECURSIVE: ";
    bt.print_inorder_non_recursive();
    cout << "\nPREORDER_RECURSIVE: ";
    bt.print_preorder(bt.root1_);
    cout << "\nPREORDER_NON_RECURSIVE: ";
    bt.print_preorder_non_recursive();
    cout << "\nPOSTORDER_RECURSIVE: ";
    bt.print_postorder(bt.root1_);
    cout << "\nPOSTORDER_NON_RECURSIVE: ";
    bt.print_postorder_non_recursive();
    cout << "\nHEIGHT: " << bt.height();
    cout << "\nNUM OF NODES: " << bt.size();
    cout << "\nIS BT BALANCED? " << status((enabled_t)bt.is_balanced_bt());
    cout << "\nHAS PATH SUM 40? " << status((enabled_t)bt.has_pathsum(40));
    cout << "\nINORDER_2ND TREE: ";
    bt.print_inorder(bt.root2_);
    cout << "\nTREES 1 & 2 are same ?" << status((enabled_t)bt.same_tree(bt.root1_, bt.root2_));
    pair<int,int> res = bt.return_non_matching_leaf_nodes(bt.root1_, bt.root2_);
    cout << "\nNON MATCHING LEAVES OF TWO TREES:" << res.first << "," << res.second;
    cout << "\nCOLUMN WISE PRINTING OF TREE 1: ";
    bt.print_columnwise(bt.root1_);

    /* Modifying Trees */
    bt.mirror_non_recursive();
    cout << "\nINORDER after MIRROR NON RECURSIVE: ";
    bt.print_inorder_non_recursive();
    bt.mirror();
    cout << "\nINORDER after 2 times MIRROR RECURSIVE: ";
    bt.print_inorder_non_recursive();
    bt.duplicate_bt();
    cout << "\nINORDER after DUPLICATION: ";
    bt.print_inorder_non_recursive();
    cout << endl;
    bt.cleanup_bt(&(bt.root1_));
    bt.cleanup_bt(&(bt.root2_));
}

int main() {
    bint_test1();
    return 1;
}
