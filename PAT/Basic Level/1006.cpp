#include <iostream>

using std::cin;
using std::cout;

int main()
{
  int number;
  cin >> number;

  int bai = number / 100;
  number %= 100;
  int shi = number / 10;
  number %= 10;

  for(int i = 0; i < bai; i++)
    cout <<'B';
  for(int i = 0; i < shi; i++)
    cout << 'S';
  for(int i = 0; i < number; i++)
    cout << i + 1;

  return 0;
}
