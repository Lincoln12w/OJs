// 2017-03-03 

/*	Question:
 *	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 *	Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *	For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include<vector>
#include<iostream>
#include<algorithm>

using std::vector;
using std::sort;

class Solution 
{
private:
	typedef vector<int>::iterator index;
public:
	int threeSumClosest(vector<int> &num, int target) /* O(n *n)   this can pass */
	{
		sort(num.begin(), num.end());
		int end = num.size() - 1;
		int closest = num[0] + num[1] + num[2];

		if(closest == target)
			return closest;
		for(int i = 0; i < end - 1; ++i){
			int j = i + 1;
			int k = end;

			while(j < k){
				int sum = num[i] + num[j] + num[k];

				if(sum == target)
					return sum;

				sum > target ? --k : ++j;

				if(abs(closest - target) > abs(sum - target))
					closest = sum;
			}
		}
		return closest;
    }
};


int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(-1);
	vec.push_back(-1);
	vec.push_back(3);

	Solution s;
	std:: cout << s.threeSumClosest(vec, -1);

	std::cin.get();

	return 0;
}