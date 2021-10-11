// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cmath>
#define a
using namespace std;

bool Check(int input, int len) {
	if (len >= 2)
	{
		int position1 = 10;
		int position2 = int(exp((len - 1) * log(10)));
		if (((input % position1) == (input / position2)))
		{
			input = (input - input / position2 * position2) / position1;
			if (len == 4 && (0 < input && 10 >= input)) { return false; }
			len -= 2;
			Check(input, len);
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}

void ThroughStr() {
	int count = 0;
	int input;
	std::cin >> input;
	while (input)
	{
		std::string strNumber = std::to_string(input);
		std::string strNumberReversed = std::to_string(input--);

		std::reverse(strNumberReversed.begin(), strNumberReversed.end());

		if (strNumber == strNumberReversed)
		{
			count++;
		}
	}
	std::cout << count << std::endl;
}

int main()
{
#if defined(a)
	int count = 0;
	int input;
	std::cin >> input;
	while (input)
	{
		int searchLen = 1;
		while (searchLen <= 100)
		{
			if (int(exp(searchLen * log(10))) > input)
			{
				break;
			}
			searchLen++;
		}
		if (Check(input, searchLen))
		{
			count++;
		}
		input--;
	}
	std::cout << count << std::endl;
#else 
	ThroughStr();
#endif
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
