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


	Restaurant res;
	res.loadDishesFromFile();
	//res.showDishesInGroup(3);

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