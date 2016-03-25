#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()      /* 1ms 316kB */
{
    int n;
    cin >> n;

    int cnt = 0;
    while(n != 1)
    {
        if(n % 2)
            n = 3 * n + 1;
        n /= 2;
        cnt ++;
    }

    cout << cnt;

    return 0;
}
