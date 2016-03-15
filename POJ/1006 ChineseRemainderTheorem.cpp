//
//  1006.cpp
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

#define physicalCycle       23
#define emotionalCycle      28
#define intellectualCycle   33
#define MCD (physicalCycle * emotionalCycle * intellectualCycle)    // need the ()

int gcd(int a, int b);
static int exgcd(int a, int & x, int b, int & y);
static int ChineseRemainderTheorem(int p, int e, int i);

int biorhythms()
{
    int p, e, i, d, n = 1;
    int days;
    
    while(cin >> p >> e >> i >> d)
    {
        if(p == -1 && e == -1 && i == -1 && d == -1)
            break;
        
        days = ChineseRemainderTheorem(p, e, i) - d;
        
        days = (days %= MCD, days > 0 ? days : days + MCD); // take care of the negative situation.
        
        cout << "Case " << n << ": the next triple peak occurs in " << days << " days. " << endl;
        n++;
    }
    
    return 0;
}

// Eucliean Algorithm: gcd(a, b) => return the great common divisor of a and b
// a % b = r => a = b * x + r <=> gcd(a, b) = gcd(b * x + r, b) = gcd(r, b) = gcd(b, r) = gcd(b, a % b)
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// Extended Eucliean Algorithm: exgcd(a, b) => a * x + b * y = gcd(a, b)
// a' = b, b' = a % b => a' * x' + b' * y' = gcd(a', b') = gcd(b, a % b) = gcd(a, b)
//                    => b * x' + (a - a / b * b) * y' = a * y' + b * (x' - a / b * y') = a * x + b * y
// if gcd(a, n) == 1, then a * x + n * y (mod n) = a * x (mod n) = 1 (mod n) => a * x ≡ 1 (mod n)
static int exgcd(int a, int & x, int b, int & y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    
    int r = exgcd(b, y, a % b, x);
    y -= (a / b) * x;
    return r;
}

// Chinese Remainder Theorem
// 有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二。问物几何？   《孙子算经》
// 三人同行七十希，五树梅花廿一支，七子团圆正半月，除百零五使得知      《数学九章》 秦九韶
// https://zh.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86

// x ≡ a1 (mod n1)
// x ≡ a2 (mod n2)
// ...
// x ≡ ak (mod nk)
//
// let [a−1]b denote the multiplicative inverse of a (mod b), => a [a−1]b ≡ 1 (mod b)
// let N denote n1 * n2 * ... * nk, define Nj = N / nj, then ni divides Nj for each i ≠ j
// such that Ni * [Ni-1]ni (mod nj) ≡ 1 if i = j
//                                 0 if i ≠ j
// so x = a1 * N1 * [N1-1]n1 + a2 * N2 * [N2-1]n2 + ... + ak * Nk * [Nk-1]nk
static int ChineseRemainderTheorem(int p, int e, int i)
{
    int Np = MCD / physicalCycle;
    int Ne = MCD / emotionalCycle;
    int Ni = MCD / intellectualCycle;
    int np, ne, ni, y;
    
    exgcd(Np, np, physicalCycle, y);
    exgcd(Ne, ne, emotionalCycle, y);
    exgcd(Ni, ni, intellectualCycle, y);
    
    int ans = p * Np * np + e * Ne * ne + i * Ni * ni;
    
    return ans;
}