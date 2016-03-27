#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef struct {
    int ID;
    int dscore;
    int cscore;
    unsigned long long index;
}student;

bool order(const student & s1, const student & s2)
{
    if(s1.index > s2.index)
        return true;
    if(s1.index == s2.index)
    {
        if(s1.ID < s2.ID)
            return true;
    }
    return false;
}

int main()
{
    int n, low, high;
    cin >> n >> low >> high;
    vector<student> ddcc,ddc,dc,oth;
    for(int i = 0; i < n; i++)
    {
        int num,d,c;
        cin >> num >> d >> c;
        student xman;
        xman.cscore = c;
        xman.dscore = d;
        xman.ID = num;
        //xman.index = ((c + d) * 1000 + d + 1) * 100000000 - num;        // long long value not ok
        xman.index = (c + d) * 1000 + d;
        if(d >= low && c >= low)
            if(d >= high)
                if(c >= high)
                    ddcc.push_back(xman);
                else
                    ddc.push_back(xman);
            else
                if(d >= c)
                    dc.push_back(xman);
                else
                    oth.push_back(xman);
    }

    sort(ddcc.begin(), ddcc.end(), order);
    sort(ddc.begin(), ddc.end(), order);
    sort(dc.begin(), dc.end(), order);
    sort(oth.begin(), oth.end(), order);

    cout << ddcc.size() + ddc.size() + dc.size() + oth.size();
    for(vector<student>::iterator iter = ddcc.begin(); iter != ddcc.end(); iter++)
        cout << '\n' << iter->ID << " " << iter->dscore << " " << iter->cscore;
    for(vector<student>::iterator iter = ddc.begin(); iter != ddc.end(); iter++)
        cout << '\n' << iter->ID << " " << iter->dscore << " " << iter->cscore;
    for(vector<student>::iterator iter = dc.begin(); iter != dc.end(); iter++)
        cout << '\n' << iter->ID << " " << iter->dscore << " " << iter->cscore;
    for(vector<student>::iterator iter = oth.begin(); iter != oth.end(); iter++)
        cout << '\n' << iter->ID << " " << iter->dscore << " " << iter->cscore;

    return 0;
}
