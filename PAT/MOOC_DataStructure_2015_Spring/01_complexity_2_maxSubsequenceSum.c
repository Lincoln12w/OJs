#include <iostream>

using namespace std;

class maxSumSubSeq
{
private:
	int length;
	int sum;
	int beg;			/* notice the question is to show the number, not the index */
	int end;
public:
	maxSumSubSeq(int length);
	void maxSum();
	void show();
};

maxSumSubSeq::maxSumSubSeq(int len)
	:sum(0), beg(0), end(0)
{
	length = len;
}

void maxSumSubSeq::maxSum()
{
	int tempSum = 0;
	int tempBeg, tempEnd;
	int ori, flag = 0;			/* add this for test case 5, which maybe {-2, -3, 0, 0, -4} */
														/* and the result should be 0 0 0 */
	cin >> tempEnd;
	ori = tempBeg = tempEnd;
	if(tempEnd == 0)
		flag = 1;

	for(int i = 1; i < length; i++)
	{
		tempSum += tempEnd;
		if(tempSum > sum)
		{
			sum = tempSum;
			beg = tempBeg;
			end = tempEnd;
		}
		cin >> tempEnd;
		if(tempEnd == 0)
			flag = 1;
		if(tempSum < 0)
		{
			tempBeg = tempEnd;
			tempSum = 0;
		}
	}
	tempSum += tempEnd;
	if(tempSum > sum)
	{
		sum = tempSum;
		beg = tempBeg;
		end = tempEnd;
	}
	if(sum == 0)
	{
		if(flag)
			beg = end = 0;
		else
		{
			beg = ori;
			end = tempEnd;
		}
	}
}

void maxSumSubSeq::show()
{
	cout << sum << ' ' << beg << ' ' << end;
}

int main()
{
	int len;

	cin >> len;

	maxSumSubSeq msss(len);

	msss.maxSum();
	msss.show();
  
  	return 0;
}

