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
	Value& s = doc["�������"];
	//s.SetInt(s.GetInt() + 1);
	assert(doc.IsObject());
	
	for (Value::ConstMemberIterator itr = doc.MemberBegin();
		itr != doc.MemberEnd(); ++itr)
	{
		printf("Type of member %s is %s\n",
			itr->name.GetString(), kTypeNames[itr->value.GetType()]);
	}
	cout << doc["�������"].GetObjectA().FindMember("group")->value.GetInt() << endl;
	cout << doc["�������"].GetObjectA().FindMember("number")->value.GetInt() << endl;


	//Restaurant res;
	//res.loadDishesFromFile();
	//res.showDishesInGroup(3);
/*
	int choice = 0;

	cout << "����� �������� �� ������ ���������?" << endl;
	cout << "1. ���������� ���� ���������." << endl;
	cout << "2. ���������� ���� ������." << endl;
	cout << "3. ���������� ����� �� ��������� �� ������." << endl;
	cout << "4. ���������� ������ �� ���� ������." << endl;
	cout << "5. �����." << endl;
	cout << "��������� ��������: ";

	cin >> choice;

	if (choice < 1 || choice > 5)
	{
		while (choice < 1 || choice > 5)
		{
			cout << "� ���������, ��������� �������� �����������. ���������: " << endl;
			cin >> choice;
		}
	}

	switch (choice)
	{
		case 1:
			res.ShowMenu();
			cout << "��� ������� ����������?" << endl;
			cout << "��������� ��������: ";
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