
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
//#include <mutex>
using namespace std;

const int JP = 10000;
const int NB_THREAD = 10;
void work(int index) {
    //start
}

void creatAndWait(int N){
    std::vector<std::thread> threads;
    for(int i = 0; i < N; ++i){
        threads.push_back(std::thread(work, i));
        std::cout << "created" << i << std::endl;
    }
    for(auto &t: threads){
        t.join();
        std::cout << "joined" << std::endl;
    }
}
/*
template <typename lockable>
class unique_lock{
    lockable& m;
public:
    unique_lock(lockable &m):m(m){
        m.lock();
    }
    ~unique_lock(){
        m.unlock();
    }
};*/

class Compte {
    int solde;
    mutable mutex m;
public :
    Compte(int solde = 0):solde(solde){
    }
    void crediter (size_t val) {
        unique_lock<mutex> l(m);
        solde += val;
        m.unlock();
    }
    int getSolde() const {
        unique_lock<mutex> l(m);
        return solde;
    }
    bool debiter (unsigned int val) {
        unique_lock<mutex> l(m);
        bool doit = (solde >= val);
        if (doit) {
            solde -= val ;
        }
        return doit;
    }
    void losepot(Compte & c) {
        for (int i=0; i < JP / 10; i++)
            c.debiter(10);
    }
};

void jackpot(Compte & c) {
    for (int i=0; i < JP; i++)
        c.crediter(1);
}


int main () {
    vector<thread> threads;
    // TODO : creer des threads qui font jackpot sur un compte
    for (auto & t : threads) {
        t.join();
    }
    // TODO : tester solde = NB_THREAD * JP
    Compte c;
    for(int i = 0; i < NB_THREAD; ++i){
        threads.emplace_back(jackpot, ref(c));
    }
    if(c.getSolde() != NB_THREAD*JP)
        cout << "problem" << endl;


    return 0;
}
