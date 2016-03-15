#include <iostream>

int main()
{
	int a, b;
	char op;

	std::cin >> a >> op >> b;
	switch(op)
	{
	case '+':
		std::cout << a + b;
		break;
	case '-':
		std::cout << a - b;
		break;
	case '*':
		std::cout << a * b;
		break;
	case '/':
		std::cout << a / b;
		break;
	case '%':
		std::cout << a % b;
		break;
	default:
		std::cout << "ERROR";
	}

	return 0;
}