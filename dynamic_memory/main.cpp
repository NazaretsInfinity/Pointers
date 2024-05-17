#include"stdafx.h"
#include"fillrand.h"
#include"print.h"
#include"print.cpp"
#define dynamic_memory

template<typename T>T* push_back(T arr[], int& n, T v);
template<typename T>T* push_front(T arr[], int& n, T v);

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);

template<typename T>T* insert(T arr[], int& n, int indx, T val);
template<typename T>T* erase(T arr[], int& n, int indx);

int** allocate(int const rows, int const cols);
template<typename T> void clear(T** arr,int rows);

template<typename T> T** push_row_back(T** arr, int& rows, int cols);
template<typename T> T** push_row_front(T** arr, int& rows, int cols);
template<typename T> T ** insert_row(T **arr, int &rows, int cols, int ex);

template<typename T>T** pop_row_back(T** arr, int& rows);
template<typename T>T** pop_row_front(T **arr, int &rows);
template<typename T>T** erase_row(T **arr, int &rows, int ex);

template<typename T>void push_col_back(T** arr, int rows, int &cols);
template<typename T>void push_col_front(T** arr, int rows, int &cols);
template<typename T>void insert_col(T** arr, int rows, int &cols, int ex);

template<typename T>void pop_col_back(T **arr, int rows, int &cols);
template<typename T>void pop_col_front(T **arr, int rows, int &cols);
template<typename T>void erase_col(T **arr, int rows, int &cols, int ex);

void main()
{
#ifdef dynamic_memory1
	setlocale(LC_ALL, "Russia");
	int n;
	cout << "Enter the size of list: "; cin >> n;
	typedef char DataType;
	DataType* arr = new DataType[n];
	fillrand(arr, n);
	print(arr, n);
	DataType value; cout << "Enter new element: "; cin >> value;
	arr = push_back(arr, n, value);
	print(arr, n);
	arr = push_front(arr, n, value);
	print(arr, n);
	arr = pop_back(arr, n);
	print(arr, n);
	arr = pop_front(arr, n);
	print(arr, n);
	delete[] arr;
#endif 
#ifdef dynamic_memory
	int n, indx;
	cout << "Enter the size of list: "; cin >> n;
	typedef double DataType;
	DataType* arr = new DataType[n];
	fillrand(arr, n);
	print(arr, n);
	DataType v;
	cout << "Enter the numb of el: "; cin >> indx;
	cout << "Enter the value: "; cin >> v;
	arr = insert(arr, n, indx, v);
	print(arr, n);

	cout << "Enter the numb of el to delete: "; cin >> indx;
	arr = erase(arr, n, indx);
	print(arr, n);
	delete[] arr;
#endif 
#ifdef dynamic_memory3
	int rows, cols;
	cout << "Enter the size of list: "; cin >> rows >> cols;
	int**arr = allocate(rows, cols);
	fillrand(arr, rows, cols);
	print(arr, rows, cols);
	int ex;
	arr = push_row_back(arr, rows,cols);
	arr = push_row_front(arr, rows,cols);
	cout << "Enter the numb of line to add: "; cin >> ex;
	arr = insert_row(arr, rows,cols, ex);
	print(arr, rows, cols);

	arr = pop_row_back(arr, rows);
	arr = pop_row_front(arr, rows);

	cout << "Enter the numb of line to delete: "; cin >> ex;
	arr = erase_row(arr, rows,ex);
	print(arr, rows, cols);

    push_col_back(arr, rows, cols);
	push_col_front(arr, rows, cols);
	cout << "Enter the numb of column add: "; cin >> ex;
	insert_col(arr, rows,cols, ex);

	//pop_col_back(arr, rows, cols);
	//pop_col_front(arr, rows, cols);
	//cout << "Enter the numb of column to delete: "; cin >> ex;
    //erase_col(arr, rows, cols,ex);
	print(arr, rows, cols);
	clear(arr, rows);
#endif
}


template<typename T>T* push_back(T arr[], int& n, T v)
{
	return insert(arr, n, n, v);
}
template<typename T>T* push_front(T arr[], int& n, T v)
{
	return insert(arr, n, 0, v);
}

template<typename T>T* pop_back(T arr[], int& n)
{
	return erase(arr, n, n-1);
}
template<typename T>T* pop_front(T arr[], int& n)
{
	return erase(arr, n, 0);
}

template<typename T>T* insert(T arr[], int& n, int indx, T val)
{
	T* buffer = new T[++n];
	for (int i = 0; i < n; i++)(i < indx ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[] arr;
	buffer[indx] = val;
	return buffer;
}
template<typename T>T* erase(T arr[], int& n, int indx)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = (i < indx ? arr[i] : arr[i + 1]);
	delete[] arr;
	return buffer;
}
int** allocate(int const rows, int const cols)
{
	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++)arr[i] = new int[cols];
	return arr;
}
template<typename T> void clear(T** arr,int rows)
{
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete[] arr;
}

template<typename T> T** push_row_back(T** arr, int& rows, int cols)
{
	return insert_row(arr, rows, cols, rows);
}
template<typename T>T** push_row_front(T** arr, int& rows, int cols)
{
	return insert_row(arr,rows,cols,0);
}
template<typename T> T** insert_row(T** arr, int& rows, int cols, int ex)
{
	T** buff = new T* [rows + 1];;
	for (int i = 0; i < rows; i++)
		(i < ex ? buff[i] : buff[i + 1]) = arr[i];
	delete[] arr;
	rows++;
	buff[ex] = new int[cols] {};
	return buff;
}

template<typename T>T** pop_row_back(T** arr, int &rows)
{
	return erase_row(arr, rows, rows-1);
}
template<typename T>T** pop_row_front(T** arr, int& rows)
{
	return erase_row(arr,rows,0);
}
template<typename T>T** erase_row(T** arr, int& rows, int ex)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)
		buffer[i] = (i < ex ? arr[i] : arr[i + 1]);
	delete[] arr[ex];
	delete[] arr;
	return buffer;
}

template<typename T>void push_col_back(T** arr, int rows, int& cols)
{
	insert_col(arr, rows, cols, cols);
}
template<typename T>void push_col_front(T** arr, int rows, int& cols)
{
	insert_col(arr,rows, cols, 0);
}
template<typename T>void insert_col(T** arr, int rows, int& cols, int ex)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
			(j < ex ? buffer[j] : buffer[j + 1]) = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>void pop_col_back(T** arr, int rows, int& cols)
{
	erase_col(arr, rows, cols, cols);
}
template<typename T>void pop_col_front(T** arr, int rows, int& cols)
{
	erase_col(arr, rows, cols, 0);
}
template<typename T>void erase_col(T** arr, int rows, int& cols, int ex)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = (j < ex ? arr[i][j] : arr[i][j + 1]);
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
