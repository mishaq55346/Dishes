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
	IStreamWrapper isw(ifs);//��������� ���� file.json
	Document doc;
	doc.ParseStream(isw);//� �������� ��������� ������� �����
	
	Value& s1 = doc["stroka"];//� s1 ������ ������� � ������ "stroka"
	Value& s2 = doc["chislo"];
	Value& s3 = doc["massiv"];
	Value& s4 = doc["pravda"];
	Value& s5 = doc["object"];

	string j1 = s1.GetString();//���� ���������, ����� ��� ������ � ������� s1 - ������
	cout << "string = " << j1 << endl;

	int j2 = s2.GetInt();//����� � ��� �����
	cout << "int = " << j2 << endl;

	cout << "array = [";//� ��������� �������� ������� ��-�������
	for (Value::ConstValueIterator itr = s3.Begin(); 
		itr != s3.End(); ++itr)//�������� ���� ������ �� ������ (s3.Begin()) �� �����
		cout << itr->GetInt() << ", ";//������� ������ ������� ���� ��������, ��� �� ������ "�����������"
	cout << "]" << endl;

	bool j4 = s4.GetBool();//����� � ��� ������ ����������
	cout << "bool = " << j4 << endl;

	cout << "object:\n";//	������� ���������, ��� � ��� ������
	//										���������, ��� ��� ����� ��� ������� � ������ "name"
	//															"�����������" �������� � ���� ��������� ��� ���
	cout << "	name: " <<  s5.GetObjectA().FindMember("name")->value.GetString() << endl;
	cout << "	age: " <<  s5.GetObjectA().FindMember("age")->value.GetInt() << endl;

	system("pause");
	return 0;
}