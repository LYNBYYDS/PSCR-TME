#pragma once

#include "Queue.h"
#include "Job.h"
#include <vector>
#include <thread>

namespace pr {

class Pool {
	Queue<Job> queue;
	std::vector<std::thread> threads;
public:
	Pool(int qsize){
        queue = new Queue<Job>(qsize);

    }
    void poolWorker(Queue<Job> & queue){
        while(ture){
            Job* j = queue.pop();
            if(j == nullptr)
                break;
            j->run();
            delete j;
        }
    }
	void start (int nbthread){
        for(size_t i = 0; i < nbthread; ++i){
            threads.emplace_back()
        }
    }
	void submit (Job * job){
        queue.push(job);
    }
	void stop(){
        queue.setBlocking();
    }
	~Pool(){
        delete queue;
        delete []threads;
    }
    /*
    void poolWorker(Queue<Job> & queue){
        while(ture){
            Job* j = queue.pop();
            if(j == nullptr)
                break;
            j->run();
            delete j;
        }
    }
    void stop(){

    }
    void start(){}

     */
};

}
