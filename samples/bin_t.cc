#include "bin_t.h"
using namespace std;

BT::BT()
    :root_(NULL) {
// Empty as of now
}

BT::~BT() {
    root_ = NULL;
}

void
BT::__create_node(btnode_t **node, int value) {
    *node = new btnode_t();
    (*node)->value = value;
    (*node)->left = NULL;
    (*node)->right = NULL;
}

void
BT::insert(btnode_t **node, int value) {
    if (*node == NULL) {
        __create_node(node, value);
        return;
    }

    if (value <= (*node)->value) {
        insert(&(*node)->left, value);
        return;
    }
    insert(&(*node)->right, value);
}

void
BT::print_inorder(const btnode_t *node) {
    if (node == NULL) return;

    print_inorder(node->left);
    cout << node->value << " ";
    print_inorder(node->right);
}

void
BT::print_preorder(const btnode_t *node) {
    if (node == NULL) return;
    cout << node->value << " ";
    print_preorder(node->left);
    print_preorder(node->right);
}

void
BT::print_postorder(const btnode_t *node) {
    if (node == NULL) return;

    print_postorder(node->left);
    print_postorder(node->right);
    cout << node->value << " ";
}

int
BT::__height(const btnode_t *node) {
    if (node == NULL) return -1;

    return max(__height(node->left), __height(node->right)) + 1;
}

int 
BT::height(void) {
    return __height(root_);
}

bool
BT::__is_balanced_bt(const btnode_t *node) {
    if (node == NULL) return true;

    int depth = abs(__height(node->left) - __height(node->right));
    if ((depth <= 1) &&
       __is_balanced_bt(node->left) && 
       __is_balanced_bt(node->right)) return true;
    return false;
}

bool
BT::is_balanced_bt(void) {
    return __is_balanced_bt(root_);
}

void
BT::cleanup_bt(btnode_t **node) {
    if (*node == NULL) return;

    cleanup_bt(&(*node)->left);
    cleanup_bt(&(*node)->right);
    delete *node;
    *node = NULL;
}
