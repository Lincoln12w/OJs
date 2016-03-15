//
//  1001.cpp
//  POJ
//
//  Created by Lincoln on 16/2/15.
//  Copyright © 2016年 Lincoln. All rights reserved.
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

typedef string::size_type sizeT;

static string exp(string number, int n);
static string multiplyTwoString(string s1, string s2);

static string stringMultiply(const string & s, int n);
static void stringAdd(string & s1, string & s2);

int exponentiation()
{
    string s;
    int n;
    
    while(cin >> s >> n)
    {
        string number = s;
        sizeT len = 0;
        
        // remove the decimal point
        sizeT pos = s.find('.');
        if(pos != string::npos)     // for interger
        {
            len = s.size() - pos - 1;
            number.assign(s, 0, pos);
            number.append(s, pos + 1, len);
        }
        
        string temp = exp(number, n);
        
        // add decimal point
        pos = temp.size() - len * n;
        sizeT beg = temp.find_first_not_of('0');
        if(beg == string::npos)     // for 0
        {
            cout << '0';
            continue;
        }
        sizeT end = temp.find_last_not_of('0');
        if(beg < pos)
            cout << temp.substr(beg, pos - beg);    // attention the usage of substr
        if(end > pos)
            cout << '.' << temp.substr(pos, end - pos + 1);
        if(n != 1)                  // for the output format
            cout << endl;
    }
    
    return 0;
}

static string exp(string number, int n)
{
    string result;
    
    if(n == 1)
        return number;

    result = multiplyTwoString(exp(number, n / 2), exp(number, n / 2));
    
    if(n % 2)
        result = multiplyTwoString(result, number);
    
    return result;
}

static string multiplyTwoString(string s1, string s2)
{
    string result = "";
    sizeT len = s2.size();
    
    for(sizeT i = len; i > 0; i--)
    {
        string tmp = stringMultiply(s1, s2[i - 1] - '0');
        tmp.append(len - i, '0');
        stringAdd(result, tmp);
    }
    
    return result;
}

static string stringMultiply(const string & s, int n)
{
    string result = s;
    
    int flag = 0;
    for(sizeT i = s.size(); i > 0; i--)
    {
        int tmp = (result[i - 1] - '0') * n + flag;
        result[i - 1] = tmp % 10 + '0';
        flag = tmp / 10;
    }
    if(flag)
        result.insert(0, 1, (char)(flag + '0'));
    
    return result;
}

static void stringAdd(string & s1, string & s2)
{
    sizeT len1 = s1.size(), len2 = s2.size();
    
    if(len1 > len2)
        s2.insert(0, len1 - len2, '0');
    if(len2 > len1)
        s1.insert(0, len2 - len1, '0');
    
    int flag = 0;
    for(sizeT i = s1.size(); i > 0; i--)
    {
        int tmp = s1[i -1 ] - '0' + s2[i - 1] - '0' + flag;
        s1[i - 1] = tmp % 10 + '0';     // causion the '0' and 0
        flag = tmp / 10;
    }
    if(flag)
        s1.insert(0, 1, (char)(flag + '0'));
}