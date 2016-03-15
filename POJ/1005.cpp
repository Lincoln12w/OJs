//
//  1005.cpp
//  POJ
//
//  Created by Lincoln on 16/2/16.
//  Copyright © 2016年 Lincoln. All rights reserved.
//

#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

#define pi 3.141592653589

int iThinkINeedaHouseboat()
{
    int n, year;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        
        // eroded area is 50 * years, also pi * r * r / 2;
        double radius = sqrt(x * x + y * y);
        double areas = pi * radius * radius / 2;
        year = areas / 50;
        if(year * 50 < areas)
            year++;
        
        cout << "Property " << i + 1 << ": This property will begin eroding in year " << year << "." << endl;
    }
    cout << "END OF OUTPUT.";
    
    return 0;
}