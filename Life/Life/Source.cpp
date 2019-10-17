#include <iostream>
using namespace std;
const int sofr = 20, sofc = 30; //20*30, rows*columns, size of field

void firstStep(bool field[sofr + 2][sofc + 2])
{
	field[sofr / 2][sofc / 2 - 2] = true;
	field[sofr / 2 - 1][sofc / 2 - 1] = true;
	field[sofr / 2][sofc / 2 - 1] = true;
	field[sofr / 2 + 1][sofc / 2 - 1] = true;
	field[sofr / 2 - 2][sofc / 2] = true;
	field[sofr / 2 + 2][sofc / 2] = true;
	field[sofr / 2 - 1][sofc / 2 + 1] = true;
	field[sofr / 2][sofc / 2 + 1] = true;
	field[sofr / 2 + 1][sofc / 2 + 1] = true;
	field[sofr / 2][sofc / 2 + 2] = true;
}

void paint(bool field[sofr + 2][sofc + 2]) //true = life, first&last row&column are false
{
	for (int i = 0; i < sofr + 2; i++)
	{
		for (int j = 0; j < sofc + 2; j++)
		{
			if (field[i][j] == true)
				cout << "|+|";
			else
				cout << "| |";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void isLife(bool field[sofr + 2][sofc + 2], bool nextfield[sofr + 2][sofc + 2])
{
	for (int i = 1; i < sofr + 1; i++)
		for (int j = 1; j < sofc + 1; j++)
		{
			int life = 0;
			for (int i1 = -1; i1 < 2; i1++)
				for (int j1 = -1; j1 < 2; j1++)//how many life around
				{
					if (i1 == 0 && j1 == 0)//self
						continue;
					if (field[i + i1][j + j1])//is life
						life++;
				}
			if (field[i][j])//is life, need 2 or 3 life around to stay life
			{
				if (life == 2 || life == 3)
					nextfield[i][j] = true;
				else
					nextfield[i][j] = false;
			}
			else//no life, need 3 life around to become life
			{
				if (life == 3)
					nextfield[i][j] = true;
				else
					nextfield[i][j] = false;
			}
		}
}

int main()
{
	bool field[sofr + 2][sofc + 2];
	bool nextfield[sofr + 2][sofc + 2];
	for (int i = 0; i < sofr + 2; i++)
		for (int j = 0; j < sofc + 2; j++)
		{
			field[i][j] = false;
			nextfield[i][j] = false;
		}

	firstStep(field);

	bool death = true;//exit

	do
	{
		paint(field);
		isLife(field, nextfield);
		for (int i = 1; i < sofr + 1; i++)
			for (int j = 1; j < sofc + 1; j++)
				if (nextfield[i][j])
					death = false;
		//system("pause");
		swap(field, nextfield);
	} while (death == false);

	cout << "There is no life here. Game over." << endl;
	system("pause");
	return 0;
}