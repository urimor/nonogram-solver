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

void NonogramSolver::Run(const string &inputFileName, const string &outputFileName) {
	Json boardJson = read_board_from_file(inputFileName);
	Board board(boardJson);
	write_board_to_file(board, outputFileName);
}

Json NonogramSolver::read_board_from_file(const string &boardJsonFileName) const {
	std::ifstream boardJsonFile(boardJsonFileName);
	Common::ExitIfFilestreamIsNotOpen(boardJsonFile, boardJsonFileName);
	string content((std::istreambuf_iterator<char>(boardJsonFile)),
	               (std::istreambuf_iterator<char>()));
	return Json::parse(content);
}

void NonogramSolver::write_board_to_file(Board board, const string &boardJsonFileName) const {
	std::ofstream boardJsonFile(boardJsonFileName);
	Common::ExitIfFilestreamIsNotOpen(boardJsonFile, boardJsonFileName);
	boardJsonFile << board.Serialize().dump(4);
}

