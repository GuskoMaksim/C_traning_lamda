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

	/// ������� 1.1 ///
	cout << "������� 1.1: " << endl;
	for_each(a.begin(), a.end(), [](int& const value) {
		cout << value << endl;
		});

	/// ������� 1.2 ///
	cout << endl << "������� 1.2: " << endl;
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
	cout << "���������� ������������ " << col << endl;

	/// ������� 1.3 ///
	cout << endl << "������� 1.3: " << endl;
	string str_f;
	string str = " ������, � ��� ����.";
	cout << "�������� ������: " << str << endl;
	cout << "������� ������" << endl;
	cin >> str_f;
	auto found_str = [&str](string str_f)
	{
		int pos = 0;
		pos = str.find(str_f);
		if (pos>=0)
			cout << "������ ������� � �������: " << pos << endl;
		else
			cout << "������ �� ������� " << endl;
	};
	found_str(str_f);

	/// ������� 2.1 ///
	cout << endl << "������� 2.1: " << endl;
	vector <int> z21;
	int n;
	auto fill_vec = [](vector<int>& z, int n) {
		for (int i = 0; i < n; i++)
			z.push_back(i);
	};
	cout << "������� ����� �������: ";
	cin >> n;
	fill_vec(z21, n);
	cout << "��������� ������: " << endl;
	for_each(z21.begin(), z21.end(), [](int& const value) {
		cout << value << " ";
		});


	/// ������� 2.2 ///
	cout << endl << endl << "������� 2.2: " << endl;
	vector <int> z22;
	int k;
	fill_vec(z22, 6);
	cout << "������� ����� ��� ��������� �������: ";
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
	cout << "��������� ������: " << endl;
	for_each(z22.begin(), z22.end(), [](int& const value) {
		cout << value << " ";
		});
}