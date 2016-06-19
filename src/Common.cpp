#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Common.h"

using std::cerr;
using std::endl;

void Common::ExitOnError(std::exception exception, std::string string) {
	std::stringstream error;
	error << string << ": " << endl << exception.what() << endl;
	ExitOnError(error.str());
}

void Common::ExitOnError(std::string error) {
	cerr << error << endl;
	exit(1);
}

void Common::ExitIfFilestreamIsNotOpen(std::ifstream &fileStream, std::string fileName) {
	if (!fileStream.is_open()) {
		ExitOnError("Could not open file " + fileName + " for reading");
	}
}

void Common::ExitIfFilestreamIsNotOpen(std::ofstream &fileStream, std::string fileName) {
	if (!fileStream.is_open()) {
		ExitOnError("Could not open file " + fileName + " for writing");
	}
}