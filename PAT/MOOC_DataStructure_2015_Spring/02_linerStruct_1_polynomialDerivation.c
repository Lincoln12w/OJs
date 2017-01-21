#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class polyDerivation
{
private:
	string poly;
public:
	friend istream & operator>>(istream & is, polyDerivation & pd)
	{
		getline(is, pd.poly);
		return is;
	}
	void derivation();
};

void polyDerivation::derivation()
{
	istringstream iss(poly);

	int a, n;

	iss >> a >> n;

	if(n)
		cout << a * n << ' ' << n - 1;
	else
		cout << "0 0";			/* for test case {6, 0} */

	while(iss >> a >> n)
	{
		if(n)
			cout << ' ' <<  a * n << ' ' << n - 1;
	}
}

int main()
{
	polyDerivation pd;

	cin >> pd;

	pd.derivation();
  
  	return 0;
}

