#include <exception>
#include <iostream>
#include <sstream>
#include "Common.h"

using std::cerr;
using std::endl;

void Common::exit_on_error(std::exception exception, std::string string) {
	std::stringstream error;
	error << string << ": " << endl << exception.what() << endl;
	exit_on_error(error.str());
}

void Common::exit_on_error(std::string error){
	cerr << error << endl;
	exit(1);
}