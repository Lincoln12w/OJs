//
//  1010.cpp
//  POJ
//
//  Created by Lincoln on 16/2/19.
//  Copyright © 2016年 Lincoln. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/*
 
 1 2 3 0
 7 4 0
 1 1 1 1 1 1 0
 6 2 3 0
 
 */

static void dealStampsAsCustomsNeed(const vector<int> & stampValue, int customValue);
static void dealStamps(const vector<int> &stampValue, int pos, vector<int>  & bestStamps, int customValue, vector<int> stamps, int & maxType, int curType, bool & isTie, int previousStamp, int sameStampCnt);

int stamps()
{
    vector<int> stampValue, customValue;
    int value;
    int line = 0;
    while(cin >> value)
    {
        if(value != 0)
            if(line == 0)
                stampValue.push_back(value);
            else
                customValue.push_back(value);
        else
            if(line == 0)
                line = 1;
            else
            {
                // solve for one pair inputs case:
                std::sort(stampValue.begin(), stampValue.end());
                for(int i = 0; i < customValue.size(); i++)
                {
                    dealStampsAsCustomsNeed(stampValue, customValue[i]);
                }
                line = 0;
                stampValue.clear();
                customValue.clear();
            }
    }
    return 0;
}

// at most 4 stamps // got TLE  T^T
static void dealStampsAsCustomsNeed(const vector<int> & stampValue, int customValue)
{
    vector<int> bestStamps;
    bool isnone = false;
    bool isTie = false;
    int maxType = 0;
    
    vector<int> stamps;
    
    int previousStamp = 0;
    int sameStampCnt = 0;
    
    dealStamps(stampValue, (int)stampValue.size() - 1, bestStamps, customValue, stamps, maxType, 1, isTie, previousStamp, sameStampCnt);
    
    /*
    for(int i = (int)stampValue.size() - 1; i >= 0; i--)
    {
        int stamp = stampValue[i];
        
        // short for more than 5 stamps have the same value.
        if(previousStamp != stamp)
        {
            previousStamp = stamp;
            sameStampCnt = 1;
        }
        else
        {
            if(sameStampCnt == 5)
                continue;
            sameStampCnt++;
        }
        
        // short for already get maxType
        if(maxType > i + 1)
            break;
        
        dealStamps(stampValue, i, bestStamps, customValue, stamps, maxType, 0, isTie);
    }
     */
    
    if(bestStamps.size() == 0)
        isnone = true;
    
    // format the output
    if(isnone)
        cout << customValue << " ---- none" << endl;
    else if(isTie)
        cout << customValue << " (" << maxType + 1 << "): tie" << endl;
    else
    {
        cout << customValue << " (" << maxType + 1 << "):";
        // cout the value of stamps
        for(int i = (int)bestStamps.size() - 1; i >= 0; i--)
            cout << ' ' << bestStamps[i];
        cout << endl;
    }
}

static void dealStamps(const vector<int> &stampValue, int pos, vector<int>  & bestStamps, int customValue, vector<int> stamps, int & maxType, int curType, bool & isTie, int previousStamp, int sameStampCnt)
{
    int newCurType = curType;
    
    for(int i = pos; i >= 0; i--)
    {
        // cannot find solution better the maxType solution already found.
        if(maxType > (curType + i))
            break;
        
        int stamp = stampValue[i];
        
        // this stamp cannot be one of the solution.
        if(customValue < stamp)
            continue;
        
        if(i != pos)
            newCurType = curType + 1;
        
        // cannot use more than 4 stamps.
        if(stamps.size() == 3 && stamp > customValue)
            continue;
        
        vector<int> newStamps = stamps;
        newStamps.push_back(stamp);
        int newCustomValue = customValue - stamp;
        
        // a new solution found
        if(newCustomValue == 0)
        {
            // check if Tie
            if(curType == maxType)
            {
                if(bestStamps.size() == newStamps.size())
                    isTie = true;
                else
                {
                    bestStamps = bestStamps.size() > newStamps.size() ? newStamps : bestStamps;
                    isTie = false;
                }
            }
            if(curType > maxType)
            {
                bestStamps = newStamps;
                maxType = curType;
                isTie = false;
            }
            // do not need continue. because this is the shortest case in this loop.
            return;
        }
        dealStamps(stampValue, i, bestStamps, newCustomValue, newStamps, maxType, newCurType, isTie, previousStamp, sameStampCnt);
    }
}
