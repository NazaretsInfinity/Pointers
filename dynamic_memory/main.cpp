#include<iostream>
using namespace std;
#define tab "\t"
void fillrand(int arr[], int n);
void print(int arr[], int n);
int* push_back(int arr[], int& n, int v);
int* push_front(int arr[], int& n, int v);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
void main()
{
#ifdef dynamic memory 1 
	setlocale(LC_ALL, "Russia");
	int n;
	cout << "Enter the size of list: "; cin >> n;
	int* arr = new int[n];
	fillrand(arr, n);
	print(arr, n);
	int value; cout << "Enter new element: "; cin >> value;
	arr = push_back(arr, n, value);
	print(arr, n);
	arr = push_front(arr, n, value);
	print(arr, n);
	//arr = pop_back(arr, n);
	print(arr, n);
	arr = pop_front(arr, n);
	print(arr, n);
	delete[] arr;
#endif 

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
int* push_back(int arr[], int& n, int v)
{
	//create a reverse array with memory we need
	int* arr1 = new int[n+1];
	for (int i = 0; i < n; i++)arr1[i] = arr[i];
	//arr1[n] = value;
	delete[] arr;
	//change address of old massive with address of new massive arr1
	arr = arr1;
	//now we got more place, exactly for 1 new element
	arr[n] = v;
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int v)
{
	int* buffer = new int[n+1];
	for (int i = 0; i < n; i++)buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = v;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}


