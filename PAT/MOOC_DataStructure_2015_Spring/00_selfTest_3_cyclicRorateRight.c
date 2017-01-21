#include <iostream>
#include <vector>

using namespace std;

class cyclicRorateRight
{
private:
	int eleNum;
	int offset;
	int * eles;
public:
	cyclicRorateRight(int n, int m);
	~cyclicRorateRight();
	void rorateNow();
	void show();
	friend istream & operator>>(istream & is, cyclicRorateRight & crr)
	{
		for(int i = 0; i < crr.eleNum; i++)
			is >> crr.eles[i];
		return is;
	}
	friend ostream & operator<<(ostream & os, const cyclicRorateRight & crr)
	{
		os << crr.eles[0];
		for(int i = 1; i < crr.eleNum; i++)
			os << ' ' << crr.eles[i];
		return os;
	}
};

cyclicRorateRight::cyclicRorateRight(int n, int m)
	:eleNum(n), offset(m % n)
{
	eles = new int[n];
}

cyclicRorateRight::~cyclicRorateRight()
{
	delete[] eles;
}

void cyclicRorateRight::rorateNow()
{
	int origin, previous, current, store;

	if(offset ==0)			 /* Consider this condition, because we use eleNum % offset here. */
		return;
	
	if(eleNum % offset)
	{
		origin = eleNum - 1;
		store = eles[origin];
		previous = origin;
		current = origin - offset;

		while(current != origin)
		{
			eles[previous] = eles[current];
			previous = current;
			current -= offset;
			current = current >= 0? current: current + eleNum;
		}
		eles[previous] = store;
	}
	else
	{
		int loop = offset;
		
		while(loop)
		{
			origin = eleNum - loop;
			store = eles[origin];
			previous = origin;
			current = origin - offset;
			while(current != origin)
			{
				eles[previous] = eles[current];
				previous = current;
				current -= offset;
				current = current >= 0? current: current + eleNum;
			}
			eles[previous] = store;
			loop--;
		}
	}
}

int main()
{
	int n, m;

	cin >> n >> m;

	cyclicRorateRight crr(n, m);

	cin >> crr;

	crr.rorateNow();
	
	cout << crr;
  
  	return 0;
}

