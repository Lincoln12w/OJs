#include <iostream>
#include <string>
//#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
//using std::vector;

//class students
//{
 //   string name;
 //   string number;
//    int grade;
//public:
//    students(string name, string number, int grade);
 //   void show();
//};

//students::students(string nam, string num, int gra)
//{
 //   name = nam;
 //   number = num;
 //   grade = gra;
//}

//void students::show()
//{
//    cout << name << ' ' << number << ' ' << grade << endl;
//}
//#include <vector>

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
