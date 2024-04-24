#include<iostream>
using namespace std;

void exchange(int& a, int& b);
void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	exchange(a, b);
	cout << a << "\t" << b << endl;
}
void exchange(int& a, int& b)
{
	int buffer = a;
	a = b;
	b = buffer;
}
