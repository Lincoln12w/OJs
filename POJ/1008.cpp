//
//  1008.cpp
//  POJ
//
//  Created by Lincoln on 16/2/17.
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

string TzolkinDays[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
map<string, int> HabbCalender;

static void HabbCalenderInit();


int mayaCalendar()
{
    int n;
    cin >> n;
    
    HabbCalenderInit();
    
    cout << n << endl;
    
    for(int i = 0; i < n; i++)
    {
        int day, year;
        char dot;
        string month;
        cin >> day >> dot >> month >> year;
        
        int days = day + HabbCalender[month] + year * 365;
        
        year = days / 260;
        month = TzolkinDays[days % 20];
        day = days % 13 + 1;
        
        cout << day << ' ' << month << ' ' << year << endl;
    }
    
    
    return 0;
}

static void HabbCalenderInit()
{
    HabbCalender["pop"] = 0;
    HabbCalender["no"] = 20;
    HabbCalender["zip"] = 40;
    HabbCalender["zotz"] = 60;
    HabbCalender["tzec"] = 80;
    HabbCalender["xul"] = 100;
    HabbCalender["yoxkin"] = 120;
    HabbCalender["mol"] = 140;
    HabbCalender["chen"] = 160;
    HabbCalender["yax"] = 180;
    HabbCalender["zac"] = 200;
    HabbCalender["ceh"] = 220;
    HabbCalender["mac"] = 240;
    HabbCalender["kankin"] = 260;
    HabbCalender["muan"] = 280;
    HabbCalender["pax"] = 300;
    HabbCalender["koyab"] = 320;
    HabbCalender["cumhu"] = 340;
    HabbCalender["uayet"] = 360;
}