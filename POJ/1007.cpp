//
//  1007.cpp
//  POJ
//
//  Created by Lincoln on 16/2/16.
//  Copyright © 2016年 Lincoln. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

int dnaSorting()
{
    int num, len;
    int Ccnt, Gcnt, Tcnt;
    
    cin >> len >> num;
    
    map<int, vector<string> > dnas;
    string dna;
    int measure;
    
    for(int i = 0; i < num; i++)
    {
        Ccnt = Gcnt = Tcnt = measure = 0;
        cin >> dna;
        for(int j = 0; j < len; j++)
        {
            switch (dna[j])
            {
                case 'A':
                    measure += Ccnt + Gcnt + Tcnt;
                    break;
                case 'C':
                    measure += Gcnt + Tcnt;
                    Ccnt++;
                    break;
                case 'G':
                    measure += Tcnt;
                    Gcnt++;
                    break;
                case 'T':
                    Tcnt++;
                    break;
                default:
                    cout << "Error inputs!\n";
            }
        }
        dnas[measure].push_back(dna);
    }
    for(map<int, vector<string> >::iterator iter = dnas.begin(); iter != dnas.end(); iter++)
    {
        vector<string> tmp = iter->second;
        for(vector<string>::iterator jter = tmp.begin(); jter != tmp.end(); jter++)
            cout << *jter << endl;
    }
    return 0;
}