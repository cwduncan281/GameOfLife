#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "GameLogic.hpp"

namespace Game {

GameLogic::GameLogic(int rows, int cols, std::string configfile) {
    this->rows = rows;
    this->cols = cols;
    this->board_input_file = configfile.empty() ? configfile : "";
    board = std::vector<std::vector<int>>(rows);
    for (auto& vec : board) {
        vec = std::vector<int>(cols);
    }
    SetupBoard();
}

bool GameLogic::SetupBoard() {
    srand(time(nullptr));
    if (board_input_file.empty()) {
        for (auto& row : board) {
            std::generate(row.begin(), row.end(), [](){ return rand() % 2; });
        }
    }
    return true;
}

void GameLogic::LifeUpdate() {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int live = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int col = x + j, row = y + i;
                    if (!(i == 0 && j == 0) && 
                            col >= 0 && col < cols &&
                            row >= 0 &&row < rows &&
                            board[row][col] > 0) {
                        live++;
                    }
                }
            }
            if (board[y][x] == 0) {
                board[y][x] -= live;
            }
            else {
                board[y][x] += live;
            }
        }
    }
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (board[y][x] > 0) {
                board[y][x] = (board[y][x] < 3 || board[y][x] > 4) ? 0 : 1;
            } else {
                board[y][x] = (board[y][x] == -3) ? 1 : 0;
            }
        }
    }
}

void GameLogic::PrintBoard() {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            std::cout << board[y][x] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

};