#ifndef NONOGRAM_SOLVER_NONOGRAMSOLVER_H
#define NONOGRAM_SOLVER_NONOGRAMSOLVER_H

#include <json.h>

class NonogramSolver {
public:
    void Run();
private:
    nlohmann::json read_board_from_file(std::string boardJsonFile) const;
};


#endif //NONOGRAM_SOLVER_NONOGRAMSOLVER_H
