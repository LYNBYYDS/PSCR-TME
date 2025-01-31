#include "Compte.h"

using namespace std;

namespace pr {
    void Compte::crediter(unsigned int val) {
        std::lock_guard<std::recursive_mutex> g(m);
        solde += val;
    }

    bool Compte::debiter(unsigned int val) {
        std::lock_guard<std::recursive_mutex> g(m);
        bool doit = solde >= val;
        if (doit) {
            solde -= val;
        }
        return doit;
    }

    int Compte::getSolde() const {
        std::lock_guard<std::recursive_mutex> g(m);
        return solde;
    }

// NB : vector exige Copyable, mais mutex ne l'est pas...
    Compte::Compte(const Compte &other) {
        other.m.lock();
        solde = other.solde;
        other.m.unlock();
    }
}
