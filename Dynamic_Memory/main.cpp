#include <iostream>
using namespace std;

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);
void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);
void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	
	Fillrand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите значение, которое нужно добавить в конец массива: " ; cin >> value;
	push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите значение, которое нужно добавить в начало массива: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите значение, которое нужно добавить в определеный индекс массива: "; cin >> value;
	cout << "Введите индекс массива: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "\n Наш массив без последнего элемента: " << endl;
	pop_back(arr, n);
	Print(arr, n);

	cout << "\n Наш массив без первого элемента: " << endl;
	pop_front(arr, n);
	Print(arr, n);


}


void Fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout <<arr[i] << "\t";
	}
	cout << endl;
}

void push_back(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;

}
void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr; 
	arr = buffer;
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
}





