#include<iostream>
using namespace std;
#define tab "\t"
void fillrand(int arr[], int n);
void print(int arr[], int n);
void main()
{
	setlocale(LC_ALL, "Russia");
	int n;
	cout << "Enter the size of list: "; cin >> n;
	int *arr = new int[n];
	fillrand(arr, n);
	print(arr, n);
	int value; cout << "Enter new element: "; cin >> value;
	int* arr1 = new int[n+1];
	for (int i = 0; i < n; i++)arr1[i] = arr[i];
	//arr1[n] = value;
	delete[] arr;
	arr = arr1;
	arr[n]=value;
	print(arr, n + 1);
	delete[] arr;
}
void fillrand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

