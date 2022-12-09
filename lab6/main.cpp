
#include <iostream>
#include <func.hpp>
using std::cin;
using std::cout;
using std::endl;



int main()
{
	int n;
	cin >> n;
	int mas[100][100];
	read(mas, n);
	if (compare(mas, n))
		change(mas, n);
	write(mas, n);
	/*int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << a << ' ' << b << endl;
	swap(a, b, a, b);
	cout << a << ' ' << b << endl;*/
}

