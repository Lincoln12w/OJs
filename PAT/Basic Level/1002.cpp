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
    int array[3] = {0,0,0};     //n小于10的100次 因此和小于999
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
            #if 0
            switch(array[i])
            {
                case 1:
                    cout << "yi";
                    break;
                case 2:
                    cout << "er";
                    break;
                case 3:
                    cout << "san";
                    break;
                case 4:
                    cout << "si";
                    break;
                case 5:
                    cout << "wu";
                    break;
                case 6:
                    cout << "liu";
                    break;
                case 7:
                    cout << "qi";
                    break;
                case 8:
                    cout << "ba";
                    break;
                case 9:
                    cout << "jiu";
                    break;
                case 0:
                    cout << "ling";
                    break;
            }
            #else
            cout << str[array[i]];      // 时间和空间上没区别
            #endif
            flag = 1;
        }
    }
}
