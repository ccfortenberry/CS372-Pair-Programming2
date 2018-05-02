#include "calculator.hpp"
using std::string;

int add(const string & number) {
	string substring = number;
	int sum = 0;
	string delimiters = ",\n";
	if(substring !="") {
		if(substring.size() > 2) {
			if(substring[0] ==  '/' && substring[1] == '/') {
				for(unsigned int i = 2; i <= substring.size(); i++) {
					if(substring[i] == '\n') {
						substring = substring.substr(i+1, substring.size());
						break;
					}
					delimiters += substring[i];
					if(i == substring.size() && substring[i] != '\n')
						throw "No end to delimeter";
				}
			}
		}
		
		while(!substring.empty()) {
			int valueToAddToSum = 0;
			
			if(substring.find_first_of(delimiters) != string::npos) {
				valueToAddToSum = stoi(substring.substr(0,substring.find_first_of(delimiters)));
				substring = substring.substr(substring.find_first_of(delimiters)+1, substring.size());	
			}
			else {
				valueToAddToSum = stoi(substring);
				substring = "";
			}
			
			if(valueToAddToSum < 0) {
				throw std::invalid_argument("A negative number was given to add");
			}
			
			if(valueToAddToSum > 1000) {
				valueToAddToSum = 0;
			}
			
			sum += valueToAddToSum;
		}
	}
	return sum;
}
