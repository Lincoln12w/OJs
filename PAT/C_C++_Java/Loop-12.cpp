#include <iostream>
#include <iomanip>

using std::setw;
using std::setiosflags;
using std::ios;

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < i + 1; j++)
			std::cout << j+1 << "*" << i + 1 << "=" 
			<< setiosflags(ios::left) << setw(4) <<(i + 1) * (j + 1);
		std::cout << std::endl;
	}

	return 0;
}