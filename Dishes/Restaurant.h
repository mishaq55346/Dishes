#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iso646.h>

using namespace std;

class Dish
{
public:
	string name = "";
	int price = 0;
	int group = 0;
	int number = 0;
	Dish() {}
	Dish(string name, int price, int group, int number) : name(name), price(price), group(group), number(number) {}
	Dish(const Dish &dish) : name(dish.name), price(dish.price), group(dish.group), number(dish.number) {}
	void print()
	{
		//cout << name << " из группы " << group << ", номер " << number << ". - цена: " << price << " руб.\n";
		cout << number << ". " << name << " - " << price << " руб.\n";
	}

};

class Restaurant//бывшее Dishes
{
	
public:
	vector<Dish> dishes;
	vector<Dish> ordered;
	int NumberDishes = 0, PriceDishes = 0;

	Restaurant(){}

	void printAllDishes()
	{
		for (auto dish : dishes)
			dish.print();
	}
	void loadDishesFromFile()
	{
		string tmp;
		fstream File;
		File.open("dishes.txt", ios::in);
		while (!File.eof())
		{
			string name = "";
			int price = 0;
			getline(File, tmp);
			if(tmp.empty())
				continue;
			int group = tmp.at(1) - '0';
			int num = tmp.at(3) - '0';
			int i;
			for (i = 5; tmp.at(i) != '#'; i++)
				name += tmp.at(i);
			i++;
			for (i; tmp.at(i) != '#'; i++)
				price = price * 10 + (tmp.at(i) - '0');
			dishes.emplace_back(name, price, group, num);
		}
		File.close();
	}
	void showDishesInGroup(int group)
	{
		for (auto dish : dishes)
			if (dish.group == group)
				dish.print();
	}
	//Вывод основного меню
	void ShowMenu()
	{
		string a;
		fstream F;
		F.open("menu.txt", ios::in);
		while (!F.eof())
		{
			getline(F, a);
			cout << a << endl;
		}
		F.close();
	}

	//Формирование заказа
	void OrderDishes(int group)
	{
		int num;
		cout << "Что желаете добавить в заказ?" << endl;
		cout << "Вы заказали: ";
		cin >> num;
		for (auto dish : dishes)
			if (dish.group == group && dish.number == num)
				ordered.emplace_back(dish);
	}

	void printOrder()
	{
		int sum = 0;
		for (auto dish : ordered) {
			cout << dish.name << " - " << dish.price << " руб." << endl;
			sum += dish.price;
		}
		cout << "Итог: " << sum << " руб." << endl;
	}
};





