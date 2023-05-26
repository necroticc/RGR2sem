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
		cout << "Введите пароль: ";
		cin >> str;
		if (str == pass) {
			encryption();
			i = 0;
		}
		else {
			cout << "Пароль неверный! Осталось попыток: " << 2 - i << endl;
			i += 1;
			if (i == 3) {
				cout << "Вы 3 раза ввели неверный пароль, повторите попытку позже.";
				n = true;
			}
		}
	}
}
