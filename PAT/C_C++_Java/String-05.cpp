#include<iostream>
#include<string>

void swap(int beg, int end, std::string & s);

int main()
{
	std::string s;
	int n;

	getline(std::cin, s);
	std::cin >> n;

	int size = s.size();
	n %= size;

	swap(0, n-1, s);
	swap(n, size - 1, s);
	swap(0, size - 1, s); 

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

