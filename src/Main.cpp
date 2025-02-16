#include <iostream>
#include <vector>

#include "GameLogic.hpp"

int main(int argc, char** argv) {
    auto thegame = new Game::GameLogic();

    auto temp = new std::vector<std::vector<int>>();
    // empty vector should cause no-op and clean return;
    thegame->gameOfLife(*temp);

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
}