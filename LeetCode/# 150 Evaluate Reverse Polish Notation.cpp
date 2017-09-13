// 2014-11-27

/*	Question:
 *	Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 *	Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *	
 *	Some examples:
 *		["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *		["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *		["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6 
 */

#include <vector>
#include <string>
#include <sstream>
#include <stack>

using std::vector;
using std::string;
using std::istringstream;
using std::stack;

class Solution {
public:
	int evalRPN(vector<string> &tokens)
	{
		stack<int> intstack;

		for(int i = 0; i < tokens.size(); i++)
		{
			istringstream iss(tokens[i]);
			int num;
			char ch = tokens[i][0];
			if((ch == '-' && (tokens[i].size() != 1)) || isdigit(ch))	/* number */
			{
				iss >> num;
				intstack.push(num);
			}
			else
			{
				int a, b;
				a = intstack.top();
				intstack.pop();
				b = intstack.top();
				intstack.pop();
				int c;
				switch(ch)
				{
					case '+':
						c = a + b;
						break;
					case '-':
						c = b - a;
						break;
					case '*':
						c = a * b;
						break;
					case '/':
						c = b / a;
						break;
					default:
						break;
				}
				intstack.push(c);
			}
		}
		return intstack.top();
	}
};