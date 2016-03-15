/*	Question:
 *	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *	
 *	Note:
 *	Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
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
		vector<int> temp(3,0);
		int end = num.size();
		sort(num.begin(), num.end());
		for(int i = 0; i < end - 2; ++i)
		{
			int j = i + 1;
			int k = end - 1;
			while(j < k)
			{
				int calc = num[i] + num[j] + num[k];
				if(calc == 0)
				{
					temp[0] = num[i];
					temp[1] = num[j];
					temp[2] = num[k];
					ans.push_back(temp);
					++j;
				}
				if(calc > 0)
					--k;
				if(calc < 0)
					++j;
			}
		}
		return ans;
    }
};

int main()
{
	//vector<int> num;
	//num.push_back(-1);
	//num.push_back(0);
	//num.push_back(1);
	//num.push_back(2);
	//num.push_back(-1);
	//num.push_back(-4);

	//Solution s;
	//s.threeSum(num);

	
  




	return 0;
}