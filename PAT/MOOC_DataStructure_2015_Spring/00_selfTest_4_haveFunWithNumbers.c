#include <iostream>

using namespace std;

class funNumbers
{
private:
	int digitNum;
	int digits[20];
	int digitCnt[10];
	bool isFun;
	bool isFlag;
public:
	funNumbers();
	void doubleAndTest();
	void show();
	friend istream & operator>>(istream & is, funNumbers & fn)
	{
		char num;
		while((num = is.get()) != '\n')
		{
			int n = num - '0';
			fn.digitCnt[n]++;
			fn.digits[fn.digitNum++] = n;
		}
		return is;
	}
};

funNumbers::funNumbers()
	:digitNum(0), isFun(true), isFlag(false)
{
	for(int i = 0; i < 10; i++)
		digitCnt[i] = 0;
}

void funNumbers::doubleAndTest()
{
	int tempNum;

	for(int i = digitNum - 1; i >= 0; i--)
	{
		tempNum = digits[i] * 2 + isFlag;	/* NOTE: here consider true as 1, and consider false as 0 */
		digits[i] = tempNum % 10;
		isFlag = tempNum / 10;
		if(--digitCnt[digits[i]] < 0)
			isFun = false;
	}
	if(isFlag)
		isFun = false;
}

void funNumbers::show()
{
	cout << (isFun ? "Yes\n" : "No\n");

	if(isFlag)							/* 2. and consider the flag when test result id false */
		cout << 1;
	
	for(int i = 0; i < digitNum; i++)	/* 1. print the number when test result is false too */
		cout << digits[i];
}

int main()
{
	funNumbers fn;

	cin >> fn;

	fn.doubleAndTest();
	fn.show();
  
  	return 0;
}

