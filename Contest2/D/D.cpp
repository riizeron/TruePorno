#include <iostream>


int main()
{
	int consignmentsCount, bulletinsCount;
	std::cin >> consignmentsCount >> bulletinsCount;

	int* consignments = new int[consignmentsCount];

	for (int i = 0; i < consignmentsCount; i++)
	{
		consignments[i] = 0;
	}
	int validAmount = 0;

	for (int j = 0; j < bulletinsCount; j++) {
		std::string bulletin;
		std::cin >> bulletin;
		int count = 0;
		int voteIndex;

		for (int i = 0;i < consignmentsCount;i++) {
			if (bulletin[i] == '+') {
				count++;
				voteIndex = i;
			}
		}
		if (count == 1) {
			validAmount++;
			consignments[voteIndex]++;
		}
	}
	double border = 0.07;
	for (int i = 0;i < consignmentsCount;i++) {

		if (consignments[i] / (double)validAmount >= border) {
			std::cout << i + 1 << " " << std::endl;
		}
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
