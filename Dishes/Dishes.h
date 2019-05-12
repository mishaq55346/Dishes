#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Restaurant
{
public:
	int NumberDishes, PriseDishes;
	string NameDishes;

	Restaurant() : NumberDishes{ 0 }, PriseDishes{ 0 }, NameDishes{ '0' } {}

	Restaurant(int NumberDishes, int PriseDishes, string NameDishes)
	{
		this->NumberDishes = NumberDishes;
		this->PriseDishes = PriseDishes;
		this->NameDishes = NameDishes;
	}
	void print()
	{
		cout << "printed info\n";
	}
};
class Dish
{
public:
	string name = "";
	int price = 0;
	int group = 0;
	

	Dish(){}
	Dish(string name, int price , int group) : name(name), price(price), group(group){}
	void print()
	{
		cout << name << " из группы " << group << " - цена: " << price << " руб.\n";
	}

};

inline string GetValueFromString(string Astr, int NumColumn)
{
	string result_s;
	string temp_str;
	int i = 0, cur_num_column = 0, j = 0;
	while (Astr[i] != '\0')
	{
		if (Astr[i] == '#')
		{
			cur_num_column = cur_num_column + 1;
		}
		if ((cur_num_column == NumColumn) && (Astr[i] != '#'))
		{
			temp_str[j] = Astr[i];
			j = j + 1;
		}
		i = i + 1;
	}
	result_s = temp_str;
	return(result_s);
}

//Вывод основного меню
inline void ShowMenu()
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

//Вывод блюд с ценой
inline void ShowDishes()
{
	int choice;
	cin >> choice;

	if (choice < 1 || choice > 8)
	{
		while (choice < 1 || choice > 8)
		{
			cout << "К сожалению, выбранное действие недопустимо. Повторите: ";
			cin >> choice;
		}
	}
	system("cls");
	fstream F;
	F.open("dishes1.txt", ios::in);
	F.close();
	cout << "show dishes\n";
	system("pause");
}

//Формирование заказа
inline void OrderDishes()
{
	int order;
	cout << "Что желаете добавить в заказ?" << endl;
	cout << "Вы заказали: ";
	cin >> order;

}
