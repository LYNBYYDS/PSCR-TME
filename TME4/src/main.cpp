#include "Banque.h"
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace std;
const int NB_THREAD = 10;
void work(pr::Banque& Bank){
    size_t n = 0;
    while(n < 1000){
        int nb_Compte = Bank.size_t();
        int i = rand()%nb_Compte;
        int j = rand()%nb_Compte;
        int m_max = Bank
        int m = rand()
    }
}
void jackpot(Compte & c) {
    for (int i=0; i < JP; i++)
        c.crediter(1);
}
int main () {
    srand((unsigned)time(NULL));
	vector<thread> threads;
	// TODO : creer des threads qui font ce qui est demandé

    pr::Banque Bank(10, 100);
    for(int i = 0; i < NB_THREAD; ++i){
        threads.push_back(thread(work,i));
    }

	for (auto & t : threads) {
		t.join();
	}

	// TODO : tester solde = NB_THREAD * JP
    for(int i = 0; i < Bank.size(), ++i){
        if(Bank.at(i).getSolde() != NB_THREAD*JP) {
            cout << "problem" << endl;
        }
    }

	return 0;
}
