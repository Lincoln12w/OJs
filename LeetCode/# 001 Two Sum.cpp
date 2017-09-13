// 2011-03-13 

/*	Question:
 *	Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 *	The function twoSum should return indices of the two numbers such that they add up to the target, 
 *	where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *	
 *	You may assume that each input would have exactly one solution.
 *
 *	Input: numbers={2, 7, 11, 15}, target=9
 *	Output: index1=1, index2=2 
 */

#include<vector>
#include<map>

using std::vector;
using std::map;
using std::pair;

class Solution 
{
public:
	vector<int> twoSum(vector<int> &numbers, int target) 
	{
		vector<int> ans;
		map<int, int> arrmap;

		for(int i = 0; i != numbers.size(); ++i)
		{
			//arrmap.insert(pair<int,int>(numbers[i], i+1));
			arrmap[numbers[i]] = i+1;
		}
		for(int i = 0; i != numbers.size();)
		{
			int temp = arrmap[target - numbers[i]];
			++i;
			if(temp)
			{
				if(temp > i)
				{
					ans.push_back(i);
					ans.push_back(temp);
					return ans;
				}
				if(temp < i)
				{
					ans.push_back(temp);
					ans.push_back(i);
					return ans;
				}
			}
		}
		return ans;
	}
};

/* test func */
int main()
{
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(4);
	numbers.push_back(3);
	numbers.push_back(0);
	Solution s;
	s.twoSum(numbers, 0);

	return 0;
}