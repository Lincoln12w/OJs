//
//  1003.cpp
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

#define C 0.57721566490153286060651209

static double EulerMaclaurinSummationFormular(double n);

// come from "Overhanging dominoes" by T.R.Sharp in 1954
// http://open.163.com/movie/2006/8/F/4/M6GLI5A07_M6GLMCDF4.html
int hangover()
{
    double length;
    
    while(cin >> length, length != 0.00)
    {
        // if call Sn = 1 + 1/2 + 1/3 + ... + 1/n
        // then ln(n) < Sn < ln(n) + 1
        // more specifically Sn = l(n) + r + 1/2n - 1/12n*n + 1/120n*n*n*n - 1/252n*n*n*n*n*n
        //                      = l(n) + r - B1/n - B2/2n*n - B4/4n*n*n*n - B6/6n*n*n*n*n*n
        //                      > l(n) + r
        //                      which r is 'Euler’s Constant', and Bn is 'Bernoulli numbers'
        double lnn = length + 1 - C;
        int n = exp(lnn);
        if(EulerMaclaurinSummationFormular((double)n) < length)
            n++;
        cout << n - 1 << " card(s)" << endl;
    }
    
    return 0;
}

static double EulerMaclaurinSummationFormular(double n)
{
    return log(n) + C - 1 + 1/(2*n) - 1/(12*n*n) + 1/(120*n*n*n*n) - 1/(252*n*n*n*n*n*n);
}
