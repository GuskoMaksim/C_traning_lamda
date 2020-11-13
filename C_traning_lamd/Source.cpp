#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<int> a{ 1,2,34,5,1,2,3 };

	/// задание 1.1 ///
	cout << "Задание 1.1: " << endl;
	for_each(a.begin(), a.end(), [](int& const value) {
		cout << value << endl;
		});

	/// Задание 1.2 ///
	cout << endl << "Задание 1.2: " << endl;
	int col = 0;
	auto comp = [&col](const int& f, const int& s)
	{
		col++;
		if (f < s)
		{
			return 1;
		}
		return 0;
	};
	sort(a.begin(), a.end(), comp);
	cout << "Количество перестановок " << col << endl;

	/// Задание 1.3 ///
	cout << endl << "Задание 1.3: " << endl;
	string str_f;
	string str = " Привет, я тут живу.";
	cout << "Исходная строка: " << str << endl;
	cout << "Введите строку" << endl;
	cin >> str_f;
	auto found_str = [&str](string str_f)
	{
		int pos = 0;
		pos = str.find(str_f);
		if (pos>=0)
			cout << "Строка найдена в позиции: " << pos << endl;
		else
			cout << "Строка не найдена " << endl;
	};
	found_str(str_f);

	/// Задание 2.1 ///
	cout << endl << "Задание 2.1: " << endl;
	vector <int> z21;
	int n;
	auto fill_vec = [](vector<int>& z, int n) {
		for (int i = 0; i < n; i++)
			z.push_back(i);
	};
	cout << "Введите длину вектора: ";
	cin >> n;
	fill_vec(z21, n);
	cout << "Полученый вектор: " << endl;
	for_each(z21.begin(), z21.end(), [](int& const value) {
		cout << value << " ";
		});


	/// Задание 2.2 ///
	cout << endl << endl << "Задание 2.2: " << endl;
	vector <int> z22;
	int k;
	fill_vec(z22, 6);
	cout << "Введите длину для изменения вектора: ";
	cin >> k;
	auto change_vec = [](vector<int>& z, int k) {
		int sizee = z.size();
		for (int i = sizee; i < k + sizee; i++)
			z.push_back(i);
		for (int i = 0; i < k; i++)
		{
			z.erase(z.begin());
		}
	};
	change_vec(z22, k);
	cout << "Полученый вектор: " << endl;
	for_each(z22.begin(), z22.end(), [](int& const value) {
		cout << value << " ";
		});
}