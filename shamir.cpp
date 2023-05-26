#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

int generator(int a, int b) {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	mt19937 rnd(seed);
	uniform_int_distribution <int> distrib(a, b);
	int rand_num = distrib(rnd);
	return rand_num;
}

int Euclid(int c, int m) {
	int loc = m;
	int u = 0;
	int v = 1;
	int t, g;
	while (c > 0) {
		t = m % c;
		g = u - m / c * v;
		m = c;
		u = v;
		c = t;
		v = g;
	}
	if (u < 0)
		u += loc;
	return u;
}
int Nod(int a, int b) {
	if (a < b) {
		return(Nod(b, a));
	}
	else if (a % b == 0) {
		return b;
	}
	else {
		return(Nod(b, a % b));
	}
}

int shag1(int p) {
	int a;
	bool pr = false;
	while (pr == false) {
		a = generator(1, p);
		if (Nod(a, p) == 1) {
			pr = true;
		}
	}
	return a;
}

int degree(int m, int c, int p) {
	int res = 1;
	for (int i = 0; i < c; i++)
	{
		res = res * m;
		res = res % p;
	}
	return res;
}

vector <int> enc_sh(string m, int ca, int cb, int da, int p) {
	vector <int> msg;
	vector <int> crmsg;
	for (int i = 0; i < m.size(); i++) {
		msg.push_back((int)m[i]);
	}
	for (auto i : msg) {
		int x1 = degree(i, ca, p);
		int x2 = degree(x1, cb, p);
		int x3 = degree(x2, da, p);
		crmsg.push_back(x3);
	}
	return crmsg;
}

vector <char> dec_sh(vector <int> cr, int db, int p) {
	vector <int> dmsg;
	vector <char> dmsg2;
	for (auto i : cr) {
		int x4 = degree(i, db, p);
		dmsg.push_back(x4);
	}
	for (int i = 0; i < dmsg.size(); i++) {
		dmsg2.push_back((char)dmsg[i]);
	}
	return dmsg2;
}

string shamir(string stroka) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int p = 3361;
	int ca = shag1(p - 1);
	int da = Euclid(ca, p - 1);
	int cb = shag1(p - 1);
	int db = Euclid(cb, p - 1);
	vector <int> cr = enc_sh(stroka, ca, cb, da, p);
	vector <char> dcr = dec_sh(cr, db, p);
	string enc;
	string dec;
	for (auto i : cr) {
		enc += to_string(i);
		enc += " ";
	}
	for (auto i : dcr) {
		dec += i;
	}

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
	cout << endl << endl << endl << "Исходное сообщение: " << stroka;
	switch (choose)
	{
	case '1':
		cout << endl << "Зашифрованный текст: ";
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
		cout << "Зашифрованный текст: " << enc << endl;

		fout << "decr: " << dec;
		cout << "Расшифрованный текст: " << dec;
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
