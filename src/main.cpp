#include <iostream>
#include <string>

#include "NonogramSolver.h"

using std::cout;
using std::endl;
using std::string;

void check_input(int argc, char **pString);

void display_usage_and_exit(string execPath);

int main(int argc, char *argv[]) {
	check_input(argc, argv);
    NonogramSolver solver;
    solver.Run(string(argv[1]),string(argv[2]));
    return 0;
}

void check_input(int argc, char *argv[]) {
	if(argc < 3) {
		display_usage_and_exit(string(argv[0]));
	}
}

void display_usage_and_exit(string execPath) {
	cout << "Usage: " << endl << execPath << " <Input board file> <Output board file>" << endl;
	exit(1);
}