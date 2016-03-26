#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

typedef struct list{
    int addr;
    int value;
    int next;
}nodelist;

void print5digit(int addr)          // for replace string with int
{
    if(addr / 10000 == 0)
        cout << '0';
    if(addr / 1000 == 0)
        cout << '0';
    if(addr / 100 == 0)
        cout << '0';
    if(addr / 10 == 0)
        cout << '0';
    cout << addr;
}

int main()
{
    int firstaddr, total, K;
    cin >> firstaddr >> total >> K;
    map<int, nodelist> mlist;
    for(int i = 0; i < total; i++)
    {
        nodelist node;
        cin >> node.addr >> node.value >> node.next;
        mlist[node.addr] = node;
    }
    vector<nodelist> vlist;
    nodelist node = mlist[firstaddr];

    while(node.next != -1)
    {
        vlist.push_back(node);
        node = mlist[node.next];
    }
    vlist.push_back(node);

    if(K != 0 && K != 1)
    {
        int times = vlist.size() / K;
        for(int i = 0; i < times; i++)
        {
            int index1 = i * K;
            int index2 = (i + 1) * K - 1;
            while(index1 < index2)
            {
                nodelist temp = vlist[index1];
                vlist[index1] = vlist[index2];
                vlist[index2] = temp;
                index1 += 1;
                index2 -= 1;
            }
        }
    }

    int n = vlist.size() - 1;

    for(int i = 0; i < n; i++)
    {
        print5digit(vlist[i].addr);
        cout << ' ' << vlist[i].value << ' ';
        print5digit(vlist[i + 1].addr); 
        cout << endl;
    }

    print5digit(vlist[n].addr);
    cout << ' ' << vlist[n].value << ' ' << "-1" << endl;
    
    return 0;
}
