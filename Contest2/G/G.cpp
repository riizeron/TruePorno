// G.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

long long GCD(long long a, long long b) {

	return b == 0 ? abs(a) : GCD(b, a % b);
}

long long LCM(long long a, long long b) {

	return(abs(b) / GCD(a, b) * abs(a));
}

int main()
{
	long long N;
	long double num1, num2;
	cin >> N >> num1;
	if (N == 0) { return 0; }

	if (long(num1) != num1) {
		cout << "Sequence has float values!";
		return 0;
	}

	long long first = num1;
	for (int i = 2; i <= N; ++i) {
		cin >> num2;
		if (long(num2) != num2) {A
			cout << "Sequence has float values!";
			return 0;
		}
		long long second = num2;
		first = LCM(second, first);
	}

	cout << first;
	return 0;
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
