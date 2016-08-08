#include "thread_t.h"

pthread_mutex_t mut1;
pthread_cond_t cond1;

Thrd::Thrd(void *args, Thrd_func func) {
    int res = pthread_create(&thrd_idx_, NULL, func, args);
    if (res) {
        std::cout << "ERROR: Thread creation failed" << std::endl;
    }
}

void 
Thrd::join() {
    pthread_join(thrd_idx_, NULL);
}

