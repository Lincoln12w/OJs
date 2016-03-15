#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::istringstream;

int main()
{
  string str;
  vector<string> vstring;
  getline(cin, str);
  istringstream iss(str);
  string temp;
  while(iss >> temp)
  {
    vstring.push_back(temp);
  }
  for(vector<string>::reverse_iterator riter = vstring.rbegin(); riter != vstring.rend(); riter++)   // using reverse iterator
  {
    cout << *riter;
    if(riter != (vstring.rend()-1))
      cout << " ";
  }

  return 0;
}
