#include "func.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void swap(int a, int b, int& c, int& d)
{
	c = b;
	d = a;
}

void read(int mas[][100], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mas[i][j];
}

void write(int mas[][100], int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << mas[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

bool equal(int mas1[], int mas2[], int n)
{
	for (int i = 0; i < n; i++)
		if (mas1[i] != mas2[i])
			return false;
	return true;
}

bool compare(int mas[][100], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (equal(mas[i], mas[j], n))
				return true;
	return false;
}

bool ifprime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i < sqrt(n) + 1; i++)
		if (n % i == 0)
			return false;
	return true;
}

int prmax(int mas[][100], int n)
{
	int max = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ifprime(mas[i][j]) && (mas[i][j] > max))
				max = mas[i][j];
	return max;
}

void minpr(int mas[][100], int j, int n, int max)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
		if (mas[i][j] < min)
			min = mas[i][j];
	for (int i = 0; i < n; i++)
		if (mas[i][j] == min)
			mas[i][j] = max;
}

void change(int mas[][100], int n)
{
	int max = prmax(mas, n);
	if (max == 1)
	{
		cout << "Error: there are no primes!" << endl;
	}
	else
	{
		for (int j = 0; j < n; j++)
			minpr(mas, j, n, max);
	}
}