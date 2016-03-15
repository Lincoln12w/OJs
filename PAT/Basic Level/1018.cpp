#include<iostream>

using std::cin;
using std::cout;
using std::endl;

bool compare(char a,char b);
void winner(int * W,char ch);
char max(int * Arr);

int main()
{
  int n;
  cin >> n;
  int A[3] = {0,0,0}, B[3] = {0,0,0};    // for B C J
  int win[3] = {0,0,0};                   // for result
  for(int i = 0; i < n; i++)
  {
    char a,b;
    cin >> a >> b;
    if(a == b)        // 平局
    {
      win[1]++;
      continue;
    }
    if(compare(a,b))
    {
      winner(A, a);
      win[0]++;       // A 赢
    }
    else
    {
      winner(B, b);
      win[2]++;       // B 赢
    }
  }
  cout << win[0] << " " << win[1] << " " << win[2] << endl;
  cout << win[2] << " " << win[1] << " " << win[0] << endl;
  cout << max(A) << " " << max(B);

  return 0;
}

bool compare(char a,char b)
{
  switch(a)
  {
    case 'C':
      if(b == 'B')
        return false;
      else
        return true;
      break;
    case 'B':
      if(b == 'J')
        return false;
      else
        return true;
      break;
    case 'J':
      if(b == 'C')
        return false;
      else
        return true;
      break;
    default:
      return false;
  }
}

void winner(int * W, char ch)
{
  switch(ch)
  {
    case 'B':
      W[0]++;
      break;
    case 'C':
      W[1]++;
      break;
    case 'J':
      W[2]++;
      break;
    default:
      ;
  }
}

char max(int * Arr)
{
  int maxx = 0;
  int status;
  for(int i = 0; i < 3; i++)
  {
      if(Arr[i] > maxx)
      {
        maxx = Arr[i];
        status = i;
      }
  }
  if(status == 0)
    return 'B';
  if(status == 1)
    return 'C';
  if(status == 2)
    return 'J';
}
