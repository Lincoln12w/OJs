//
//  1004.cpp
//  POJ
//
//  Created by Lincoln on 16/2/16.
//  Copyright © 2016年 Lincoln. All rights reserved.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int financialManagement()
{
    double sum = 0;
    for(int i = 0; i < 12; i++)
    {
        double month;
        cin >> month;
        sum += month;
    }
    cout << '$' << sum / 12 << endl;
    return 0;
}