#include <iostream>
#include <stdlib.h>
#include "my_fun.cpp"
#include "MyVector.h"
#include "ISubscriber.h"
#include "IPublisher.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char str0[]{ "TopGear" };
	char str1[]{ "National Geographic" };
	char str2[]{ "People" };
	char str3[]{ "BusinessWeek" };
	char str4[]{ "PROSport" };
	char str5[]{ "Forbes" };

	ConcretePublisher publishers[6]
	{
		ConcretePublisher(str0),
		ConcretePublisher(str1),
		ConcretePublisher(str2),
		ConcretePublisher(str3),
		ConcretePublisher(str4),
		ConcretePublisher(str5)
	};

	char str00[]{"Vidov"};
	char str01[]{ "Kramar" };
	char str02[]{ "Kostin" };
	ConcreteSubscriber people[3]
	{
		ConcreteSubscriber(str00),
		ConcreteSubscriber(str01),
		ConcreteSubscriber(str02)
	};
	
	for (int i = 0; i < ConcreteSubscriber::counter; i++)		//очистить файлы
	{
		people[i].clear_file();	
	}

	while(1)
	{
		int choise;
		cout << "|1| Выбрать пользователя\n|2| START BUTTON\n|0| Выход\n>";		cin >> choise;
		switch(choise)
		{
			case 1:
			{
				int ch_person;
				cout << "Выберите пользователя:" << endl;
				for (int i = 0; i < ConcreteSubscriber::counter; i++)
				{
					cout << i + 1 << ") " << people[i].ret_name() << endl;
				}
				cin >> ch_person;
				ch_person--;
				int ch = -1;		// т.к. 0 - выход из вайла для выбора пользователя
				while (ch != 0)
				{

					cout << "|1| Подписаться на журналы\n|2| Отписаться от журналов\n|0| Выход\n>";		cin >> ch;
					switch (ch)
					{
					case 1:
						int ch2;
						cout << "\nЖурналы, доступные для подписки:\n1)TopGear\t\t\t";
						if (publishers[0].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n2)National Geographic\t\t";
						if (publishers[1].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n3)People\t\t\t";
						if (publishers[2].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n4)BusinessWeek\t\t\t";
						if (publishers[3].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n5)PROSport\t\t\t";
						if (publishers[4].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n6)Forbes\t\t\t";
						if (publishers[5].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n0)Назад\n>";
						cin >> ch2;
						switch (ch2)
						{
						case 1:
							if(!publishers[0].plus_or_minus(people[ch_person]))
								publishers[0].subscribe(people[ch_person]);		
							break;
						case 2:
							if (!publishers[1].plus_or_minus(people[ch_person]))
								publishers[1].subscribe(people[ch_person]);		
							break;
						case 3:
							if (!publishers[2].plus_or_minus(people[ch_person]))
								publishers[2].subscribe(people[ch_person]);		
							break;
						case 4:
							if (!publishers[3].plus_or_minus(people[ch_person]))
								publishers[3].subscribe(people[ch_person]);		
							break;
						case 5:
							if (!publishers[4].plus_or_minus(people[ch_person]))
								publishers[4].subscribe(people[ch_person]);		
							break;
						case 6:
							if (!publishers[5].plus_or_minus(people[ch_person]))
								publishers[5].subscribe(people[ch_person]);		
							break;
						case 0:		break;
						}
						break;
					case 2:
						int ch3;
						cout << "\nОтписаться от:\n1)TopGear\t\t\t";
						if (publishers[0].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n2)National Geographic\t\t";
						if (publishers[1].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n3)People\t\t\t";
						if (publishers[2].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n4)BusinessWeek\t\t\t";
						if (publishers[3].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n5)PROSport\t\t\t";
						if (publishers[4].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n6)Forbes\t\t\t";
						if (publishers[5].plus_or_minus(people[ch_person])) cout << '+';		else	cout << '-';
						cout << "\n0)Назад\n>";
						cin >> ch3;
						switch (ch3)
						{
						case 1:
							publishers[0].unsubscribe(people[ch_person]);		break;
						case 2:
							publishers[1].unsubscribe(people[ch_person]);		break;
						case 3:
							publishers[2].unsubscribe(people[ch_person]);		break;
						case 4:
							publishers[3].unsubscribe(people[ch_person]);		break;
						case 5:
							publishers[4].unsubscribe(people[ch_person]);		break;
						case 6:
							publishers[5].unsubscribe(people[ch_person]);		break;
						case 0:		break;
						}
						break;
					case 0:
						break;
					}
					system("cls");
				}
				break;
			}
			case 2:
			{
				ConcretePublisher::some_logic(publishers);		break;
			}
			case 0:
				return 0;
		}
		system("cls");
	}
}
