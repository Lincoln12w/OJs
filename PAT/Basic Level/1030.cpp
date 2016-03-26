#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

int mainq()
{
    int n, p;
    cin >> n >> p;
    
    vector<unsigned> numbers;
    unsigned number;
    
    for(int i = 0; i < n; i++)
    {
        cin >> number;
        numbers.push_back(number);
    }
    
    sort(numbers.begin(), numbers.end());
    
    int max = 1;
    
    for(int i = 0; i < n; i++)
    {
        unsigned a = numbers[i] * p;				// if overflow, it will turn to negative
        int j = i + max;
        while(j < n)
        {
            if(a < numbers[j])
                break;
            j++;
        }
        max = j - i;
    }
    
    cout << max;
    
    return 0;
}