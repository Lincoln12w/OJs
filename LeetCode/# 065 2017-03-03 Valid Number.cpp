/*	Question:
 *	Validate if a given string is numeric.
 *	
 *	Some examples:
 *	"0" => true
 *	" 0.1 " => true
 *	"abc" => false
 *	"1 a" => false
 *	"2e10" => true
 *	Note: It is intended for the problem statement to be ambiguous. 
 *	You should gather all requirements up front before implementing one.
 */
 
#include <string>
#include <ctype.h>
#include <iostream>

using std::string;
 
class Solution {
public:
    bool isNumber(string s) {
    	int n = s.size();

    	bool is_head = true;

    	bool has_blank = false;
    	char previous = 'n';
    	bool cur_is_digit = false;
    	bool has_digit = false;
    	bool dot = false;
    	bool e = false;
    	bool end_with_e = false;
    	char last_non_blank;

    	for(int i = 0; i < n; i++) {
    		char c = s[i];
    		if (has_blank && c != ' ')
    			return false;

    		if(isdigit(c)){
    			if (!e) {
    				//std::cout << "--" << std::endl;
    				cur_is_digit = true;
    			}

    			has_digit = true;
    			is_head = false;
    		}
    		else {
    			if (c == ' ') {
    				if (is_head == false)
    					has_blank = true;
    			}
    			else if (c == '+' || c == '-') {
    				if (!is_head && (previous != 'e')) {
    					std::cout << "+/-" << std::endl;
    					return false;
    				}
    			}
    			else if (c == 'e') {
    				if (!cur_is_digit)
    					return false;
    				cur_is_digit = false;
    				e = true;
    			}
    			else if (c == '.') {
    				if (dot || e || (previous == 'e')) {
    					std::cout << "." << std::endl;
    					return false;
    				}
    				dot = true;
    			}
    			else
    				return false;
    			if (c != ' ')
    				is_head = false;
    		}
    		if (c != ' ')
    			last_non_blank = c;
    		previous = c;
    	}
    	if(!has_digit)
			return false;

		if(!isdigit(last_non_blank) && last_non_blank != '.')
			return false;

        return true;
    }
};

int main() {

	Solution s;

	std::cout << s.isNumber("0") << std::endl;
	std::cout << s.isNumber(" 0.1") << std::endl;
	std::cout << s.isNumber("abc") << std::endl;
	std::cout << s.isNumber("1 a") << std::endl;
	std::cout << s.isNumber("2e10") << std::endl;
	std::cout << s.isNumber(" ") << std::endl;
	std::cout << s.isNumber(" 74") << std::endl;
	std::cout << s.isNumber("8. ") << std::endl;
	std::cout << s.isNumber("8 .") << std::endl;
	std::cout << s.isNumber("-1.") << std::endl;
	std::cout << s.isNumber("10") << std::endl;
	std::cout << s.isNumber("1  ") << std::endl;
	std::cout << s.isNumber("0e  ") << std::endl;
	std::cout << s.isNumber("0e+  ") << std::endl;
	std::cout << s.isNumber("+.8") << std::endl;
	std::cout << s.isNumber(".0") << std::endl;

	return 0;
}