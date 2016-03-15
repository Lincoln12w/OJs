#include <iostream>
#include <string>

void swap(int pos1, int pos2, std::string & s);

int main()
{
	std::string s;
	int beg, end = 0;

	getline(std::cin, s);

	//while(((beg = s.find_first_not_of(' ',end)) != std::string::npos) && ((end = s.find_first_of(' ', beg)) != std::string::npos))
	//{
	//	swap(beg, end - 1, s);
	//}
	//swap(beg, s.size() - 1, s);
	swap(0,s.size() - 1, s);

	std::cout << s;

	return 0;
}

void swap(int beg, int end, std::string & s)
{
	for(int i = beg, j = end; i < j; ++i, --j)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}