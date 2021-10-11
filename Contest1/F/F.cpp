// F.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>

long double Factorial(long double num)
{
	if (num == 0) { return 1; }
	return num * Factorial(num - 1);
}

double Tailor(double x, double accuracy, [Out] int i) {
	i = 1;
	long double pi = 3.14159265;

	double cos = 1, sin = x, intermediateValueCos = 1, intermediateValueSin = x;
	x = fmod(x, pi);
	while (fabs(intermediateValueCos *= -x * x / (2 * i * (2 * i - 1))) > accuracy
		&& fabs(intermediateValueSin *= -x * x / (2 * i * (2 * i + 1))) > accuracy) {
		cos += intermediateValueCos;
		sin += intermediateValueSin;
		i++;
	}
	return sin;
}

int main()
{
	long double X;
	long double e;
	std::cin >> X;
	std::cin >> e;
	int accuracy = -int(log(e)) / 2;

	int i;
	double result = Tailor(X, e, i);

	std::cout << std::setprecision(accuracy) << result << std::endl;
	std::cout << i << std::endl;
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
