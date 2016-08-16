#include "data_structures.h"
#include <vector>
#include <unordered_map>

using namespace std;

class BT {
public:
    BT();
    ~BT();
    void insert(btnode_t **node, int value);
    void print_inorder(const btnode_t *node);
    void print_inorder_non_recursive(void);
    void print_preorder(const btnode_t *node);
    void print_preorder_non_recursive(void);
    void print_postorder(const btnode_t *node);
    void print_postorder_non_recursive(void);
    void cleanup_bt(btnode_t **node);
    int height(void);
    int size(void);
    bool has_pathsum(int sum);
    void mirror(void);
    void mirror_non_recursive(void);
    bool is_balanced_bt(void); // depth diff between children should be atmost 1
    btnode_t *root_;
private:
    void __create_node(btnode_t **node, int value);
    int __height(const btnode_t *const node);
    int __size(const btnode_t * const node);
    bool __is_balanced_bt(const btnode_t *node); 
    void __pathsum(btnode_t *node, vector<int> &pathsum, unordered_map<int,vector<int> *> &pathmap,
                   int &index, int curr_sum);
    void __mirror(btnode_t *node);
};
