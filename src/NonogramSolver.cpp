#include <iostream>
#include <fstream>
#include <json.h>

#include "NonogramSolver.h"
#include "Board.h"
#include "Common.h"

using std::cout;
using std::endl;
using std::string;
using Json = nlohmann::json;

void NonogramSolver::Run() {
    Json boardJson = read_board_from_file("resources/mushroom.json");
    Board board(boardJson);
    write_board_to_file(board, "viewer/board.json");
}

Json NonogramSolver::read_board_from_file(string boardJsonFileName) const {
    std::ifstream boardJsonFile(boardJsonFileName);
    string content( (std::istreambuf_iterator<char>(boardJsonFile) ),
                         (std::istreambuf_iterator<char>()    ) );
    return Json::parse(content);
}

void NonogramSolver::write_board_to_file(Board board, string boardJsonFileName) const {
    std::ofstream boardJsonFile(boardJsonFileName);
    if(!boardJsonFile.is_open()){
        Common::exit_on_error("NonogramSolver::write_board_to_file - could not open "
                              + boardJsonFileName + " for writing");
    }
    boardJsonFile << board.Serialize().dump(4);
}