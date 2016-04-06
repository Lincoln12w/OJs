#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;
using std::sort;

typedef struct _record
{
	string time;
	string status;
}record;

int gettime(string time)
{
	return ((time[0] - '0') * 10 + time[1] - '0') * 3600 + ((time[3] - '0') * 10 + time[4] - '0') * 60 + (time[6] - '0') * 10 + time[7] - '0';
}	

bool ordered(record a, record b)
{
	return a.time < b.time;
}

int main()
{
	int K, N;
	cin >> K >> N;

	map<string, vector<record> > cars;

	// get car in/out record
	for(int i = 0; i < K; i++)
	{	
		record r;
		string ID;
		cin >> ID >> r.time >> r.status;
		
		cars[ID].push_back(r);
	}

	int longtime = 0;
	vector<string> longCar;
	map<string, int> times;

	// valid record & select max
	for(map<string, vector<record> >::iterator iter = cars.begin(); iter != cars.end(); iter++)
	{
		vector<record> r = iter->second;
		sort(r.begin(), r.end(), ordered);
		int parktime = 0;
		for(int i = 0; i < r.size() - 1; i++)
		{
			if(r[i].status == "in" && r[i+1].status == "out")
			{
				string tin = r[i].time;
				string tout = r[i+1].time;
				times[tin] += 1;
				times[tout] -= 1;
				parktime += gettime(tout) - gettime(tin);				
				i++;
			}
		} 
		if(parktime == longtime)
			longCar.push_back(iter->first);
		if(parktime > longtime)
		{
			longCar.clear();
			longCar.push_back(iter->first);
			longtime = parktime;
		}
	}

	map<string, int>::iterator iter = times.begin();
	int parkedcnt = 0;
	for(int i = 0; i < N; i++)
	{
		string time;
		cin >> time;
		while(iter != times.end())
		{
			if(time < iter->first)
			{
				cout << parkedcnt << endl;
				break;
			}
			parkedcnt += iter->second;
			iter++;
		}
		if(iter == times.end())
			cout << parkedcnt << endl;
	}

	sort(longCar.begin(), longCar.end());
	for(int i = 0; i < longCar.size(); i++)
		cout << longCar[i] << ' ';

	printf("%02d:%02d:%02d\n", longtime / 3600, (longtime % 3600) / 60, longtime % 60);

	return 0;
}
