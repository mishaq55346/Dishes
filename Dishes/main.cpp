#include "windows.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream ifs("file.json");
	IStreamWrapper isw(ifs);//загружаем файл file.json
	Document doc;
	doc.ParseStream(isw);//в ƒокумент переносим парсинг файла
	
	Value& s1 = doc["stroka"];//в s1 храним элемент с ключом "stroka"
	Value& s2 = doc["chislo"];
	Value& s3 = doc["massiv"];
	Value& s4 = doc["pravda"];
	Value& s5 = doc["object"];

	string j1 = s1.GetString();//€вно указываем, какой тип данных в объекте s1 - строка
	cout << "string = " << j1 << endl;

	int j2 = s2.GetInt();//здесь у нас число
	cout << "int = " << j2 << endl;

	cout << "array = [";//с массивами работаем немного по-другому
	for (Value::ConstValueIterator itr = s3.Begin(); 
		itr != s3.End(); ++itr)//проходим весь массив от начала (s3.Begin()) до конца
		cout << itr->GetInt() << ", ";//выводим каждый элемент я¬Ќќ указыва€, что мы оттуда "вытаскиваем"
	cout << "]" << endl;

	bool j4 = s4.GetBool();//здесь у нас булева переменна€
	cout << "bool = " << j4 << endl;

	cout << "object:\n";//	сначала указываем, что у нас объект
	//										указываем, что нам нужен его элемент с ключом "name"
	//															"вытаскиваем" значение и я¬Ќќ указываем его тип
	cout << "	name: " <<  s5.GetObjectA().FindMember("name")->value.GetString() << endl;
	cout << "	age: " <<  s5.GetObjectA().FindMember("age")->value.GetInt() << endl;

	system("pause");
	return 0;
}