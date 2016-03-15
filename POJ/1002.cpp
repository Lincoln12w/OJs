//
//  1002.cpp
//  POJ
//
//  Created by Lincoln on 16/2/15.
//  Copyright © 2016年 Lincoln. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int chars[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

int phoneNumber()
{
    int n;
    cin >> n;
    
    map<string, int> yellowPage;
    
    for(int i = 0; i < n; i++)
    {
        string s, tel;
        cin >> s;
        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                int num = chars[s[i] - 'A'];
                if(num)
                    tel.push_back(num + '0');
                continue;
            }
            if(s[i] == '-')
                continue;
            else
                tel.push_back(s[i]);
        }
        tel.insert(3, 1, '-');
        
        yellowPage[tel]++;
    }
    int flag = 1;
    for(map<string, int>::iterator iter = yellowPage.begin(); iter != yellowPage.end(); iter++)
    {
        if(iter->second > 1)
        {
            flag = 0;
            cout << iter->first << ' ' << iter->second << endl;
        }
    }
    if(flag)
        cout << "No duplicates.";
    
    return 0;
}
