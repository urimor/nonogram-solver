#ifndef NONOGRAM_SOLVER_COMMON_H
#define NONOGRAM_SOLVER_COMMON_H


class Common {
public:
	static void exit_on_error(std::exception exception, std::string string);
	static void exit_on_error(std::string error);
};


#endif //NONOGRAM_SOLVER_COMMON_H
