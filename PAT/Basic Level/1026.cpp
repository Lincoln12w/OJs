#include <iostream>

using namespace std;

int main1()
{
  int time1, time2;
  
    cin >> time1 >> time2;
  
    int seconds = (time2 - time1) / 100;
    if((time2 - time1) % 100 >=50)
    seconds++;
  
    int minutes = seconds / 60;
    seconds %= 60;
  
    int hours = minutes / 60;
    minutes %= 60;
  
    cout << (hours >10 ? "" : "0") << hours << ':' << (minutes >10 ? "" : "0") << minutes << ':' << (seconds >10 ? "" : "0") <<seconds;
  
    return 0;  
}