﻿// odu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

double f(double x, double y)
{
	return (2*x*x+5)*sin(y);
}

int main()
{
	setlocale(LC_ALL,"Rus");
	const int n = 10;
	double h = 0.1;
	double* x = new double[11] { 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1 };
	double* y = new double[11];
	y[0] = 1;

	for (int i = 0; i < n; i++)
	{
		y[i + 1] = y[i] + h * f(x[i], y[i]);
	}

	for (int i = 0; i < n; i++)
	{
		y[i + 1] = y[i] + h * f(x[i] + h / 2, y[i] + h * f(x[i], y[i]) / 2);
	}

	for (int i = 0; i < n; i++)
	{
		
		double a = h * f(x[i], y[i]);
		double	b = h * f(x[i] + h / 2, y[i] + a / 2);
		double c = h * f(x[i] + h / 2, y[i] + b / 2);
		double d = h * f(x[i] + h, y[i] + c);
		y[i + 1] = y[i] + (a + 2 * b + 2 * c + d) / 6;
	}

	for (int i = 3; i < n; i++)
	{
		double t = (55 * f(x[i], y[i])
			- 59 * f(x[i - 1], y[i - 1])
			+ 37 * f(x[i - 2], y[i - 2])
			- 9 * f(x[i - 3], y[i - 3]));
		y[i + 1] = y[i] + h * t / 24;
	}

	for (int i = 3; i < n; i++)
	{
		double t = (23 * f(x[i], y[i])
			- 16 * f(x[i - 1], y[i - 1])
			+ 5 * f(x[i - 2], y[i - 2]));
		y[i + 1] = y[i] + h * t / 12;
	}

	for (int i = 3; i < n; i++)
	{
		double t = (3 * f(x[i], y[i])
			- f(x[i - 1], y[i - 1]));
		y[i + 1] = y[i] + h * t / 2;
	}
	cout << "Метод Эйлера: ";
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << endl;

	cout << "Модифицированный метод Эйлера: ";
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << endl;

	cout << "Метод Рунге-Кутты: ";
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << endl;

	cout << "Метод Адамса порядка m = 3: ";
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << endl;

	cout << "Метод Адамса порядка m = 2: ";
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << endl;

	cout << "Метод Адамса порядка m = 1: ";
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
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
