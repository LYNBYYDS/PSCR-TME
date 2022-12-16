//
// Created by yongli on 21/10/2022.
//


#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_
#include <string> //size_t
#include <iostream>
template <typename T>class Queue {

    mutable std::mutex mut;
    std::condition_variable cv;
    T ** tab;
    const size_t allocsize;
    size_t begin;
    size_t sz;
    bool full(){
        return sz == allocsize;
    }
    bool empty(){
        return sz == 0;
    }
public :
    Queue (size_t maxsize) :allocsize(maxsize),begin(0),sz(0) {
        tab = new T* [maxsize];
        memset(tab, 0, maxsize * sizeof(T*));
        }
    size_t size() const {
        std::unique_lock<mutex> l(mut);
        return sz;
    }
    T* pop () {
        std::unique_lock<mutex> l(mut);
        while(empty()){
            cv.wait(l);
            // return nullptr;
        }
        cv.notify_all();
        T *ret = tab[begin];
        tab[begin] = nullptr;
        sz--;
        begin = (begin + 1) % allocsize;
        return ret;
    }
    void push (T* elt) {
        std::unique_lock<mutex> l(mut);
        while (full()) {
            cv.wait(l);
            // return false;
        }
        cv.notify_all();
        tab[(begin + sz) % allocsize] = elt;
        sz++;
    }
    ~Queue() {
        for (size_t i = 0; i < sz ; i++) {
            33 size_t ind = (begin + i) % allocsize;
            delete tab[ind];
            }
        delete[] tab;
    }
    };

#endif /* SRC_QUEUE_H_ */

// cv. wait(l,[&](){return ! text})
// == while(text){cv.wait(l)}
