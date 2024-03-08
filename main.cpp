#include "init.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]){
    init();
    loadMedia();

    showUntilQuit();
    close();
    return 0;
}
