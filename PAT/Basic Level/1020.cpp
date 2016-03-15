#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ios;

int main()
{
  int type, desire;
  cin >> type >> desire;
  vector<double> store, cost, price;
  for(int i = 0; i < type; i++)
  {
    double st;
    cin >> st;
    store.push_back(st);
  }
  for(int i = 0; i < type; i++)
  {
    double ct;
    cin >> ct;
    cost.push_back(ct);
  }
  for(int i = 0; i < type; i++)   // get price
  {
    price.push_back(cost[i]/store[i]);
  }
  for(int i = 0; i < type; i++)   // sort by price
  {
    for(int j = i+1; j < type; j++)
    {
      if(price[i] < price[j])
      {
        double temps = store[i];
        store[i] = store[j];
        store[j] = temps;
        temps = cost[i];
        cost[i] = cost[j];
        cost[j] = temps;
        temps = price[i];
        price[i] = price[j];
        price[j] = temps;
      }
    }
  }
  int n = 0;
  double total = 0;
  while(n != desire && store.size())      // count
  {
    if(store[0] <= (desire-n))
    {
      n += store[0];
      total += cost[0];
      cost.erase(cost.begin());
      store.erase(store.begin());
      price.erase(price.begin());
    }
    else
    {
      total += price[0] * (desire - n);
      n = desire;
    }
  }
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << total ;

  return 0;
}
