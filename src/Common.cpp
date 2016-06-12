#include <exception>
#include <iostream>
#include "Common.h"

using std::cerr;
using std::endl;

void Common::exit_on_error(std::exception exception, std::string string) {
	cerr << string << ": " << endl << exception.what() << endl;
}