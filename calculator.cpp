#include "calculator.hpp"

int add(const string & number) {
	string substring = number;
	int sum = 0;
	if(substring !=""){
		while(!substring.empty())
		{
			if(substring.find_first_of(",\n") != string::npos)
			{
				sum += stoi(substring.substr(0,substring.find_first_of(",\n")));
				substring = substring.substr(substring.find_first_of(",\n")+1, substring.size());	
			}
			else
			{
				sum += stoi(substring);
				substring = "";
			}
		}
	}
	return sum;
}
