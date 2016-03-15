/*	Question:
 *	Given a string, find the length of the longest substring without repeating characters. 
 *	
 *	For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 *	which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <string>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
        int maxbeg, maxend;
		inr curbeg, curend;
    }
};

/* test func */
int main()
{
	string str("abcabcbb");

	Solution s;
	s.lengthOfLongestSubstring(str);

	return 0;
}