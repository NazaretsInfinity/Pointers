#include<iostream>
using namespace std;

#define tab "\t"
void fillrand(int arr[], int n);
void fillrand(int **arr, int rows, int cols);

void print(int arr[], int n);
void print(int** arr, int rows, int cols);

int* push_back(int arr[], int& n, int v);
int* push_front(int arr[], int& n, int v);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int indx, int val);
int* erase(int arr[], int& n, int indx);

int** allocate(int const rows,int const cols);
void clear(int** arr,int rows);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int **arr, int &rows, int cols, int ex);

int**pop_row_back(int **arr, int &rows);
int** pop_row_front(int **arr, int &rows, int cols);
int** erase_row(int **arr, int &rows, int cols, int ex);

void push_col_back(int** arr, int rows, int &cols);
void push_col_front(int** arr, int rows, int &cols);
void insert_col(int** arr, int rows, int &cols, int ex);

void pop_col_back(int **arr, int rows, int &cols);
void pop_col_front(int **arr, int rows, int &cols);
void erase_col(int **arr, int rows, int &cols, int ex);

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
#ifdef dynamic memory 2
	int n;
	cout << "Enter the size of list: "; cin >> n;
	int* arr = new int[n];
	fillrand(arr, n);
	int v, indx;
	cout << "Enter the numb of el: "; cin >> indx;
	cout << "Enter the value: "; cin >> v;
	arr = insert(arr, n, indx, v);
	print(arr, n);
	cout << "Enter the numb of el to delete: "; cin >> indx;
	arr = erase(arr, n, indx);
	print(arr, n);
	delete[] arr;
#endif 
	int rows, cols;
	cout << "Enter the size of list: "; cin >> rows >> cols;
	int** arr = allocate(rows, cols);
	fillrand(arr, rows, cols);
	print(arr, rows, cols);
	int ex;
	//arr = push_row_back(arr, rows,cols);
	//arr = push_row_front(arr, rows,cols);
	//cout << "Enter the numb of line to add: "; cin >> ex;
	//arr = insert_row(arr, rows,cols, ex);

	//arr = pop_row_back(arr, rows);
	//arr = pop_row_front(arr, rows, cols);

	//cout << "Enter the numb of line to delete: "; cin >> ex;
	//arr = erase_row(arr, rows, cols,ex);

    //push_col_back(arr, rows, cols);
	//push_col_front(arr, rows, cols);
	//cout << "Enter the numb of column add: "; cin >> ex;
	 //insert_col(arr, rows,cols, ex);

	//pop_col_back(arr, rows, cols);
	//pop_col_front(arr, rows, cols);
	//cout << "Enter the numb of column to delete: "; cin >> ex;
    //erase_col(arr, rows, cols,ex);
	print(arr, rows, cols);
	clear(arr, rows);
}
void fillrand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void fillrand(int **arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)arr[i][j] = rand() % 100;
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void print(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int v)
{
	//create a reverse array with memory we need
	int* buff = new int[n+1];
	for (int i = 0; i < n; i++)buff[i] = arr[i];
	//arr1[n] = value;
	delete[] arr;
	//change address of old massive with address of new massive arr1
	arr = buff;
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

int* insert(int arr[], int& n, int indx, int val)
{
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		if(i>=indx)buffer[i + 1] = arr[i];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[indx] = val;
	return buffer;
}
int* erase(int arr[], int& n, int indx)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		if (i >= indx)buffer[i] = arr[i+1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

int** allocate(int const rows, int const cols)
{
	int** dblarr = new int* [rows];
	for (int i = 0; i < rows; i++)dblarr[i] = new int[cols];
	return dblarr;
}
void clear(int** arr,int rows)
{
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, int cols)
{
	int** buff = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buff[i] = arr[i];
	delete[] arr;
	buff[rows] = new int[cols] {};
	rows++;
	return buff;
}
int** push_row_front(int** arr, int& rows, int cols)
{
	int** buff = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buff[i+1] = arr[i];
	delete[] arr;
	buff[0] = new int[cols] {};
	rows++;
	return buff;
}
int** insert_row(int** arr, int& rows, int cols, int ex)
{
	int** buff = new int* [rows + 1];;
	for (int i = 0; i < rows; i++)
			if (i >= ex)buff[i + 1] = arr[i];
			else buff[i] = arr[i];
	delete[] arr;
	rows++;
	buff[ex] = new int[cols] {};
	return buff;
}

int** pop_row_back(int** arr, int &rows)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows]; //delete the line from memory
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr[0]; //delete the line from memory
	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, int cols, int ex)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
		if (i >= ex)buffer[i] = arr[i + 1];
		else buffer[i] = arr[i];
	delete[] arr[ex];
	delete[] arr;
	return buffer;
}

void push_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, int rows, int& cols, int ex)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
			if(j>=ex)buffer[j+1] = arr[i][j];
			else buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1];
		for (int j = 0; j < cols-1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, int rows, int& cols, int ex)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)
			if (j >= ex)buffer[j] = arr[i][j + 1];
			else buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
