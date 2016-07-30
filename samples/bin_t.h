#include "data_structures.h"

class BT {
public:
    BT();
    ~BT();
    void insert(btnode_t **node, int value);
    void print_inorder(const btnode_t *node);
    void print_inorder_non_recursive(void);
    void print_preorder(const btnode_t *node);
    void print_postorder(const btnode_t *node);
    void cleanup_bt(btnode_t **node);
    int height(void);
    bool is_balanced_bt(void); // depth diff between children should be atmost 1
    btnode_t *root_;
private:
    void __create_node(btnode_t **node, int value);
    int __height(const btnode_t *node);
    bool __is_balanced_bt(const btnode_t *node); 
};
