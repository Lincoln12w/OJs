#include <iostream>
#include <string>

int main()
{
	std::string s1, s2;

	getline(std::cin, s1);
	getline(std::cin, s2);

	int size = s2.size();

	int pos = s1.find(s2);

	while(pos != std::string::npos)
	{
		s1.erase(pos, size);
		pos = s1.find(s2);
	}

	std::cout << s1;

	return 0;
}