#include <iostream>
#include <deque>

using std::cin;
using std::cout;
using std::deque;

int main()
{
  int count, pos;
  cin >> count >> pos;
  deque<int> array;
  int number;
  for(int i = 0; i < count; i++)      // cin
  {
    cin >> number;
    array.push_back(number);
  }
  for(int i = 0; i < pos; i++)        // shift     using pop and push
  {
    deque<int>::reverse_iterator riter = array.rbegin();
    number = *riter;
    array.pop_back();
    array.push_front(number);
  }
  for(deque<int>::iterator iter = array.begin(); iter != array.end(); iter++)
  {
    cout << *iter;
    if(iter != (array.end()-1))
      cout << " ";
  }
}
