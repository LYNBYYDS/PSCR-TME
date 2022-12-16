//
// Created by yongli on 21/10/2022.
//

#ifndef TP5_POOL_HPP
#define TP5_POOL_HPP
#include "Jop.hpp"
class Pool {
    Queue<Job> queue;
    std::vector<std::thread> threads;
public:
    Pool(int qsize) ;
    void start (int nbthread);
    void submit (Job * job) ;
    void stop() ;
    ~Pool() ;
    void poolWorker(Queue<Job> & queue){
        while(ture){
            Job* j = queue.pop();
            if(j == nullptr)
                break;
            j->run();
            delete j;
        }
    }
    void stop(){}
    void start(){}
};

#endif //TP5_POOL_HPP
