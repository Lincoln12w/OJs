#include<iostream>
#include<utility>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::cout;
using std::vector;
using std::string;
using std::pair;
using std::endl;

class Slist
{
  //string addr;
  //int n;
public:
  pair<string, int> psi;
  string next;
  Slist(pair<string, int> pstringint, string nextaddr): psi(pstringint), next(nextaddr) {}
  bool compare(string add){return (psi.first == add)? true:false;}
  void add(vector<pair<string, int> > &vec, string & add) { vec.push_back(psi); add = next; }
};

int main()
{
  string firstaddr;
  int total, K;
  cin >> firstaddr >> total >> K;
  vector<Slist> vsl;
  for(int i = 0; i < total; i++)
  {
    string s1, s2;
    int n;
    pair<string, int> ps;
    cin >> s1 >> n >> s2;
    ps=make_pair(s1, n);
    Slist sl(ps,s2);
    vsl.push_back(sl);
  }
  vector<pair<string ,int> > vpsi;
  while(firstaddr != "-1")          // sort
  {
    for(vector<Slist>::iterator viter = vsl.begin(); viter != vsl.end(); viter++)
    {
      if(viter->psi.first == firstaddr)
      {
        vpsi.push_back(viter->psi);
        firstaddr = viter->next;
        break;
      }
    }
  }
  
  if(K != 1)
  {
    int start = 0;
    int end = K;
    while(total >= end)
    {
      for(int i = start,j = end-1; i < j; i++, j--)
      {
        pair<string, int> ptemp = vpsi[i];
        vpsi[i]=vpsi[j];
        vpsi[j]=ptemp;
      }
      start = end;
      end += K;
    }
  }

  for(vector<pair<string, int> >::iterator viter=vpsi.begin(); viter != vpsi.end(); viter++)
  {
    cout << viter->first << " " << viter->second << " ";
    if(viter != vpsi.end()-1)
    {
      cout << (viter+1)->first << endl;
    }
    else
      cout << -1;
  }

  return 0;
}
