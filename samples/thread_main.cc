#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include "thread_t.h"

#define MAX_COUNT 5
int var = 0;
pthread_mutex_t mut;
pthread_cond_t cond;
using namespace std;


void *listen(void *args) {
    pthread_mutex_lock(&mut);
    while (var < MAX_COUNT) {
        cout << "thread id is " <<  pthread_self() << endl;
        cout << "Giving the mutex to publisher to increment the var. current: "
             << var << endl;
        pthread_cond_wait(&cond, &mut);
    }
    cout << "var is " << var << endl;
    pthread_mutex_unlock(&mut);
    pthread_exit(NULL);
}

void *publisher(void *args) {
    int i = 0;
    while (i < 7) {
        pthread_mutex_lock(&mut);
        var++;
        if (var == 5) {
//            cout << "thread tid is " << syscall(SYS_gettid) << endl;
            cout << "thread id is " <<  pthread_self() << endl;
            cout << "signaling the listener that var is 5" << endl;
            pthread_cond_signal(&cond);
            // This sleep is introduced because by the time the listener
            // prints the value of var after the publisher has signalled, the
            // publisher runs through couple of more iterations as listener is slow.
            sleep(1);
        }
        pthread_mutex_unlock(&mut);
        i++;
    }
    pthread_exit(NULL);
}

void ttest1() {
    cout << "Started thread test: " << __func__ << endl;
    pthread_t pub;
    pthread_t lis;
    pthread_attr_t attr;

    pthread_mutex_init(&mut, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    pthread_create(&lis, &attr, listen, NULL);
    pthread_create(&pub, &attr, publisher, NULL);

    pthread_join(lis, NULL);
    pthread_join(pub, NULL);

    pthread_mutex_destroy(&mut);
    pthread_cond_destroy(&cond);
    pthread_attr_destroy(&attr);

    pthread_exit(NULL);
}

class MyThread {
public:
    void *test_func(void *) {
        cout << "Thread id is " << pthread_self() << endl;
    }
    void run(){
        Thrd *internal_thrd = new Thrd((void *)NULL, this->test_func);
        internal_thrd->join();
        internal_thrd->exit();
    }
};

void ttest2() {
    cout << "Started thread test: " << __func__ << endl;
    MyThread thrd1;
    thrd1.run();
}

int main() {
    ttest1();
    ttest2();
    return 1;
}
