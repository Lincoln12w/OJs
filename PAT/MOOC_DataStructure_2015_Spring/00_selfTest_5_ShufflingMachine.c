#include <iostream>

using namespace std;

class shufflingMachine
{
private:
	int repeat;
	int pos[54];
	int * pOriCards, * pResCards;
	int cardsA[54];
	int cardsB[54];
	void showCard(int card);
public:
	shufflingMachine();
	void shuffle();
	void show();
	friend istream & operator>>(istream & is, shufflingMachine & sm)
	{
		is >> sm.repeat;

		for(int i = 0; i < 54; i++)
			is >> sm.pos[i];
		return is;
	}
};

void shufflingMachine::showCard(int card)
{
	int group = card / 100;
	int number = card % 100;

	switch(group)
	{
	case 0:
		cout << 'S' << number;
		break;
	case 1:
		cout << 'H' << number;
		break;
	case 2:
		cout << 'C' << number;
		break;
	case 3:
		cout << 'D' << number;
		break;
	case 4:
		cout << 'J' << number;
	}
}

shufflingMachine::shufflingMachine()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
			cardsA[i * 13 + j] = i * 100 + j + 1;
	}
	cardsA[52] = 401;
	cardsA[53] = 402;

	pOriCards = cardsA;
	pResCards = cardsB;
}

void shufflingMachine::shuffle()
{
	for(int i = 0; i < repeat; i++)
	{
		for(int j = 0; j < 54; j++)
		{
			pResCards[pos[j] - 1] = pOriCards[j];
		}
		int * pTempCards = pResCards;
		pResCards = pOriCards;
		pOriCards = pTempCards;
	}
}

void shufflingMachine::show()
{
	showCard(pOriCards[0]);
	for(int i = 1; i < 54; i++)
	{
		cout << ' ';
		showCard(pOriCards[i]);
	}
}

int main()
{
	shufflingMachine sm;

	cin >> sm;

	sm.shuffle();
	sm.show();
  
	return 0;
}

