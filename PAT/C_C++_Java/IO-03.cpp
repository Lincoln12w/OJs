#include<iostream>
#include <iomanip>

int main()
{
	int a, b, c, d;
  	
  	std::cin >> a >> b >> c >> d;
  
  	int sum = a+b+c+d;
  
  	std::cout << "Sum = " << sum << "; Average = " << std::fixed << std::setprecision(1) << sum/4.0;
  
  	return 0;
}