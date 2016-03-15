#include <iostream>
#include <string>
#include <vector>

int main()
{
	typedef std::vector<std::string> arr;
	int n, times, i = 0;
	std::string s;
	arr svec;

	std::cin >> n >> times;
	while(n--)
	{
		std::cin >> s;
		svec.push_back(s);
	}
	for(arr::iterator iter = svec.begin(); iter != svec.end() - 1; ++iter)
	{
		for(arr::iterator jter = iter + 1; jter != svec.end(); ++jter)
		{
			if(*iter > *jter)
			{
				std::string temp = *iter;
				*iter = *jter;
				*jter = temp;
			}
			++i;
			if(i == times)
				break;
		}
	}
	std::cout << svec.front();
	for(arr::iterator iter = svec.begin() + 1; iter != svec.end(); ++iter)
		std::cout << "\n" << *iter;

	return 0;
}