// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

enum Criteria {
	lowerCase = 1,
	numbers = 2,
	len = 4,
	upperCase = 8
};

int CheckPas(string password) {

	int length = password.length();
	int value = 0;

	if (length >= 8) {
		value |= len;
	}
	for (int i = 0;i < password.length();i++) {
		if ('a' <= password[i] && password[i] <= 'z') {
			value |= lowerCase;
		}
		if ('A' <= password[i] && password[i] <= 'Z') {
			value |= upperCase;
		}
		if ('0' <= password[i] && password[i] <= '9') {
			value |= numbers;
		}
	}
	return value;
}

int main()
{
	string password;
	cin >> password;

	if (CheckPas(password) == (len | upperCase | lowerCase | numbers)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
