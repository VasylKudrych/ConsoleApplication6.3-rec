// lab 6.3 - rec
// варіант 24

#include <iostream>
#include <iomanip>
using namespace std;



int first_pair(int* a, const int size, int m, int i)
{
	if (i < size)
	{
		if (a[i] % 2 == 0)
		{
			m = a[i];
			return m; 
		}
		first_pair(a, size, m, i + 1);
	}
	else
		return m;
}

int max(int* a, const int size, int i, int m)
{
	if (i < size)
	{
		if (a[i] % 2 == 0)
		{
			if (a[i] > m)
				m = a[i];
		}
		max(a, size, i + 1, m);
	}
	else
		return m;
}
void Print(int* a, const int size, int i)
{
	if (i < size)
	{
		cout << setw(4) << a[i];
		Print(a, size, i + 1);
	}
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create(a, size, Low, High, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 20;

	int a[n];
	int m = 0;
	int i = 0;

	Create(a, n, -20, -1, 0);

	cout << "array = ";
	Print(a, n, 0);
	cout << '\n' << '\n' << "max" << setw(5) << max(a, n, 0, first_pair(a, n, 0, 0)) << '\n';
	m = 0;

	cout << "----------------------------------------" << '\n';
}
