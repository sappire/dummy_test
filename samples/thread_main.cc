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
    cout << "---------------------------------------------------------" << endl;
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

//    pthread_exit(NULL);
}

typedef void* (*fptr)(void*);
typedef void (*pptr)(void);

void prod(void) {
    for(int i=0; i < 3; i++) {
        pthread_mutex_lock(&mut);
        cout << "i is " << i << " and thread id for prod is " << pthread_self() << endl;
        while(var == 1) {
            cout << "in while i is " << i << " and thread id for prod is " << pthread_self() << endl;
            pthread_cond_wait(&cond, &mut);
        }
        var = 1;
        pthread_mutex_unlock(&mut);
        pthread_cond_signal(&cond);
    }
    cout << "producer thread exiting" << endl;
//    return NULL;
}

void* cons(void*) {
    for(int i = 0; i < 3; i++) { 
         pthread_mutex_lock(&mut);
         cout << "i is " << i << " and thread id for cons is " << pthread_self() << endl;
         while (var == 0) {
             cout << "in while i is " << i << " and thread id for cons is " << pthread_self() << endl;
             pthread_cond_wait(&cond, &mut);
         }
         var = 0;
         pthread_mutex_unlock(&mut);
         pthread_cond_signal(&cond);
    }
    cout << "consumer thread exiting" << endl;
    return NULL;
}

void* g_fptr(void *arg) {
    pptr p = (pptr)arg;
    p();
    return NULL;
}

void ttest3(void) {
    cout << "Started test: " << __func__ << endl;
    pthread_t tid[2];
    pthread_mutex_init(&mut, NULL);
    pthread_cond_init(&cond, NULL);
    
    fptr prod_func = &g_fptr;
    fptr cons_func = &cons;
    pthread_create(&tid[0], NULL, prod_func, (void*)&prod);
    pthread_create(&tid[1], NULL, cons_func, NULL);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&mut);
    pthread_cond_destroy(&cond);
}

class MyThread {
public:
    MyThread():count_(0){;}
    void func(void) {
        cout << "Child Thread id is " << pthread_self() << endl;
        pthread_mutex_lock(&mut1);
        count_++;
        pthread_cond_signal(&cond1);
        pthread_mutex_unlock(&mut1);
    }
    void run(){
        cout << "Parent Thread id is " << pthread_self() << endl;
        pthread_mutex_lock(&mut1);
        Thrd *internal_thrd = new Thrd(this, MyThread::fptr);
        pthread_cond_wait(&cond1, &mut1);
        pthread_mutex_unlock(&mut1);
        internal_thrd->join();
        cout << "Parent read value of count is " << count_ << endl;
    }

    static void *fptr(void *arg) {
        ((MyThread*)arg)->func();
        cout << "End of test function execution by Child" << endl;
        pthread_exit(NULL);
        return NULL;
    }

    static void init() {
        pthread_mutex_init(&mut1, NULL);
        pthread_cond_init(&cond1, NULL);
    }
    static void exit() {
        pthread_mutex_destroy(&mut1);
        pthread_cond_destroy(&cond1);
        pthread_exit(NULL);
    }
    int count_;
};

void ttest2() {
    cout << "---------------------------------------------------------" << endl;
    cout << "Started thread test: " << __func__ << endl;
    MyThread::init();
    MyThread thrd1;
    thrd1.run();
    MyThread::exit();
}

int main() {
    //ttest1();
    //ttest2();
    ttest3();
    return 1;
}
