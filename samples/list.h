#include<iostream>

template<typename T>
class List {
private:
    typedef struct node {
        T val;
        struct node* next;
        node(T v){val = v; next = NULL;}
    }node_t;
    node_t* head_;
    node_t* tail_;
public:
    List():head_(NULL),tail_(NULL) {}
    void push(T val) {
        node_t *n1 = new node_t(val);
        if(tail_ != NULL) {
            tail_->next = n1;
            tail_ = n1;
        } else {
            tail_ = n1;
        }
        if(head_ == NULL) {
            head_ = n1;
        }
    }
    node_t* head(void) {return head_;}
    friend std::ostream& operator<<(std::ostream& os, const node_t *n) {
        if (n != NULL) {
            os << n->val;
        }
        return os;
    }
    ~List() {
        node_t *tmp = NULL;
        while(head_ != NULL) {
           tmp = head_->next;
           delete head_;
           head_ = tmp; 
        }
    }
};
