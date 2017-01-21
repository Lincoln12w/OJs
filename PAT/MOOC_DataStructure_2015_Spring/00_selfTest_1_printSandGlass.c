#include <iostream>

using namespace std;

class printSandglass
{
private:
	int numOfCh;
	int maxLen;
	char ch;
	void printMulti(int n, char c);
	void printLen(int n);
public:
	int leftChNum() {return numOfCh - 1;}
	printSandglass();
	printSandglass(int n, char c);
	void print();
};

printSandglass::printSandglass(int n, char c)
	:numOfCh(n),ch(c)
{
	maxLen = 1;
	if(numOfCh >= 7)
	{
		while(numOfCh > 2 * (maxLen + 2))
		{
			numOfCh -= 2 * (maxLen + 2);
			maxLen += 2;
		}
	}
}

void printSandglass::printLen(int n)
{
	printMulti((maxLen - n) / 2, ' ');
	printMulti(n, ch);
	cout << endl;
}

void printSandglass::printMulti(int n, char c)
{
	for(int i = 0; i < n; i++)
		cout << c;
}

void printSandglass::print()
{
	int i = maxLen;
  	
	while(i > 1)
	{
		printLen(i);
		i -= 2;
	}
	while(i <= maxLen)
	{
		printLen(i);
		i += 2;
	}
}

int main()
{
	int n;
	char c;

	cin >> n >> c;

	printSandglass sg(n, c);
	sg.print();
	cout << sg.leftChNum();

	cin >> n;
  
	return 0;
}

