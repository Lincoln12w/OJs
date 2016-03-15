#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int callatz(int n);

int main()
{
    int n;
    cin >> n;
    if(n > 1000 || n <= 0)
    {
        //cout << "Error Input!\n" << endl;
        return 0;
    }

    callatz(n);

    return 0;
}

int callatz(int n)
{
    static int count;

    if(n == 1)
    {
        cout << count;
        return 0;
    }
    count ++;
    if(n%2)
    {
        callatz((3*n+2)/2);
    }
    else
    {
        callatz(n/2);
    }

    return 1;
}
