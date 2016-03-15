#include<string>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  int A,Da,B,Db;    // A B 均小于10的10次 故不用担心溢出问题
  cin >> A >> Da >> B >> Db;
  int addA = 0, addB = 0;
  while(A)
  {
    if(A%10 == Da)
      addA = addA * 10 + Da;
    A = A/10;
  }
  while(B)
  {
    if(B%10 == Db)
      addB = addB * 10 + Db;
    B = B/10;
  }
  cout << addA + addB;

  return 0;
}
