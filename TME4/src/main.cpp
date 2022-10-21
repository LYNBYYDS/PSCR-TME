#include "Banque.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

const int NB_THREAD = 10;
void work(pr::Banque& Bank){
    for(size_t n = 0; n < 1000; ++n){
        int nb_Compte = Bank.size();
        int i = rand()%nb_Compte;
        int j = rand()%nb_Compte;
        unsigned int m = rand()%100+1;
        int s = rand()%20+1;
        Bank.transfert(i, j, unsigned(m));
        //std::cout << "Start thread " << n << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(m));
        //std::cout << "Finsished thread" << n << std::endl;
    }
}

int main () {
    pr::Banque Bank(20, 1000);
    std::srand((unsigned) std::time(NULL));

    // TODO : creer des threads qui font ce qui est demandé

    std::vector<std::thread> threads;
    threads.reserve(NB_THREAD);
    for (size_t i = 0; i < NB_THREAD; ++i) {
        threads.emplace_back(work, std::ref(Bank));
        std::cout << "thread" << i << "created" << std::endl;
    }
    for (size_t i = 0; i < NB_THREAD; ++i) {
        threads.at(i).join();
        std::cout << "thread" << i << "joined" << std::endl;
    }
    // TODO : tester solde = NB_THREAD * JP
    return 0;
}

/// Le programme se bloque immédiatement, même avec un seul thread qui fait des
/// transferts. Pourquoi ?
/*
 Par défaut on a utilisé un mutex qui ne permet pas de double lock, même si le même thread
 détient déjà le lock. Ce comportement est di􏰂érent de celui eg. des barrières synchronized
 de Java.

 Ici, on lock le compte, puis on essaie de faire des crédits/débits dessus, donc on reprend
 le même lock. C'est un deadlock warning.

 Pour permettre une réacquisition il nous faut un recursive_mutex. En dehors de la
 déclaration, l'utilisation est le même que le mutex 􏰀normal􏰁.

 Un même thread peut le lock plusieurs fois, mais le nombre d'unlock et de lock doit rester
 cohérent. Souvent permet une programmation plus simple au niveau client de la classe.

 C'est aussi la sémantique proposée en Java pour 􏰀synchronized􏰁. Attention à mettre à jour
 le paramètre générique du lock guard
 * */