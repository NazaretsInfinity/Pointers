#include<iostream>
using namespace std;
#define tab "\t"
void fillrand(int arr[], int n);
void DBLfillrand(int **arr, int rows, int cols);

void print(int arr[], int n);
void DBLprint(int** arr, int rows, int cols);

int* push_back(int arr[], int& n, int v);
int* push_front(int arr[], int& n, int v);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int indx, int val);
int* erase(int arr[], int& n, int indx, int val);

int** allocate(int const rows,int const cols);
void clear(int** arr,int rows);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int **arr, int &rows, int cols, int nrow);

void pop_row_back(int **arr, int &rows);
void pop_row_front(int **arr, int &rows, int cols);
void erase_row(int **arr, int &rows, int cols, int drow);

int** push_col_back(int** arr, int rows, int &cols);
int** push_col_front(int** arr, int rows, int &cols);
int** insert_col(int** arr, int rows, int &cols, int ncol);

int** pop_col_back(int **arr, int rows, int &cols);
int** pop_col_front(int **arr, int rows, int &cols);
int** erase_col(int **arr, int rows, int &cols, int dcol);

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
	int v, indx, indx2;
	cout << "Enter the numb of el: "; cin >> indx;
	cout << "Enter the value: "; cin >> v;
	arr = insert(arr, n, indx, v);
	print(arr, n);
	cout << "Enter the numb of el to delete: "; cin >> indx2;
	arr = erase(arr, n, indx2, v);
	print(arr, n);
#endif 
	int rows, cols;
	cout << "Enter the size of list: "; cin >> rows >> cols;
	int** dblarr = allocate(rows, cols);
	DBLfillrand(dblarr, rows, cols);
	DBLprint(dblarr, rows, cols);

	//dblarr = push_row_back(dblarr, rows,cols);
	dblarr = push_row_front(dblarr, rows,cols);
	int nrow, drow, ncol, dcol;
	//cout << "Enter the numb of line to add: "; cin >> nrow;
	//dblarr = insert_row(dblarr, rows,cols, nrow);

	//pop_row_back(dblarr, rows);
	//pop_row_front(dblarr, rows, cols);

	//cout << "Enter the numb of line to delete: "; cin >> drow;
	//erase_row(dblarr, rows, cols,drow);

    //dblarr = push_col_back(dblarr, rows, cols);
	//dblarr = push_col_front(dblarr, rows, cols);

	//cout << "Enter the numb of column add: "; cin >> ncol;
	//dblarr = insert_col(dblarr, rows,cols, ncol);

	//dblarr = pop_col_front(dblarr, rows, cols);

	//cout << "Enter the numb of column to delete: "; cin >> dcol;
	//	dblarr = erase_col(dblarr, rows, cols,dcol);
	DBLprint(dblarr, rows, cols);
	clear(dblarr, rows);
}
void fillrand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void DBLfillrand(int **arr, int rows, int cols)
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
void DBLprint(int** arr, int rows, int cols)
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
int* erase(int arr[], int& n, int indx, int val)
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
int** insert_row(int** arr, int& rows, int cols, int nrow)
{
	int** buff = allocate(++rows, cols);
	for (int i = 0; i < rows-1; i++)
		for (int j = 0; j < cols; j++)
			if (i >= nrow - 1)buff[i + 1][j] = arr[i][j];
			else buff[i][j] = arr[i][j];
	for (int j = 0; j < cols; j++)buff[nrow - 1][j] = 0;
	clear(arr, rows - 1);
	return buff;
}

void pop_row_back(int** arr, int &rows)
{
	delete[] arr[rows-1];
	rows--;
}
void pop_row_front(int** arr, int& rows, int cols)
{
	for (int i = 0; i < rows-1; i++)
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}
	pop_row_back(arr, rows);
}
void erase_row(int** arr, int& rows, int cols, int drow)
{
	for (int i = 0; i < rows-1; i++)
		for (int j = 0; j < cols; j++)
			if (i >= drow-1)arr[i][j] = arr[i + 1][j];
	pop_row_back(arr, rows);
}

int** push_col_back(int** arr, int rows, int& cols)
{
	int** buff = allocate(rows, ++cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols-1; j++)buff[i][j] = arr[i][j];
		buff[i][cols-1] = rand() % 100;
	}
	clear(arr, rows);
	return buff;
}
int** push_col_front(int** arr, int rows, int& cols)
{
	int** buff = allocate(rows, ++cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)buff[i][j+1] = arr[i][j];
		buff[i][0] = rand() % 100;
	}
	clear(arr, rows);
	return buff;
}
int** insert_col(int** arr, int rows, int& cols, int ncol)
{
	int** buff = allocate(rows, ++cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{ 
		if (j >= ncol-1)buff[i][j + 1] = arr[i][j];
		else buff[i][j] = arr[i][j];
		if (j == ncol-1)buff[i][j] = 0;
		}
	}
	clear(arr, rows);
	return buff;
}

int** pop_col_back(int** arr, int rows, int& cols)
{
	int** buff = allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)buff[i][j] = arr[i][j];
	clear(arr, rows);
	return buff;
}
int** pop_col_front(int** arr, int rows, int& cols)
{
	int** buff = allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)buff[i][j] = arr[i][j+1];
	clear(arr, rows);
	return buff;
}
int** erase_col(int** arr, int rows, int& cols, int dcol)
{
	int** buff = allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (j >= dcol-1)buff[i][j] = arr[i][j + 1]; 
			else buff[i][j] = arr[i][j];
		}
	clear(arr, rows);
	return buff;
}
