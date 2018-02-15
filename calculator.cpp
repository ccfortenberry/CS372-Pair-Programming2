#include "calculator.hpp"

int add(const string & number) {
	if(number !=""){
		return std::stoi(number,nullptr);
	}
	else
		return 0;
}