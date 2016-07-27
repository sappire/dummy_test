#include "data_structures.h"

class BT {
public:
    BT();
    ~BT();
    void insert(btnode_t **node, int value);
    void print_inorder(const btnode_t *node);
    void print_preorder(const btnode_t *node);
    void print_postorder(const btnode_t *node);
    void cleanup_bt(btnode_t **node);
    int height(void);
    btnode_t *root_;
private:
    void __create_node(btnode_t **node, int value);
    int __height(const btnode_t *node);
};
