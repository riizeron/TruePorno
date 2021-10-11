#include <iostream>



long GCD(long a, long b) {

	return b == 0 ? abs(a) : GCD(b, a % b);
}

long LCM(long a, long b) {

	return(b / GCD(a, b) * a);
}

int main()
{
	long N;
	double num1, num2;
	cin >> N >> num1;
	if (N == 0) { return 0; }

	if (long(num1) != num1) {
		cout << "Sequence has float values!";
		return 0;
	}

	long first = num1;
	for (int i = 2; i <= N; ++i) {
		cin >> num2;
		if (long(num2) != num2) {
			cout << "Sequence has float values!";
			return 0;
		}
		long second = num2;
		first = LCM(second, first);
	}

	cout << first;
	return 0;
}




/*int N;
double first;
cin >> N;
cin >> first;

if (long(first) != first) {
	cout << "Sequence has float values!";
	return 0;
}

for (int i = 1;i < N;i++)
{
	double number;
	cin >> number;

	if (long(number) != number) {
		cout << "Sequence has float values!";
		return 0;
	}
	first = GCD(long(number), long(first));
}
cout << first << " " << counter << endl;
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
