#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void MaxRow(int** a, const int rowNo, const int colCount, int colNo, int& num, int& max);
void Max(int** a, const int rowCount, const int colCount, int rowNo, int& max);


int main()
{
	srand((unsigned)time(NULL));

	int Low = 0;
	int High = 31;

	int rowCount; // рядки матриці
	int colCount; // колонки матриці
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	int max = 0;
	Max(a, rowCount, colCount, 0, max);
	cout << max << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void MaxRow(int** a, const int rowNo, const int colCount, int colNo, int& num, int& max)
{
	if (a[rowNo][colNo] > num)
		num = a[rowNo][colNo];
	if (colNo < colCount - 1)
		MaxRow(a, rowNo, colCount, colNo + 1, num, max);
	else
		max += num;
}


void Max(int** a, const int rowCount, const int colCount, int rowNo, int& max)
{
	if (rowNo < rowCount) { // перевірка чи ще потрібно провіряти далі, чи рядки закінчились
	int num = a[rowNo][0];
		MaxRow(a, rowNo, colCount, 0, num, max); 
		Max(a, rowCount, colCount, rowNo + 1, max);
}

}
