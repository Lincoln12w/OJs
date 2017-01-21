#include <iostream>
#include <vector>

using namespace std;

class twinPrimeConjecture
{
private:
	int maxNum;
	int pairCount;
	vector<bool> isPrime;
	void primeTest();
	void markFalse(int base);
public:
	twinPrimeConjecture();
	twinPrimeConjecture(int n);
	int count();
	void show();
};

twinPrimeConjecture::twinPrimeConjecture(int n)
	:maxNum(n)
{
	isPrime.assign(n + 1,true);
	isPrime[0] = false;
	isPrime[1] = false;
	pairCount = 0;
}

void twinPrimeConjecture::markFalse(int base)
{
	int i = 1;

	while(++i * base <= maxNum)
		isPrime[i * base] = false;
}

void twinPrimeConjecture::primeTest()
{
	int i = 1;

	while(++i <= maxNum)
		if(isPrime[i])
			markFalse(i);
}

int twinPrimeConjecture::count()
{
	int i = 1;

	primeTest();

	while(++i <= maxNum - 2)
		if(isPrime[i] && isPrime[i+2])
			pairCount++;

	return pairCount;
}

void twinPrimeConjecture::show()
{
	int i = 1;
	while(++i <= maxNum)
		if(isPrime[i] == true)
			cout << i << ' ';
	cout << endl;
}

int main()
{
	int n;

	cin >> n;
	twinPrimeConjecture tp(n);
	cout << tp.count();
  
	return 0;
}

