#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "pass_head.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string pass, str;
	bool n = false;
	pass = "1234";
	int i = 0;
	while (n == false) {
		cout << "������� ������: ";
		cin >> str;
		if (str == pass) {
			encryption();
			i = 0;
		}
		else {
			cout << "������ ��������! �������� �������: " << 2 - i << endl;
			i += 1;
			if (i == 3) {
				cout << "�� 3 ���� ����� �������� ������, ��������� ������� �����.";
				n = true;
			}
		}
	}
}
