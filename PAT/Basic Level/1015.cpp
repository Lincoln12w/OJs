#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;

struct Score
{
  int number;
  int dscore;
  int cscore;
  int total;
};

bool isbigger(const Score & s1, const Score & s2);

#if 1
int main()
{
  int n, low, high;
  cin >> n >> low >> high;
  list<Score> ddcc,ddc,dc,oth;
  for(int i = 0; i < n; i++)
  {
    int num,d,c;
    cin >> num >> d >> c;
    struct Score scor;
    scor.cscore = c;
    scor.dscore = d;
    scor.number = num;
    scor.total = c + d;
    if(d >= low && c >= low)
    {
      if(d >= high)
      {
        if(c >= high)
        {
          ddcc.push_back(scor);
        }
        else
        {
          ddc.push_back(scor);
        }
      }
      else
      {
        if(d > c)
        {
          dc.push_back(scor);
        }
        else
        {
          oth.push_back(scor);
        }
      }
    }
  }
  //stable_sort(ddcc.begin(),ddcc.end(),isbigger);
  ddcc.sort(isbigger);
  ddc.sort(isbigger);
  dc.sort(isbigger);
  oth.sort(isbigger);
  //stable_sort(ddc.begin(),ddc.end(),isbigger);
  //stable_sort(dc.begin(),dc.end(),isbigger);
  //stable_sort(oth.begin(),oth.end(),isbigger);

  cout << ddcc.size() + ddc.size() + dc.size() + oth.size() << endl;
  for(list<Score>::iterator iter = ddcc.begin(); iter != ddcc.end(); iter++)
  {
    cout << iter->number << " " << iter->dscore << " " << iter->cscore << endl;
  }
  for(list<Score>::iterator iter = ddc.begin(); iter != ddc.end(); iter++)
  {
    cout << iter->number << " " << iter->dscore << " " << iter->cscore << endl;
  }
  for(list<Score>::iterator iter = dc.begin(); iter != dc.end(); iter++)
  {
    cout << iter->number << " " << iter->dscore << " " << iter->cscore << endl;
  }
  int i = 1;
  for(list<Score>::iterator iter = oth.begin(); iter != oth.end(); iter++)
  {
    cout << iter->number << " " << iter->dscore << " " << iter->cscore;
    i ++;
    if(i == oth.size())
      cout << endl;
  }

  return 0;
}
#else
int main()
{
  int n, low, high;
  cin >> n >> low >> high;
  vector<Score> students;
  vector<int> ddcc,ddc,dc,oth;
  for(int i = 0; i < n; i++)
  {
    int num,d,c;
    cin >> num >> d >> c;
    struct Score scor;
    scor.cscore = c;
    scor.dscore = d;
    scor.number = num;
    scor.total = c + d;
    students.push_back(scor)
    if(d >= low && c >= low)
    {
      if(d >= high)
      {
        if(c >= high)
        {
          ddcc.push_back(i);
        }
        else
        {
          ddc.push_back(i);
        }
      }
      else
      {
        if(d > c)
        {
          dc.push_back(i);
        }
        else
        {
          oth.push_back(i);
        }
      }
    }
  }
}



#endif

bool isbigger(const Score & s1, const Score & s2)
{
  if(s1.total > s2.total)
    return true;
  if(s1.total == s2.total)
  {
    if(s1.dscore > s2.dscore)
      return true;
    if(s1.dscore == s2.dscore)
    {
      if(s1.number < s2.number)
        return true;
    }
  }
  return false;
}
