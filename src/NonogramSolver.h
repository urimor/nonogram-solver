#ifndef NONOGRAM_SOLVER_NONOGRAMSOLVER_H
#define NONOGRAM_SOLVER_NONOGRAMSOLVER_H

#include <json.h>
#include "Board.h"

class NonogramSolver {
public:
	void Run(const std::string &inputFileName, const std::string &outputFileName);

private:
	nlohmann::json read_board_from_file(const std::string &boardJsonFileName) const;

	void write_board_to_file(Board board, const std::string &boardJsonFileName) const;
};


#endif //NONOGRAM_SOLVER_NONOGRAMSOLVER_H
