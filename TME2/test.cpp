#include <iostream>
#include "HashMap.hpp"

int main(){
    size_t NB = 10;
    int val = 20;
    std::string key = "ok";
    HashMap<std::string, int> h(NB);
    h.put(key, val);
    auto addr = h.get(key);

    std::cout << &(addr) << std::endl;
    return 0;
}
