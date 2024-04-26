#include<iostream>
using namespace std;
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "Russia");
	int n;
	cout << "Enter the size of list: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	delete[] arr;
}