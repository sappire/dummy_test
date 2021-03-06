#include "data_structures.h"
#include <vector>
#include <unordered_map>
#include <stack>
#include <map>

using namespace std;

class BT {
public:
    BT();
    ~BT();
    void insert(btnode_t **node, int value);
    void create_tree1(void);
    void create_tree2(void);
    void print_inorder(const btnode_t *node);
    void print_inorder_non_recursive(void);
    void print_preorder(const btnode_t *node);
    void print_preorder_non_recursive(void);
    void print_postorder(const btnode_t *node);
    void print_postorder_non_recursive(void);
    void cleanup_bt(btnode_t **node);
    int height(void);
    int size(void);
    bool has_pathsum_nodes(int sum);
    bool has_pathsum(int sum);
    void mirror(void);
    void mirror_non_recursive(void);
    void duplicate_bt(void);
    bool is_balanced_bt(void); // depth diff between children should be atmost 1
    bool same_tree(btnode_t *a, btnode_t *b);
    int longest_consecutive_numbers_in_path(tnode_t *node);
    std::pair<int,int> return_non_matching_leaf_nodes(btnode_t *t1, btnode_t *t2);
    void print_columnwise(btnode_t *root);
    bool is_validBST(btnode_t *root);
    btnode_t* bst_to_ll(btnode_t *root);
    btnode_t *root1_;
    btnode_t *root2_;
    tnode_t *troot1_;
private:
    void __create_node(btnode_t **node, int value);
    int __height(const btnode_t *const node);
    int __size(const btnode_t * const node);
    int __is_balanced_bt(const btnode_t *node);
    void __pathsum(btnode_t *node, vector<int> &pathsum, unordered_map<int,vector<int> *> &pathmap,
                   int &index, int curr_sum);
    bool __has_pathsum(btnode_t *node, int carry_sum, const int &target, vector<int>& pathsum);
    void __mirror(btnode_t *node);
    void __duplicate_bt(btnode_t *node);
    void __longest_consecutive_numbers_in_path(tnode_t *node, int &max_length, 
                                               int curr_length);
    btnode_t *__leaf_of_tree(stack<btnode_t *> &s);
    void __populate_columnwise(btnode_t *root, map<int,vector<int>*> &m, int key);
    void __insert_columnwise(btnode_t *node, map<int,vector<int>*> &m, int key);
    bool __is_validBST(btnode_t *root, int min, int max);
    void _bst_to_ll(btnode_t *root, btnode_t **head, btnode_t **prev);
};
