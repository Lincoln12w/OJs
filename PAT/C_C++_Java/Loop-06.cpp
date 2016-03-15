#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::istringstream;

int main()
{
	string s;
	string word;
	int cnt = 0;

	getline(std::cin, s);
	
	istringstream iss(s);
	while(iss >> word)
		cnt++;
	
	std::cout << cnt;

	return 0;
}

