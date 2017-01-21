#include <iostream>

using namespace std;

class maxSumSubSeq
{
private:
	int length;
public:
	maxSumSubSeq(int length);
	int maxSum();
};

maxSumSubSeq::maxSumSubSeq(int len)
	:length = len
{}

int maxSumSubSeq::maxSum()
{
	int sum = 0;
	int temp = 0;
	int num;

	for(int i = 0; i < length; i++)
	{
		cin >> num;
		temp += num;
		if(temp > sum)
			sum = temp;
		else if(temp <= 0)
			temp = 0;
	}
	return sum;
}

int main()
{
	int len;

	cin >> len;

	maxSumSubSeq msss(len);

	cout << msss.maxSum();
  
  	return 0;
}

