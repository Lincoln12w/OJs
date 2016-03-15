#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;

int main()
{
  string s1,s2,s3,s4;
  cin >> s1 >> s2 >> s3 >> s4;
  string day[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
  for(int i = 0;i < s1.size() && i < s2.size(); i++)      // 主要问题在于界定有效字符
  {
    if(s1[i] == s2[i] && s1[i] <= 'G' && s1[i] >= 'A')      // 大写字母
    {
      cout << day[s1[i] - 'A'] << " ";
      for(int j = i+1; j < s1.size() && j < s2.size(); j++)
      {
        if(s1[j] == s2[j] && (isdigit(s1[j]) || (s1[j] >= 'A' && s1[j] <= 'N')))
        {
          if(isdigit(s1[j]))
            cout << "0" << s1[j] << ":";
          else
            cout << s1[j] - 'A' + 10 << ":";
          break;
        }
      }
      break;
    }
  }
  for(int i = 0;i < s3.size() && i < s4.size(); i++)
  {
    if(s3[i] == s4[i] && isalpha(s3[i]))  // 英文字母
    {
      if(i < 10)
        cout << "0" << i;
      else
        cout << i;
      break;
    }
  }

  return 0;
}
