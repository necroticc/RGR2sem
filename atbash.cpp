#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

string enc_atb(string stroka) {
	int i = 0;
	string str;
	while (stroka[i] != '\0') {
		if (stroka[i] != '\0') {
			str += 255 - stroka[i] + 1;
			i++;
		}
		else break;
	}
	return str;
}

string dec_atb(string stroka) {
	int i = 0;
	string str;
	while (stroka[i] != '\0') {
		if (stroka[i] != '\0') {
			str += 255 - stroka[i] + 1;
			i++;
		}
		else break;
	}
	return str;
}

string atbash(string stroka) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string enc = enc_atb(stroka);
	string dec = dec_atb(enc);
	string path = "outputText.txt";
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла. Повторите попытку.";
	}
	else {
		fout << stroka;
	}
	fout.close();

	string k1;
	char choose;
	cout << "Шифрование, дешифрование, полная проверка?" << endl;
	cout << "Нажмите <1>, <2>, <3>." << endl;
	cout << "Ввод: ";
	bool z = false;
	while (z == false) {
		getline(cin, k1);
		if (k1 == "1" or k1 == "2" or k1 == "3") {
			choose = k1[0];
			break;
		}
		else {
			cout << "Такого варианта ответа нет. Повторите попытку." << endl;
		}
	}

	switch (choose)
	{
	case '1':
		cout << endl << "Зашифрованный текст: " << enc << endl << endl;
		fout.open(path);
		fout << enc;
		fout.close();
		break;
	case '2':
		cout << endl << "Расшифрованный текст: " << dec << endl << endl;
		fout.open(path);
		fout << dec;
		fout.close();
		break;
	case '3':
		fout.open(path, ofstream::app);
		cout << endl;
		fout << endl << endl;
		fout << "encr: " << enc;
		fout << endl << endl;
		cout << enc << endl;

		fout << "decr: " << dec;
		cout << dec;
		fout.close();
		break;
		{
	default:
		cout << "Такого варианта ответа нет. Повторите попытку." << endl;
		break;
		}
	}
	cout << endl << endl << endl << endl;
	return stroka;
}
