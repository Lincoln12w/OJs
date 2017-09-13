// 2014-03-05 

/*	Question:
 *	Given an input string, reverse the string word by word.
 *
 *	For example,
 *	Given s = "the sky is blue",
 *	return "blue is sky the".
 */

#include<string>
#include<vector>
#include<sstream>
#include<iostream>

using std::string;
using std::vector;
using std::istringstream;

class Solution 
{
private:
	typedef string::size_type index;
public:
	void reverseWords(string & str)
	{
		vector<string> vstring;
		istringstream iss(str);
		string temp;
		while(iss >> temp)
		{
			vstring.push_back(temp);
		}
		str = "";
		if(vstring.size()==0)
			return;
		for(vector<string>::reverse_iterator riter = vstring.rbegin(); riter != vstring.rend(); riter++)   // using reverse iterator
		{
			str += *riter;
			if(riter != (vstring.rend()-1))
			str += " ";
		}

		return;
	}
	void reverseWord(string &s)	
	{
		index pos = 0;
		index cur = 0;

		pos = s.find_first_not_of(' ',0);
		s.erase(0, pos);
		if(s == "")
		return;
		while((pos = s.find_first_of(' ', cur)) != string::npos)
		{
			swap(cur,pos,s);
			if((cur = s.find_first_not_of(' ', pos)) == string::npos)
				break;
			index diff = cur - pos - 1;
			s.erase(pos,diff);
			cur -= diff;
		}
		swap(cur,s.size(),s);
		swap(0,s.size(),s);
		if(pos = s.find_first_not_of(' ',0))
			s.erase(0, pos);

		return;
	}
	inline void swap(index beg, index end, string & s)
	{
		for(index i = beg, j = end - 1; i < j; ++i, --j)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	}
};

/* test func */
int main(void)
{
	string str("  a   bndff dd er    er  ");
	Solution s;
	s.reverseWord(str);

	std::cout << str;

	std::cin.get();

}