// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

string word;
int amount;
char consonants[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };

bool check_symbol(char ch) {
	for (int i = 0;i < 20;i++) {
		if (ch == consonants[i]) {
			return true;
		}
	}
	return false;
}

int count_cons(string word) {
	int count = 0;
	for (int i = 0;i < int(word.length());i++) {
		if (check_symbol(word[i])) {
			count++;
		}
	}
	return count;
}

auto cons_arr(string word)
{
	int j = 0;
	char* arr = new char[amount];
	for (int i = 0;i < int(word.length());i++) {
		if (check_symbol(word[i])) {
			arr[j++] = word[i];
		}
	}
	return arr;
}
int main()
{
	cin >> word;
	amount = count_cons(word);
	char* only_cons = cons_arr(word);
	
	if (!check_symbol(only_cons[0]) || amount==1) {
		cout << "YES" << endl;
		return 0;
	}

	for (int i = 0; i<int(amount / 2);i++) {

		if (!(only_cons[i] == only_cons[amount - i - 1])) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		return 0;
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
