/*	Question:
 *	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 *	Find all unique triplets in the array which gives the sum of zero.
 *	
 *	Note:
 *	Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 *	The solution set must not contain duplicate triplets.
 *
 *  For example, given array S = {-1 0 1 2 -1 -4},
 *
 *		A solution set is:
 *		(-1, 0, 1)
 *		(-1, -1, 2)
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
	{
		vector<vector<int> > ans;
		sort(num.begin(), num.end());
		int end = num.size();
		for(int i = 0; i < end - 2; ++i)
		{
			int j = i + 1;
			int k = end - 1;

			if(num[i] + num[j] + num[j+1] > 0)				    // for early stop
				break;
			if(num[i] + num[k] + num[k-1] < 0)
			    continue;

			while(j < k)
			{
				int sum = num[i] + num[j] + num[k];

			    if(num[i] + num[j] + num[j+1] > 0)			    // for early stop
				    break;

				if(sum == 0)
				{
					ans.push_back(vector<int>{num[i], num[j], num[k]});
					while((++j < k) && (num[j] == num[j-1]));   // skip duplicate number 2
					while((j < --k) && (num[k] == num[k+1]));	// skip duplicate number 3
				}
				if(sum > 0)
					--k;
				if(sum < 0)
					++j;
			}

			while(num[i] == num[i + 1])					    	// skip duplicate number 1
				++i;
		}
		return ans;
    }
};

int main()
{
	vector<int> num;
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);

	Solution s;
	s.threeSum(num);

	return 0;
}