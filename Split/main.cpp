#include<iostream>
using namespace std;
void print(const int arr[], int n);
void main()
{
	const int s = 10;
	int arr[s];
	int a = 0;
	int b = 0;
	int* even = new int[a];
	int* odd = new int[b];
	for (int i = 0; i < s; i++)arr[i] = rand()%100;
	print(arr, s);
	for (int i = 0; i < s; i++)
	{
		if (arr[i] % 2 == 0)even[a++] = arr[i];
		else odd[b++] = arr[i];
	}
	print(even, a);
	print(odd, b);
}
void print(const int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
