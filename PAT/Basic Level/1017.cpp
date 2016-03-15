#include<string>
#include<iostream>
#include<sstream>

using std::cin;
using std::cout;
using std::string;
using std::istringstream;
using std::ostringstream;

char calc(string str, int n);

int main()
{
  string number;
  int num;
  cin >> number >> num;
  while(number.size() > 9)
  {
    string s;
    s.assign(number,0,9);
    char last[2];
    last[0] = calc(s,num);
    last[1] = '\0';
    number.erase(0,9);
    if(last[0] != '0')
      number.insert(0,last);
  }
  char ch = calc(number,num);
  cout << " " << ch;
  return 0;
}

char calc(string str, int n)
{
  istringstream iss(str);
  int numb;
  iss >> numb;
  cout << numb/n;
  char ch = numb%n + '0';

  return ch;
}
