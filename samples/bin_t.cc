#include "bin_t.h"
#include <stack>

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

int
BT::__size(const btnode_t * const node) {
    if(node == NULL) return 0;
    return __size(node->left) + __size(node->right) + 1;
}

int 
BT::size(void) {
    return __size(root_);
}

void
BT::print_inorder(const btnode_t *node) {
    if (node == NULL) return;

    print_inorder(node->left);
    cout << node->value << " ";
    print_inorder(node->right);
}

void
BT::print_inorder_non_recursive(void) {
/* Navigate through all the left nodes and push them in to the stack. Once curr node is 
 * NULL, then pop the item, print it and then make the right child of it as the current node.
 */
    if (root_ == NULL) return;
    stack<btnode_t *> s;
    btnode_t *curr = root_;
    while ((curr != NULL) || (!s.empty())) {
        
        if (curr == NULL) {
            curr = s.top();
            s.pop();
            cout << curr->value << " ";
            curr = curr->right;
            continue;
        }
        s.push(curr);
        curr = curr->left; 
    }
}

void
BT::print_preorder(const btnode_t *node) {
    if (node == NULL) return;
    cout << node->value << " ";
    print_preorder(node->left);
    print_preorder(node->right);
}

void
BT::print_preorder_non_recursive(void) {
/* Print the current node and keep navigating through all the left nodes and push them in 
 * to the stack. Once curr node is NULL, then pop the item, print it and then make the 
 * right child of it as the current node.
 */
    if (root_ == NULL) return;
    stack<btnode_t *> s;
    btnode_t *curr = root_;
    while ((curr != NULL) || (!s.empty())) {
        if (curr == NULL) {
            curr = s.top();
            s.pop();
            curr = curr->right;
            continue;
        }
        cout << curr->value << " ";
        s.push(curr);
        curr = curr->left; 
    }
}

void
BT::print_postorder(const btnode_t *node) {
    if (node == NULL) return;

    print_postorder(node->left);
    print_postorder(node->right);
    cout << node->value << " ";
}

void
BT::print_postorder_non_recursive(void) {
/* 1. Push the current node and right child in to the stack and make current node point to the 
 * left child. 
 * 2. If curr is NULL, pop the item, make it current and check if the right child 
 * of the popped item is at the top of the stack. 
 *     a. If yes, then pop the top item and then push the current node first and then the right
 *        child and make current as right child. 
 *     b. If No, then print the current element and make curr = NULL;
 */
    if (root_ == NULL) return;
    stack<btnode_t *> s;
    btnode_t *curr = root_;
    btnode_t *tmp = NULL;
    while ((curr != NULL) || (!s.empty())) {
        if (curr != NULL) {
            if (curr->right != NULL) {
                s.push(curr);
                s.push(curr->right);
                curr = curr->left;
                continue;
            }
            s.push(curr);
            curr = curr->left;
            continue;
        }
        curr = s.top();
        s.pop();
        if (!s.empty() && (curr->right == s.top())) {
            tmp = s.top();
            s.pop();
            s.push(curr);
            curr = tmp;
            continue;
        }
        cout << curr->value << " ";
        curr = NULL;
    }
}

int
BT::__height(const btnode_t *const node) {
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
BT::__pathsum(btnode_t *node, vector<int> &pathsum, unordered_map<int,vector<int> *> &pathmap, 
              int &index, int curr_sum) {
    if (node == NULL) return;
    if (pathsum.size() < (index + 1)) {
        pathsum.push_back((curr_sum + node->value));
        pathmap.insert(pair<int,vector<int> *>(index, new vector<int>()));
    } else {
        pathsum[index] += node->value;
    }
    curr_sum = pathsum[index];
    pathmap[index]->push_back(node->value);
    __pathsum(node->left, pathsum, pathmap, index, curr_sum);
    __pathsum(node->right, pathsum, pathmap, ++index, curr_sum);
}

bool
BT::has_pathsum(int sum) {
    vector<int> pathsum;
    unordered_map<int,vector<int> *> pathmap;
    int index = 0;
    int curr_sum = 0;
    __pathsum(root_, pathsum, pathmap, index, curr_sum);
    for (int i=0; i < pathsum.size(); i++) {
        if (pathsum[i] == sum) {
            vector<int> &ref = (*pathmap[i]);
            cout << "{";
            for (int j=0; j < ref.size(); j++) {
                cout << ref[j] << " ";
            }
            cout << "}, ";
            return true;
        }
    }

    if (pathmap.size() > 0) {
        unordered_map<int, vector<int> *>::iterator it;
        for (it = pathmap.begin(); it != pathmap.end(); ++it) {
            delete it->second;
        }
    }
    return false;
}

void
BT::cleanup_bt(btnode_t **node) {
    if (*node == NULL) return;

    cleanup_bt(&(*node)->left);
    cleanup_bt(&(*node)->right);
    delete *node;
    *node = NULL;
}
