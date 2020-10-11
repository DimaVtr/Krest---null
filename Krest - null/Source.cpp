#include <iostream>
#include<ctime>
using namespace std;


void Print(char arr[9])
{
	int count = 0;
	cout << "___________________\n" << endl;
	for (size_t i = 0; i < 9; i++)
	{

		cout << " | " << arr[i] << " | ";
		count++;
		if (count == 3 || count == 6)
		{
			cout << endl;

		}


	}
	cout << "\n___________________\n" << endl;
}

void Play(char token, char arr[9])
{
	int number1 = 0;
	while (true)
	{
		cout << " Enter number" << endl;
		cin >> number1;
		if (number1 > 0 && number1 <= 9 && arr[number1 - 1] != 'X' && arr[number1 - 1] != 'O')
		{
			arr[number1- 1] = token;
			break;
		}
		else
		{
			cout << " Error\n" << endl;
		}
	}

}

void Bot(char token1, char arr[9])
{
	int number2 = 0;
		srand(time(NULL));

	while (true)
	{
		cout << " Enter number 2" << endl;
		number2 = rand() % 9+1;
		
		if (number2 > 0 && number2 <= 9 && arr[number2 - 1] != 'X' && arr[number2 - 1] != 'O')
		{
			arr[number2 - 1] = token1;
			break;
		}
		
	}

}


bool Win(char arr[9], char symbol)
{
	if (arr[0] == symbol && arr[1] == symbol && arr[2] == symbol) return true;
	if (arr[3] == symbol && arr[4] == symbol && arr[5] == symbol) return true;
	if (arr[6] == symbol && arr[7] == symbol && arr[8] == symbol) return true;
	if (arr[0] == symbol && arr[3] == symbol && arr[6] == symbol) return true;
	if (arr[1] == symbol && arr[4] == symbol && arr[7] == symbol) return true;
	if (arr[2] == symbol && arr[5] == symbol && arr[8] == symbol) return true;
	if (arr[0] == symbol && arr[4] == symbol && arr[8] == symbol) return true;
	if (arr[2] == symbol && arr[4] == symbol && arr[6] == symbol) return true;
	return false;
}


int main()
{
	cout << "Hello World!\n";

	char arr[9] = { '1','2','3','4','5','6','7','8','9' };

	int count_2 = 0;  
	
	while (true)
	{
		if (count_2 == 9)
		{
			Print(arr);
			cout << " Nobody win " << endl;
			break;
		}
		else
		{


			Print(arr);
			if (count_2 % 2 == 0)
			{
				Play('X', arr);
				count_2++;
				if (Win(arr, 'X'))
				{
					Print(arr);
					cout << " Win X" << endl;
					break;
				}
				else
				{

				}
			}
			else
			{
					Bot('O', arr);
					count_2++;
					if (Win(arr, 'O'))
					{
						Print(arr);
						cout << " Win O" << endl;
						break;
					}
					else
					{

					}
				

			}
			system("CLS");
		}
	}
	system("pause");
	return 0;
}