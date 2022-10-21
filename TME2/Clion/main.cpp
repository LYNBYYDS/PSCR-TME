#include <iostream>
#include "HashMap.hpp"
size_t count(iterator begin, iterator end){

}
int main() {

    std::cout << "begin" << std::endl;
    HashMap<std::string, int> hp(20);

    std::string word = "all";

    bool b = hp.push("all",12);
    std::cout << b << " : " << *(hp.get(word)) << std::endl;

    return 0;
}

