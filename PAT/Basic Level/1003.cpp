#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int check(const string & str);

string pat("PAT");

int main()
{
  int n;
  cin >> n;
  string pat("PAT");
  for(int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    check(str);
  }

  return 0;
}

int check(const string & str)
{
  string::size_type posa, posb, posc;

  if(str == pat)                      /* PAT */
  {
    cout << "YES" << endl;
    return 0;
  }
  if(str.find_first_not_of(pat) != string::npos)            /* have more than A T P */
  {
    cout << "NO" << endl;
    return 0;
  }
  if((posa = str.find('P')) != string::npos)                /* Must have P */
  {
    if((posc = str.find('P', posa+1)) != string::npos)      /* don't have two or more P */
    {
      cout << "NO" << endl;
      return 0;
    }
    if((posb = str.find('T')) != string::npos)              /* Must have T */
    {
      if((posc = str.find('T', posb+1)) != string::npos)    /* don't have two or more T */
      {
        cout << "NO" << endl;
        return 0;
      }
      if((posa > posb) || (posb - posa == 1))               /* xTyPz xTAPy xPTy */
      {
        cout << "NO" << endl;
        return 0;
      }
      if((posc = str.find(pat)) != string::npos)            /* xPATy */
      {
        string a = str.substr(0, posc);
        string b = str.substr(posc+3);
        if(a == b)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
        return 0;
      }
      string a, b, c;                                       /* xPyTz */
      a = str.substr(0,posa);
      b = str.substr(posa+1,posb-posa-1);
      c = str.substr(posb+1);
      int counta, countb, countc;
      counta = a.size();
      countb = b.size();
      countc = c.size();
      if((counta == 0 && countc == 0) || (countc == counta * countb))
      {
        cout << "YES" << endl;
        return 0;
      }
      else
      {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;       // don't forget this

  return 0;
}
