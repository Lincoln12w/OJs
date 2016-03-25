#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()      /* 1ms 292kB */
{
    int total = 0;
    string number;

    cin >> number;

    for(int i = 0; i < number.size(); i++)
    {
        total += number[i] - '0';
    }
    int array[3] = {0,0,0};             //n小于10的100次 因此和小于900
    int i = 2;
    while(total)
    {
        array[i] = total % 10;
        total = total / 10;
        i--;
    }
    int flag = 0;
    string str[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
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
