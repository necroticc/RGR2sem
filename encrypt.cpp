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
	cout << endl << "������� ��� �����: ";
	cin.ignore();
	getline(cin, name_file);
	cout << endl;
again:
	ifstream fin(name_file);
	if (!fin.is_open()) {
		cout << "�������� ��� �����!\n��������� ����..." << endl;
		cin >> name_file;
		goto again;
	}
	else {
		getline(fin, mes);
		cout << "���������� �����: " << mes << endl;
	}
	fin.close();
	bool z = false;
	while (z == false) {
		string k1;
		char k;
		cout << "�������� ��������: " << endl;
		cout << "��� ������� �� ������� <1> - ���� �����." << endl;
		cout << "��� ������� �� ������� <2> - ���� �����������." << endl;
		cout << "��� ������� �� ������� <3> - ���� ������." << endl;
		cout << "��� ������� �� ������� <0> - ����� �� ���������." << endl;
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
			cout << "������ �������� ������ ���. ��������� �������." << endl << endl;
			}
		}
	}
}
