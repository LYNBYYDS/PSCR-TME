#include "mastring.h"
#include <iostream>

using namespace std;
int main(int argc, const char** argv){
    cout << "j'ai" << argc << "arg" << endl;
    const char* hw = "hello world";
    char* news = pr::newcopy(hw);
    cout << hw << pr::length(hw) << news << pr::length(news) << endl;
    delete []news;
    return 0;
}