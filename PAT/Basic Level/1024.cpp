#include<iostream>
#include<string>
#include<sstream>

using std::cin;
using std::cout;
using std::string;
using std::istringstream;
using std::endl;

void display(string & str, int pos);

int main()
{
  string s;
  cin >> s;
  if(s[0] == '-')     // only - need to display
    cout << s[0];
  char first = s[1];
  s.erase(0,2);
  if(s[0] != '.')
  {
    return 0;
  }
  s.erase(0,1);           // all calc based on a.bEc
  string num;
  int n = s.find('E');
  num.assign(s,0,n);
  num.insert(0,&first,1);   // get the number
  s.erase(0,n+1);
  int pos = 1;
  char flag = s[0];
  s.erase(0,1);
  istringstream iss(s);
  int cnt;
  iss >> cnt;              // get the pow
  if(flag == '+')
  {
    pos += cnt;
    display(num,pos);
  }
  else
  {
    pos -= cnt;
    display(num,pos);
  }

  return 0;
}

void display(string & str, int pos)     // diaplay based number and power by 10
{
  if(pos <= 0)      // the point shift left
  {
    cout << "0.";
    for(int i = 0; i > pos; i--)
    {
      cout << 0;
    }
    cout << str;
  }
  else
  {
    int size = str.size();
    if(pos < size)        // the point shift right, but still inside the number
    {
      str.insert(pos,".");
      while(str[0]=='0' && str[1]!='.')
      {
        str.erase(0,1);
      }
      cout << str;
    }
    else                // need to add 0 at the end
    {
      while(str[0]=='0' && str[1]!='.')
      {
        str.erase(0,1);
      }
      cout << str;
      for(int i = 0; i < pos-size; i++)
      {
        cout << '0';
      }
    }
  }
}
