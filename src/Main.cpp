#include <iostream>
#include <thread>
#include <chrono>

#include "GameLogic.hpp"

int main(int argc, char** argv) {
    // x / columns => argv[1]
    // y / rows    => argv[2]
    // num updates => argv[3]
    if (argc < 4) {
        std::cout << "Missing arguments, expected: .\\GameOfLife.exe X Y N" << std::endl;
        return 0;
    }

    auto thegame = new Game::GameLogic(atoi(argv[2]), atoi(argv[1]));

    for (int i = 0; i < atoi(argv[3]); i++) {
        thegame->LifeUpdate();
        thegame->PrintBoard();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}