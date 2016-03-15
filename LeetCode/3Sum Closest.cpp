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
		//sort(beg, end);
		int end = num.size();
		int flag = 0;
		int max = num[0] + num[1] + num[2];
		for(int i = 0; i != end - 2; ++i)
		{
			for(int j = i+1; j != end - 1; ++j)
			{
				for(int k = j+1; k != end; ++k)
				{
					int sum = num[i] + num[j] + num[k];
					if(sum == target)
						return sum;
					else
						if(abs(max - target) > abs(sum - target))
							max = sum;
				}
			}
		}
		return max;
    }
	int abs(int x)
	{
		return x < 0 ? -x : x;
	}

	int threeSumClosest_others(vector<int> &num, int target) {        
		vector<int> v(num.begin(), num.end()); // I didn't wanted to disturb original array.
		int n = 0;
		int mx = 0;
		int sum;

		sort(v.begin(), v.end());

		// If less then 3 elements then return their sum
		while (n < 3 && n < v.size()) {
			mx += v[n++];
			if (n == v.size()) return mx;
		}

		n = v.size();

		/* v[0] v[1] v[2] ... v[i] .... v[j] ... v[k] ... v[n-2] v[n-1]
		 *                    v[i]  <=  v[j]  <= v[k] always, because we sorted our array. 
		 * Now, for each number, v[i] : we look for pairs v[j] & v[k] such that 
		 * absolute value of (target - (v[i] + v[j] + v[k]) is minimised.
		 * if the sum of the triplet is greater then the target it implies
		 * we need to reduce our sum, so we do K = K - 1, that is we reduce
		 * our sum by taking a smaller number.
		 * Simillarly if sum of the triplet is less then the target then we
		 * increase out sum by taking a larger number, i.e. J = J + 1.
		 */
		for (int i = 0; i < n-2; i++) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				sum = v[i] + v[j] + v[k];
				if (abs(target - mx) > abs(target - sum)) {
					mx = sum;
					if (mx == target) return mx;
				}
				(sum > target) ? k-- : j++;
			}
		}
		return mx;
	}
};

int main()
{
	vector<int> vec;

	vec.push_back(-1);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(4);

	Solution s;
	std:: cout << s.threeSumClosest_others(vec, 1);

	std::cin.get();

	return 0;
}