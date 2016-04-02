#include <iostream>

#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;

int main()
{
	int n;
	cin >> n;

	map<int, int> schools;

	int maxscore = 0;
	int maxID = 0;

	for(int i = 0; i < n; i++)
	{
		int ID, score;
		cin >> ID >> score;

		schools[ID] += score;
		if(schools[ID] > maxscore)
		{
			maxscore = schools[ID];
			maxID = ID;
		}
	}
	cout << maxID << ' ' << maxscore << endl;

	return 0;
}
