#ifndef NONOGRAM_SOLVER_COMMON_H
#define NONOGRAM_SOLVER_COMMON_H


class Common {
public:
	static void ExitOnError(std::exception exception, std::string string);
	static void ExitOnError(std::string error);
	static void ExitIfFilestreamIsNotOpen(std::ifstream &fileStream, std::string fileName);
	static void ExitIfFilestreamIsNotOpen(std::ofstream &fileStream, std::string fileName);
};


#endif //NONOGRAM_SOLVER_COMMON_H
