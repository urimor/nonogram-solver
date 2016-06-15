#include <iostream>
#include <fstream>
#include <json.h>

#include "NonogramSolver.h"
#include "Board.h"

using std::cout;
using std::endl;
using std::string;
using Json = nlohmann::json;

void NonogramSolver::Run() {
    Json boardJson = read_board_from_file("resources/mushroom.json");
    Board board(boardJson);
    cout << "serialized board =  " << endl << board.Serialize().dump(4) << endl;
}

Json NonogramSolver::read_board_from_file(string boardJsonFileName) const {
    std::ifstream boardJsonFile(boardJsonFileName);
    string content( (std::istreambuf_iterator<char>(boardJsonFile) ),
                         (std::istreambuf_iterator<char>()    ) );
    return Json::parse(content);
}
