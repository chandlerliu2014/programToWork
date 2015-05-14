//顺时针打印矩阵
//2015-05-14
//by chandler

#include <iostream>
using namespace std;

void printMatrix(int **numbers,int columns,int rows,int start);
void PrintMatrixClockwisely(int **numbers,int columns,int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start * 2 && rows > start * 2) {
		printMatrix(numbers,columns,rows,start);
		start++;
	}
}
void printMatrix(int **numbers,int columns,int rows,int start)
{
	int i;
	//从左往右
	for (i = start;i < columns - start;i++)
		cout << numbers[start][i] << " ";

	//从上往下
	for (i = start + 1;i < rows - start;i++)
		cout << numbers[i][columns - start - 1] << " ";

	//从右往左
	for (i = columns - start - 2;i >= start;i--)
		cout << numbers[rows - start - 1][i] << " ";

	//从下往上
	for (i = rows - start - 2;i > start;i--)
		cout << numbers[i][start] << " ";
	cout << endl;
}

int main(void)
{
	int **numbers = new int*[6];
	for (int i = 0;i < 6;i++) {
		numbers[i] = new int[6];
		for (int j = 0;j < 6;j++) {
			numbers[i][j] = j;
		}
	}
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 6;j++)
			cout << numbers[i][j] << " ";
		cout << endl;
	}
	 PrintMatrixClockwisely(numbers,6,6);
	return 0;
}
