#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#include "enc_head.h"

using namespace std;

void encryption() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string mes = "";
	string name_file;
	cout << endl << "Введите имя файла: ";
	cin.ignore();
	getline(cin, name_file);
	cout << endl;
again:
	ifstream fin(name_file);
	if (!fin.is_open()) {
		cout << "Неверное имя файла!\nПовторите ввод..." << endl;
		cin >> name_file;
		goto again;
	}
	else {
		getline(fin, mes);
		cout << "Содержание файла: " << mes << endl;
	}
	fin.close();
	bool z = false;
	while (z == false) {
		string k1;
		char k;
		cout << "Выберите действие: " << endl;
		cout << "При нажатии на клавишу <1> - шифр Атбаш." << endl;
		cout << "При нажатии на клавишу <2> - шифр Гронсфельда." << endl;
		cout << "При нажатии на клавишу <3> - шифр Шамира." << endl;
		cout << "При нажатии на кливишу <0> - выход из программы." << endl;
		getline(cin, k1);
		if (k1.size() > 1) {
			k = 5;
		}
		else {
			k = k1[0];
		}
		switch (k)
		{
		case '1':
			atbash(mes);
			cout << endl;
			system("notepad outputText.txt");
			break;
		case '2':
			gronsfeld(mes);
			cout << endl;
			system("notepad outputText.txt");
			break;
		case'3':
			shamir(mes);
			cout << endl;
			system("notepad outputText.txt");
			break;
		case '0':
			exit(0);
			break;
			{
		default:
			cout << "Такого варианта ответа нет. Повторите попытку." << endl << endl;
			}
		}
	}
}
