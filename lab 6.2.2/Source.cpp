// Варіант 6(Рекурсивний спосіб)
#define NOMINMAX
#include <Windows.h>
#include <iostream>
using namespace std;

void Init(int b[], const int size, int i)
{
	if (i < size)
	{
		b[i] = -10 + rand() % 21;
		Init(b, size, i + 1);
	}
}

void Print(const int* const b, const int size, int i)
{
	if (i < size)
	{
		if (i == 0)
			cout << "{";
		cout << b[i];
		if (i != size - 1)
			cout << ", ";
		else cout << "}" << endl;
		Print(b, size, i + 1);
	}
}

void FirsIndex(const int b[], const int size, int& index, int i)
{
	if (i < size)
	{
		if (b[i] % 2 == 0)
		{
			index = i;
			return;
		}
		FirsIndex(b, size, index, i + 1);
	}
}

void IndexMin(const int* b, int size, int& min, int& index, int i)
{
	if (i < size)
	{
		if (b[i] < min && b[i] % 2 == 0) 
		{
			index = i;
			min = b[i];
		}
		IndexMin(b, size, min, index, i + 1);
		return;
	}
}

bool Modify(int b[], const int size)
{
	int index, min;
	FirsIndex(b, size, index, 0);
	min = b[index];

	IndexMin(b, size, min, index, 0);
	if (index != -1) 
	{
		int tmp = b[0];
		b[0] = b[index];
		b[index] = tmp;
		return true;
	}
	else return false;
}

int main()
{
	SetConsoleOutputCP(1251);

	srand(time(0));
	int n;
	cout << "n = "; cin >> n;
	int* b = new int[n];

	Init(b, n, 0);
	Print(b, n, 0);
	if (!Modify(b, n))
		cout << "Немає елемента, який підходить умові" << endl;
	Print(b, n, 0);

	delete[] b;
	b = nullptr;

	return 0;
}