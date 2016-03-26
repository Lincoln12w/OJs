#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()        // only for max and min, not sort
{
    int n;
    cin >> n;
    string a,b;
    int c;
    cin >> a;
    string maxname(a), minname(a);
    cin >> b;
    string maxnumber(b), minnumber(b);
    cin >> c;
    int maxgrade = c, mingrade = c;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;
        if(c > maxgrade)
        {
            maxname = a;
            maxnumber = b;
            maxgrade = c;
        }
        if(c < mingrade)
        {
            minname =a;
            minnumber = b;
            mingrade = c;
        }
    }
    cout << maxname << " " << maxnumber << endl;
    cout << minname << " " << minnumber << endl;

}
