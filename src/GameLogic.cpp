#include "GameLogic.hpp"

namespace Game {

void GameLogic::gameOfLife(std::vector<std::vector<int>>& board) {
    if (board.empty()) return;
    
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board[0].size(); x++) {
            int live = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int col = x + j, row = y + i;
                    if (!(i == 0 && j == 0) && col >= 0 && col < board[0].size() && row >= 0 && row < board.size() && board[row][col] > 0) {
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
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board[0].size(); x++) {
            if (board[y][x] > 0) {
                board[y][x] = (board[y][x] < 3 || board[y][x] > 4) ? 0 : 1;
            } else {
                board[y][x] = (board[y][x] == -3) ? 1 : 0;
            }
        }
    }
}

};