#include <vector>
#include <string>

namespace Game {

class GameLogic {
private:
    int rows;
    int cols;
    std::string board_input_file;
    std::vector<std::vector<int>> board;

    bool SetupBoard();

public:
    GameLogic(int rows, int cols, std::string configfile = "");

    void LifeUpdate();
    void PrintBoard();
};

};