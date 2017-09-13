// 2014-10-05 

/*	Question:
 *	Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *	
 *	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *	
 *	Find the minimum element.
 *	
 *	You may assume no duplicate exists in the array.
 */

#include <vector>

using std::vector;

class Solution
{
public:
    int findMin(vector<int> &num)
	{
		int beg = 0;
		int end = num.size() - 1;

		while(beg != end)
		{
			if(num[beg] < num[end])
				return num[beg];
			int mid = beg + (end - beg) / 2;

			if(mid == beg)
				return num[beg] > num[end] ? num[end] : num[beg];
			
			if(num[mid] > num[beg])
				beg = mid + 1;
			else
				end = mid;
		}
		return num[beg];
    }
};


int main()
{
	vector<int> num;

	num.push_back(5);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	//num.push_back(1);
	//num.push_back(2);
	//num.push_back(1);

	Solution s;

	int min = s.findMin(num);

	return 0;
}