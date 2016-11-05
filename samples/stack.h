#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
    typedef struct elem {
        T obj;
        struct elem *next;
    }elem_t;

    Stack():head(NULL) { }

    int push(const T *obj) {
        elem_t *tmp = new elem_t();
        memcpy(&(tmp->obj), obj, sizeof(T));
        cout << "element pushed is " << tmp->obj << endl;
        tmp->next = head;
        head = tmp;
        return 0;
    }

    pair<int,T> pop(void) {
        T res;
        if(!head) {
            return make_pair(-1,res);
        }
        elem_t *tmp = head->next;
        memcpy(&res, &(head->obj), sizeof(T));
        delete head;
        head = tmp;
        return make_pair(0,res);
    }
private:
    elem_t *head; 
};

