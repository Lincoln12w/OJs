#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

bool isearly(string date1, string date2);

int main()
{
  int n;
  cin >> n;
  string firstman, lastman, firstdate, lastdate;
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  firstman = s1;
  lastman = s1;
  firstdate = s2;
  lastdate = s3;
  for(int i = 1; i < n; i++)
  {
    cin >> s1 >> s2 >> s3;
    if(isearly(s2,firstdate))
    {
      firstdate = s2;
      firstman = s1;
    }
    if(isearly(lastdate,s3))
    {
      lastdate = s3;
      lastman = s1;
    }
  }

  cout << firstman << " " << lastman;

  return 0;
}

bool isearly(string date1, string date2)
{
  string d1,d2;
  d1.assign(date1,0,2);
  d2.assign(date2,0,2);
  if(d1 < d2)
    return true;
  if(d1 > d2)
    return false;
  d1.assign(date1,3,2);
  d2.assign(date2,3,2);
  if(d1 < d2)
    return true;
  if(d1 > d2)
    return false;
  d1.assign(date1,6,2);
  d2.assign(date2,6,2);
  if(d1 < d2)
    return true;
  if(d1 > d2)
    return false;
  else
    return false;
}
