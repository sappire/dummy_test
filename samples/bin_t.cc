#include "bin_t.h"
#include <stack>

BT::BT()
    :root1_(NULL),
     root2_(NULL) {
// Empty as of now
}

BT::~BT() {
    root1_ = NULL;
    root2_ = NULL;
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
BT::create_tree1(void) {
    insert(&root1_, 20);
    insert(&root1_, 10);
    insert(&root1_, 30);
    insert(&root1_, 7);
    insert(&root1_, 3);
    insert(&root1_, 25);
}

void
BT::create_tree2(void) {
    insert(&root2_, 20);
    insert(&root2_, 10);
    insert(&root2_, 30);
    insert(&root2_, 40);
    insert(&root2_, 3);
}

int
BT::__size(const btnode_t * const node) {
    if(node == NULL) return 0;
    return __size(node->left) + __size(node->right) + 1;
}

int 
BT::size(void) {
    return __size(root1_);
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
    if (root1_ == NULL) return;
    stack<btnode_t *> s;
    btnode_t *curr = root1_;
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
 * to the stack. Once curr node is NULL, then pop the item and then make the 
 * right child of it as the current node.
 */
    if (root1_ == NULL) return;
    stack<btnode_t *> s;
    btnode_t *curr = root1_;
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
    if (root1_ == NULL) return;
    stack<btnode_t *> s;
    btnode_t *curr = root1_;
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
    return __height(root1_);
}

int
BT::__is_balanced_bt(const btnode_t *node) {
    if (node == NULL) return -1;

    int left_depth = __is_balanced_bt(node->left);
    if (left_depth == INT_MIN) return INT_MIN;
    int right_depth = __is_balanced_bt(node->right);
    if (right_depth == INT_MIN) return INT_MIN;
    int depth = abs(left_depth - right_depth);
    int max_child_depth = max(left_depth, right_depth);
    return (depth > 1 ? INT_MIN: max_child_depth + 1);
}

bool
BT::is_balanced_bt(void) {
    int val = __is_balanced_bt(root1_);
    return val != INT_MIN;
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
BT::has_pathsum_nodes(int sum) {
    vector<int> pathsum;
    unordered_map<int,vector<int> *> pathmap;
    int index = 0;
    int curr_sum = 0;
    __pathsum(root1_, pathsum, pathmap, index, curr_sum);
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

bool
BT::__has_pathsum(btnode_t *node, int carry_sum, const int &target, vector<int> &pathsum) {
    if (node == NULL) {
        if (carry_sum == target) return true;
        return false;
    }
    int curr_sum = node->value + carry_sum;
    pathsum.push_back(node->value);
    bool left = __has_pathsum(node->left, curr_sum, target, pathsum);
    if (left) return true;
    if (node->left != NULL) pathsum.pop_back();
    bool right = __has_pathsum(node->right, curr_sum, target, pathsum);
    if (right) return true;
    if (node->right != NULL) pathsum.pop_back();
    return false;
}

bool
BT::has_pathsum(int sum) {
    vector<int> pathsum;
    bool res = __has_pathsum(root1_, 0, sum, pathsum);
    cout << "{";
    for (int j=0; j < pathsum.size(); j++) {
        cout << pathsum[j] << " ";
    }
    cout << "}";
    return res;
}

void
BT::__mirror(btnode_t *node) {
    if (node == NULL) return;
    btnode_t *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    __mirror(node->left);
    __mirror(node->right);
}

void
BT::mirror(void) {
    __mirror(root1_);
}

void
BT::mirror_non_recursive(void) {
    btnode_t *curr = root1_;
    btnode_t *tmp = NULL;
    stack<btnode_t *> s;
    while((curr != NULL) || (!s.empty())) {
        if (curr != NULL) {
            tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;
            if (curr->right != NULL) {
                s.push(curr->right);
            }
            curr = curr->left;
            continue;
        }
        if (!s.empty()) {
            curr = s.top();
            s.pop();
        }
    }
}

void
BT::__duplicate_bt(btnode_t *node) {
    if (node == NULL) return;
    btnode_t *dup = NULL;
    __create_node(&dup, node->value);
    dup->left = node->left;
    node->left = dup;
    __duplicate_bt(dup->left);
    __duplicate_bt(node->right);
}

void
BT::duplicate_bt(void) {
    /* Need to make a duplicate of each node. Place the new node as the 
     * left child of current node. The resulting should also be BT. */
    return __duplicate_bt(root1_);
}

bool
BT::same_tree(btnode_t *a, btnode_t *b) {
    if ((a == NULL) && (b == NULL)) {
        return true;
    } else if ((a == NULL) || (b == NULL)) {
        return false;
    }
    return ((a->value == b->value) &&
            (same_tree(a->left , b->left)) && 
            (same_tree(a->right , b->right)));
}

void 
BT::__longest_consecutive_numbers_in_path(tnode_t *node, int &max_length, int curr_length) {
    if (node == NULL) return;
    for(int i=0; i < NUM_OF_CHILDREN; i++) {
        int curr_iteration_length = curr_length;
        if (node->children[i] != NULL) {
            if (node->children[i]->value == (node->value + 1)) {
                curr_iteration_length++;
                if(curr_iteration_length > max_length) {
                    max_length = curr_iteration_length;
                }
            } else {
                curr_iteration_length = 1;
            }
            __longest_consecutive_numbers_in_path(node->children[i], max_length, curr_iteration_length);
        }
    }
}

int
BT::longest_consecutive_numbers_in_path(tnode_t *node) {
    int max_length = 0;
    int curr_length = 0;
    if (node != NULL) {
        max_length = 1;
        curr_length = 1;
    }
    __longest_consecutive_numbers_in_path(node, max_length, curr_length);
    return max_length;
}

btnode_t *
BT::__leaf_of_tree(stack<btnode_t *> &s) {
    btnode_t *curr = NULL;
    while (!s.empty()) {
        curr = s.top();
        s.pop();
        if ((curr->left == NULL) && (curr->right == NULL)) {
            return curr;
        } else if (curr->right != NULL) {
            curr = curr->right;
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
        }
    }
    return NULL; 
}

std::pair<int,int> 
BT::return_non_matching_leaf_nodes(btnode_t *t1, btnode_t *t2) {
    stack<btnode_t *> s1;
    stack<btnode_t *> s2;
    btnode_t *curr1 = t1;
    btnode_t *curr2 = t2;
    while (curr1 != NULL) {
        s1.push(curr1);
        curr1 = curr1->left;
    }
    while (curr2 != NULL) {
        s2.push(curr2);
        curr2 = curr2->left;
    }
    btnode_t *leaf1 = __leaf_of_tree(s1);
    btnode_t *leaf2 = __leaf_of_tree(s2);
    while((leaf1 != NULL) && (leaf2 != NULL)) {
        if(leaf1->value != leaf2->value) return make_pair(leaf1->value,leaf2->value);
        leaf1 = __leaf_of_tree(s1);
        leaf2 = __leaf_of_tree(s2);
    }
    if ((leaf1 != NULL) && (leaf2 == NULL)) return make_pair(leaf1->value,0);
    if ((leaf1 == NULL) && (leaf2 != NULL)) return make_pair(0,leaf2->value);

    return make_pair(0,0);
}

void 
BT::__insert_columnwise(btnode_t *node, map<int,vector<int>*> &m, int key) {
    map<int,vector<int>*>::iterator it;
    if ((it = m.find(key)) == m.end()) {
        m.insert(pair<int, vector<int>*>(key, new vector<int>()));
//        map.emplace(key, new vector<int>());
    }
    m[key]->push_back(node->value);
}

void
BT::__populate_columnwise(btnode_t *root, map<int,vector<int>*> &m, int key) {
    if (root == NULL) return;
    __insert_columnwise(root, m, key);
    __populate_columnwise(root->left, m, key-1);
    __populate_columnwise(root->right, m, key+1);
}

void
BT::print_columnwise(btnode_t *root) {
    map<int,vector<int>*> m;
    int key = 0;
    __populate_columnwise(root, m, key);
    map<int,vector<int>*>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for(int i=0; i < it->second->size(); i++) {
            cout << (*it->second)[i];
            if (i+1 < it->second->size()) cout << ",";
        }
        cout << "--";
    }
}

//[20,10,30,5,25]
bool
BT::__is_validBST(btnode_t *root, int min, int max) {
    if (root == NULL) return true;
    if (!(root->value >= min && root->value < max)) return false;
    return __is_validBST(root->left, min, root->value) &&
           __is_validBST(root->right, root->value, max);
}

bool
BT::is_validBST(btnode_t *root) {
    if (root == NULL) return true;
    return __is_validBST(root->left, INT_MIN, root->value) &&
           __is_validBST(root->right, root->value, INT_MAX);
}

btnode_t*
BT::bst_to_ll(btnode_t *root) {
    btnode_t *head = NULL;
    btnode_t *prev = NULL;
    _bst_to_ll(root, &head, &prev);
    if(prev != head) {
        prev->right = head;
        head->left = prev;
    }
    return head;
}

void 
BT::_bst_to_ll(btnode_t *root, btnode_t **head, btnode_t **prev) {
    if(root == NULL) return;
    bst_to_ll(root->left, prev);
    if(*prev != NULL) (*prev)->right = root;
    root->left = *prev;
    *prev = root;
    _bst_to_ll(root->right, head, prev);
    if(*head == NULL) *head = root;
}

void
BT::cleanup_bt(btnode_t **node) {
    if (*node == NULL) return;

    cleanup_bt(&(*node)->left);
    cleanup_bt(&(*node)->right);
    delete *node;
    *node = NULL;
}

