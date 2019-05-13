#include "windows.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Restaurant.h"

using namespace std;

int main()
{
	
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	static const char* kTypeNames[] =
	{ "Null", "False", "True", "Object", "Array", "String", "Number" };

	ifstream ifs("dishes.json");
	IStreamWrapper isw(ifs);
	Document doc;
	doc.ParseStream(isw);
	Value& s = doc["Яичница"];
	//s.SetInt(s.GetInt() + 1);
	assert(doc.IsObject());
	
	for (Value::ConstMemberIterator itr = doc.MemberBegin();
		itr != doc.MemberEnd(); ++itr)
	{
		printf("Type of member %s is %s\n",
			itr->name.GetString(), kTypeNames[itr->value.GetType()]);
	}
	cout << doc["Яичница"].GetObjectA().FindMember("group")->value.GetInt() << endl;
	cout << doc["Яичница"].GetObjectA().FindMember("number")->value.GetInt() << endl;


	//Restaurant res;
	//res.loadDishesFromFile();
	//res.showDishesInGroup(3);
/*
	int choice = 0;

	cout << "Какую операцию Вы хотите выполнить?" << endl;
	cout << "1. Посмотреть меню ресторана." << endl;
	cout << "2. Посмотреть счет заказа." << endl;
	cout << "3. Посмотреть отчет по продуктам на складе." << endl;
	cout << "4. Посмотреть заказы за весь период." << endl;
	cout << "5. Выход." << endl;
	cout << "Выбранное действие: ";

	cin >> choice;

	if (choice < 1 || choice > 5)
	{
		while (choice < 1 || choice > 5)
		{
			cout << "К сожалению, выбранное действие недопустимо. Повторите: " << endl;
			cin >> choice;
		}
	}

	switch (choice)
	{
		case 1:
			res.ShowMenu();
			cout << "Что желаете посмотреть?" << endl;
			cout << "Выбранное действие: ";
			int group;
			cin >> group;
			res.showDishesInGroup(group);
			res.OrderDishes(group);
			res.printOrder();
		break;
	}
	*/
	/*
	ifstream A;
	string nam;
	int num, pri;
	vector<Restaurant> v;
	A.open("dishes1.txt");
	if (A.is_open() && !A.eof())
	{
		A >> num;
		A >> pri;
		A >> nam;
		v.emplace_back(num, pri, nam);
	}
	A.close();
	for (auto dish : v)
		dish.print();*/
	system("pause");
	return 0;
}