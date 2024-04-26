#include<iostream>
using namespace std;
#define tab "\t"
void fillrand(int arr[], const int n);
void print(const int arr[], int n);
void main()
{
	const int s = 10;
	int arr[s];
	fillrand(arr, s);
	print(arr, s);
	int evencount = 0;
	int oddcount = 0;
	//count the size of odd and even arays(how many elements)
	for (int i = 0; i < s; i++)
	{
		arr[i] % 2 == 0 ? evencount++: oddcount++;
	}
	cout << evencount << endl;
	cout << oddcount << endl;
	//provide min memory for arrays
	int* even = new int[evencount];
	int* odd = new int[oddcount];
	//distribute all elements into the appropriate arrays(copy them)
	for (int i = 0,j=0,k=0; i < s; i++)
	{
	  (arr[i]%2 ? odd[k++] : even[j++]) = arr[i];
	}
	print(even, evencount);
	print(odd, oddcount);
	delete[] even;
	delete[] odd;
	}
void fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)arr[i] = rand() % 100;
}
void print(const int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}


