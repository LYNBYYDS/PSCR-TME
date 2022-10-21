#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

#include <cstdlib>
#include <mutex>

namespace pr {

// MT safe version of the Queue, non blocking.
template <typename T>
class Queue {
	T ** tab;
	const size_t allocsize;
	size_t begin;
	size_t sz;
	mutable std::mutex m;
    std::condition_variable cv;
    bool block;

	// fonctions private, sans protection mutex
	bool empty() const {
		return sz == 0;
	}
	bool full() const {
		return sz == allocsize;
	}
public:
	Queue(size_t size) :allocsize(size), begin(0), sz(0), block(true) {
		tab = new T*[size];
		memset(tab, 0, size * sizeof(T*));
	}
	size_t size() const {
		std::unique_lock<std::mutex> lg(m);
		return sz;
	}
    setBlocking(){
        block = true;
    }
	T* pop() {
		std::unique_lock<std::mutex> lg(m);
		while (empty() && block) {
			cv.wait(lg);
            //return nullptr;
		}
        if (empty() && !block){
            return nullptr;
        }
        cv.notify_all();
		auto ret = tab[begin];
		tab[begin] = nullptr;
		sz--;
		begin = (begin + 1) % allocsize;
		return ret;
	}
	bool push(T* elt) {
		std::unique_lock<std::mutex> lg(m);
		while (full() && block) {
			cv.wait(lg);
            //return false;
		}
        if(full() && !block){
            return false;
        }
        cv.notify_all();
		tab[(begin + sz) % allocsize] = elt;
		sz++;
		return true;
	}
	~Queue() {
		// ?? lock a priori inutile, ne pas detruire si on travaille encore avec
		for (size_t i = 0; i < sz; i++) {
			auto ind = (begin + i) % allocsize;
			delete tab[ind];
		}
		delete[] tab;
	}
};

}

#endif /* SRC_QUEUE_H_ */
