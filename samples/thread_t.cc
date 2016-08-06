#include "thread_t.h"

Thrd::Thrd(void *args, Thrd_func func) {
    int res = pthread_create(&thrd_idx_, NULL, func, NULL);
    if (res) {
        std::cout << "ERROR: Thread creation failed" << std::endl;
    }
}

void 
Thrd::join() {
    pthread_join(thrd_idx_, NULL);
}

void 
Thrd::exit() {
    pthread_exit(NULL);
}
