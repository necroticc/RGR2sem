#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fstream>
using namespace std;

string enc_gron(string& stroka, vector <int> vec2) {
	string str;
	int s = vec2.size();
	for (int i = 0; i < s; i++) {
		str += stroka[i] + vec2[i];
	}
	return str;
}

string dec_gron(string& stroka, vector <int> vec2) {
	string str;
	int s = vec2.size();
	for (int i = 0; i < s; i++) {
		str += stroka[i] - vec2[i];
	}
	return str;
}


vector <int> cicle(string pred, vector <int> vec) {
	int k = 0;
	vector <int> vec2;
	while (pred[k] != '\0') {
		for (auto i : vec) {
			if (pred[k] != '\0') {
				vec2.push_back(i);
				k++;
			}
			else break;
		}
	}
	return vec2;
}

string gronsfeld(string stroka) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key = 0;
	string strKey;
	bool n = false;
	cout << endl << "Для использования данного вида шифрования необходим ключ.";
	while (n == false) { //ввод ключа и проверка на ошибки
		cout << endl << "Введите ключ: ";
		cin >> strKey;
		size_t found = strKey.find_first_not_of("1234567890");
		if (found != string::npos) {
			cout << "Ключ должен состоять из чисел." << endl;
		}
		else {
			key = stoi(strKey);
			cout << endl;
			n = true;
		}
	}
	cin.ignore();
	vector <int> vec;
	int p = key;
	while (p != 0) { //записываем ключ из строки в вектор
		int p2 = p % 10;
		vec.push_back(p2);
		p = p / 10;
	}
	reverse(vec.begin(), vec.end());
	vector <int> vec2 = cicle(stroka, vec);
	string enc = enc_gron(stroka, vec2);
	string dec = dec_gron(enc, vec2);

	cout << "Шифрование, дешифрование, полная проверка?" << endl;
	cout << "Нажмите <1>, <2>, <3>." << endl;
	cout << "Ввод: ";
	char choose;
	string k1;
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
	cout << endl << endl << endl << "Исходное сообщение: " << stroka << endl;
	switch (choose)
	{
	case '1':;
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
		cout << "Зашифрованное сообщение: " << enc << endl;

		fout << "decr: " << dec;
		cout << "Расшифрованное сообщение: " << dec;
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
