#include <iostream>
#include <pthread.h>

extern pthread_mutex_t mut1;
extern pthread_cond_t cond1;

class Thrd {
public:
    typedef void * (*Thrd_func)(void*);
//    Thrd(void *args, void *func(void*));
    Thrd(void *args, Thrd_func fun);
    void join();
private:
    pthread_t thrd_idx_;
};
