#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char num;
    int total = 0;
    while((num = cin.get()) != '\n' )
    {
        total += num - '0';
    }
    if(total == 0)            // for 0
    {
      cout << "zero";
      return 0;
    }
    int array[3] = {0,0,0};     //n小于10的100次 因此和小于999
    int i = 2;
    while(total)
    {
        array[i] = total % 10;
        total = total / 10;
        i--;
    }
    int flag = 0;
    string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i = 0; i < 3; i++)
    {
        if(array[i] || flag)
        {
            if(flag)
                cout << " ";
            cout << str[array[i]];      // 时间和空间上没区别
            flag = 1;
        }
    }
}
