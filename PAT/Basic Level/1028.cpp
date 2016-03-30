#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int n;
	cin >> n;

	int oldday = 18140906;
	int	today = 20140906;
	int	oldBirth = 20140907;
	int	youngBirth = 18140905;
	int	validCnt = 0;
	string oldest, youngest;
	
	for(int i = 0; i < n; i++)
	{
		string name, birthday;
		cin >> name >> birthday;
		int birth = 0;
		for(int j = 0; j < 10; j++)
		{
			if(birthday[j] != '/')
			{
				birth *= 10;
				birth += birthday[j] - '0';
			}
		}
		if(birth <= today && birth >= oldday)
		{
			validCnt +=1;
			if(birth < oldBirth)
			{
				oldBirth = birth;
				oldest = name;
			}
	        if(birth > youngBirth)
	        {
	            youngBirth = birth;
				youngest = name;
			}
		}
	}

	if(validCnt)
		cout << validCnt << ' ' << oldest << ' ' << youngest << endl;
	else
		cout << 0;

	return 0;
}

