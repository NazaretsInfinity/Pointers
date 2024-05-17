#include"fillrand.h"
void fillrand(int arr[], int n)
{
	for (int i = 0; i < n; i++)	*(arr + i) = rand() % 100;
}
void fillrand(char arr[], int n)
{
	for (int i = 0; i < n; i++)	*(arr + i) = rand();
}
void fillrand(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() & 100;
		arr[i] /= 100;
	}
}
void fillrand(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)arr[i][j] = rand() % 100;
}
void fillrand(char** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)arr[i][j] = rand();
}
