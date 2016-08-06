#include <iostream>
#include <pthread.h>

class Thrd {
public:
    typedef void *Thrd_func(void*);
//    Thrd(void *args, void *func(void*));
    Thrd(void *args, Thrd_func fun);
    void join();
    void exit();
private:
    pthread_t thrd_idx_;
};

