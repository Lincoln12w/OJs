#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::istringstream;

int main()
{
  string str;
  getline(cin, str);
  istringstream iss(str);     // 用于确定输入的结束
  int a,n;
  vector<int> as;
  vector<int> ns;
  while(iss >> a >> n)
  {
    if(n)
    {
      as.push_back(a);
      ns.push_back(n);
    }
  }
  if(as.size() == 0)        // 还真是这个问题啊 f(x) = a; 导数为0的情况
  {
    cout << "0 0";
    return 0;
  }
  for(vector<int>::iterator aiter=as.begin(), niter=ns.begin(); aiter!=as.end(), niter!=ns.end(); aiter++, niter++)
  {
    *aiter = (*aiter)*(*niter);
    cout << *aiter << " ";
    *niter = *niter - 1;
    cout << *niter;
    if(niter != (ns.end()-1))
      cout << " ";
  }

  return 0;
}
