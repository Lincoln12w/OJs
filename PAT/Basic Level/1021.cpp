#include<iostream>
#include<string>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main()
{
  string number;
  cin >> number;
  #if 0
  int count[10] = {0,0,0,0,0,0,0,0,0,0}; // for count 0 - 9
  for(int i =0; i < number.size(); i++)
  {
    count[number[i]-'0'] ++;
  }
  int flag = 0;
  for(int i = 0; i < 10; i++)
  {
    if(count[i])
    {
      if(flag)
        cout << endl;
      flag = 1;
      cout << i << ":" << count[i];
    }
  }
  #else
  map<int, int> count;  // using map to make sure there must be some value
  for(int i =0; i < number.size(); i++)
  {
    count[number[i]-'0']++;
  }
  for(map<int, int>::iterator iter = count.begin(); iter != count.end(); iter++)
  {
    if(iter != count.begin())
      cout << endl;
    cout << iter->first << ":" << iter->second;
  }

  #endif

  return 0;
}
