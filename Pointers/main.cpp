#include<iostream>
using namespace std;
#define pointers_basics
void main()
{
	setlocale(LC_ALL, "Russia");
#ifdef pointers_basics1
	int a = 2;
	int *pa = &a;
	cout << a << endl;
	cout << &a << endl; //взятие адресса переменной а прямо при выводе
	cout << pa << endl; //вывод адреса переменной а , хранящегося в указатели pa
	cout << *pa << endl; //dereference of the 'pa' pointer
	int *pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;
#endif // pointers_basics1
	const int n = 5;
	short arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << (arr + i) << "\t";
	}
}
