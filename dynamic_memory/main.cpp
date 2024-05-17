#include<iostream>
using namespace std;
#define dynamic_memory
#define tab "\t"

void fillrand(int arr[], int n);
void fillrand(char arr[], int n);
void fillrand(double arr[], int n);
void fillrand(int **arr, int rows, int cols);
void fillrand(double **arr, int rows, int cols);

template<typename T> void print(T arr[], int n);
template<typename T> void print(T** arr, int rows, int cols);

template<typename T>T* push_back(T arr[], int& n, T v);
template<typename T>T* push_front(T arr[], int& n, T v);

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);

template<typename T>T* insert(T arr[], int& n, int indx, T val);
template<typename T>T* erase(T arr[], int& n, int indx);

template<typename T>T** allocate(int const rows, int const cols);
template<typename T> void clear(T** arr,int rows);

template<typename T> T** push_row_back(T** arr, int& rows, int cols);
template<typename T> T** push_row_front(T** arr, int& rows, int cols);
template<typename T> T ** insert_row(T **arr, int &rows, int cols, int ex);

template<typename T>T**pop_row_back(T**arr, int &rows);
template<typename T>T** pop_row_front(T **arr, int &rows, int cols);
template<typename T>T** erase_row(T **arr, int &rows, int cols, int ex);

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
#ifdef dynamic_memory2
	int n, indx;
	cout << "Enter the size of list: "; cin >> n;
	char* arr = new char[n];
	fillrand(arr, n);
	print(arr, n);
	char v;
	cout << "Enter the numb of el: "; cin >> indx;
	cout << "Enter the value: "; cin >> v;
	arr = insert(arr, n, indx, v);
	print(arr, n);

	cout << "Enter the numb of el to delete: "; cin >> indx;
	arr = erase(arr, n, indx);
	print(arr, n);
	delete[] arr;
#endif 
#ifdef dynamic_memory
	int rows, cols;
	cout << "Enter the size of list: "; cin >> rows >> cols;
	typedef double DataType;
	DataType**arr = allocate<DataType>(rows, cols);
	fillrand(arr, rows, cols);
	print(arr, rows, cols);
	int ex;
	//arr = push_row_back(arr, rows,cols);
	//arr = push_row_front(arr, rows,cols);
	//print(arr, rows, cols);
	//cout << "Enter the numb of line to add: "; cin >> ex;
	//arr = insert_row(arr, rows,cols, ex);

	//arr = pop_row_back(arr, rows);
	//arr = pop_row_front(arr, rows, cols);
	//print(arr, rows, cols);

    //cout << "Enter the numb of line to delete: "; cin >> ex;
    //arr = erase_row(arr, rows, cols,ex);

    //push_col_back(arr, rows, cols);
	//push_col_front(arr, rows, cols);
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

void fillrand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void fillrand(char arr[], int n)
{
	for (int i = 0; i < n; i++)	*(arr + i) = rand();
}
void fillrand(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand()&100;
		arr[i] /= 100;
	}
}
void fillrand(int **arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)arr[i][j] = rand() % 100;
}
void fillrand(double** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
			arr[i][j] /= 100;
		}
}
template<typename T>void print(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>void print(T** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

template<typename T>T* push_back(T arr[], int& n, T v)
{
	//create a reverse array with memory we need
	T* arr1 = new T[n+1];
	//copy elements
	for (int i = 0; i < n; i++)arr1[i] = arr[i];
	//arr1[n] = value;
	delete[] arr;
	//add new el
	arr1[n] = v;
	n++;
	return arr1;
}
template<typename T>T* push_front(T arr[], int& n, T v)
{
	T* buffer = new T[n+1];
	for (int i = 0; i < n; i++)buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = v;
	n++;
	return buffer;
}

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
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
template<typename T>T** allocate(int const rows, int const cols)
{
	T** arr = new T*[rows];
	for (int i = 0; i < rows; i++)arr[i] = new T[cols];
	return arr;
}
template<typename T> void clear(T** arr,int rows)
{
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete[] arr;
}

template<typename T> T** push_row_back(T** arr, int& rows, int cols)
{
	return push_back(arr, rows, new T[cols]{});
}
template<typename T>T** push_row_front(T** arr, int& rows, int cols)
{
	return push_front(arr, rows, new T[cols]{});
}
template<typename T> T** insert_row(T** arr, int& rows, int cols, int ex)
{
	return insert(arr, rows, ex, new T[cols]{});
}

template<typename T>T** pop_row_back(T** arr, int &rows)
{
	delete[] arr[rows-1]; //delete the line from memory
	return pop_back(arr, rows);
}
template<typename T>T** pop_row_front(T** arr, int& rows, int cols)
{
	delete[] arr[0]; 
	return pop_front(arr, rows);
}
template<typename T>T** erase_row(T** arr, int& rows, int cols, int ex)
{
	delete[] arr[ex];
	return erase(arr, rows, ex);
}

template<typename T>void push_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//T() - default values ( usually 0)
		arr[i]= push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>void push_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>void insert_col(T** arr, int rows, int& cols, int ex)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols,ex, T());
		cols--;
	}
	cols++;
}

template<typename T>void pop_col_back(T** arr, int rows, int& cols)
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
template<typename T>void pop_col_front(T** arr, int rows, int& cols)
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
