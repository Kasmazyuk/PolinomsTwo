#include "TPolinom.h"
#include <iostream>

using namespace std;

void main() {
	int count;
	setlocale(LC_ALL, "Russian");
	cout << "Выберите пункт меню:" << endl <<"1. Введите P и Q" << endl << "2. Добавить моном к P" << endl << "3. Вывод на экран результата" << endl << "4. Сравнение P и Q" << endl;
	cin >> count;
	switch (count)
	{
	case 1: 
		{
			TPolinom <TMonom> *A = new TPolinom<TMonom>; 

			TMonom *B = 3xyz;

		break;
		}
	case 2: 
		{

		break;
		}
	case 3: 
		{

		break;
		}
	case 4: 
		{

		break;
		}

	default:
		break;
	}


	system("PAUSE");


}


