#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int callatz(int n);
vector<int> callatzs;
bool searchcallatzs(int n);

int main()
{
  int n;
  cin >> n;
  int number;
  vector<int> numbers;

  for(int i = 0; i < n; i++)        // 输入就开始排序
  {
    cin >> number;
    vector<int>::iterator iter;
    if(numbers.size() == 0)
    {
      numbers.push_back(number);
    }
    else
    {
      for(iter = numbers.begin(); iter != numbers.end(); iter++)
      {
        if(*iter < number)
        {
          numbers.insert(iter,number);
          break;
        }
      }
    }
    if(iter == numbers.end()) 
      numbers.push_back(number);
    callatz(number);
  }

  vector<int> output;   /* 选择 */
  for(vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
  {
    if(searchcallatzs(*iter))
    {
      output.push_back(*iter);
    }
  }
  for(vector<int>::iterator iter = output.begin(); iter != output.end(); iter++)
  {
    cout << *iter;
    if(iter != (output.end()-1))
      cout << " ";
  }

  return 0;
}

int callatz(int n)
{
    if(n == 1)
    {
        return 0;
    }
    if(n%2)
    {
        if(searchcallatzs((3*n+1)/2))   // 优化： 已经在callatzs列表中的已经计算过，后面的肯定都在，不用重复计算
        {
          callatzs.push_back((3*n+1)/2);
          callatz((3*n+1)/2);
        }
    }
    else
    {
        if(searchcallatzs(n/2))
        {
          callatzs.push_back((n/2));
          callatz(n/2);
        }
    }

    return 1;
}

bool searchcallatzs(int n)    // 是否在callatzs中，两用：插入新元素以及判断是否存在
{
  for(vector<int>::iterator iter = callatzs.begin(); iter != callatzs.end(); iter++)
  {
    if(*iter == n)
      return false;
  }
  return true;
}
