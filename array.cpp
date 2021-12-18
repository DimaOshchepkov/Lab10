#include <iostream>
#include <cmath>
#include <tuple>
int** createArr(int n, int m)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	return arr;
}
int** fillArr(int** arr, int n, int m)
{
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rand() % (30 + 30 + 1) - 30;
	return arr;
}
void printArr(int** arr,int n,int m)
{
	std::cout << "Array now:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << arr[i][j] << " ";
		std::cout << '\n';
	}
}
int** fillArr09()
{
	int **arr = createArr(10, 10);
	int i = 0;
	while (i <= 9)
	{
		int j = 0;
		while (j <= 9)
		{
			arr[i][j] = (i + j) % 10;
			j++;
		}
		i++;
	}
	return arr;
}
int countEntry(int** arr, int n, int m, int num)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			count += (arr[i][j] == num);
	return count;
}
void deleteArr(int** arr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
void printColumn(int** arr, int n, int m)
{
	int* sumColumn = new int[m];
	int maxSumColumn = 0, countColumn = -1;
	for (int i = 0; i < m; i++)
		sumColumn[i] = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			sumColumn[i] += abs(arr[j][i]);
	for (int i = 0; i < m; i++)
		if (sumColumn[i] >= maxSumColumn)
		{
			maxSumColumn = sumColumn[i];
			countColumn = i;
		}
	for (int i = 0; i < n; i++)
		std::cout << arr[i][countColumn] << '\n';
}
int** convertArr(int** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
				arr[i][j] *= arr[i][0];
			else
				arr[i][j] *= arr[n - 1][j];
		}
	return arr;
}
int* crateArr1d(int** arr, int n, int m)
{
	int* arr1d = new int[n];
	for (int i = 0; i < n; i++)
	{
		int max = INT_MIN;
		for (int j = 0; j < m; j++)
			if (max < arr[i][j])
				max = arr[i][j];
		arr1d[i] = max;
	}
	return arr1d;
}
void printArr1d(int* arr1d, int n)
{
	std::cout << "Array 1d now:\n";
	for (int i = 0; i < n; i++)
		std::cout << arr1d[i] << ' ';
	std::cout << '\n';
}
int searchRow(int** arr, int n, int m)
{
	int result = -1;
	bool isGrow = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
			isGrow *= (arr[i][j] > arr[i][j - 1]);
		if (isGrow)
			result = i;
		isGrow = true;
	}
	return result;
}
int maxInOblast(int** arr, int k)
{
	int max = INT_MIN;
	for (int i = 0; i < k / 2; i++)
		for (int j = i; j < k - i; j++)
			if (max < arr[j][i])
				max = arr[j][i];
	for (int i = k - 1; i >= k / 2; i--)
		for (int j = (k - 1) - i; j <= i; j++)
			if (max < arr[j][i])
				max = arr[j][i];
	return max;
}
void equalElements(int** arr, int** arr2, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == arr2[i][j])
				std::cout << "(" << i << ", " << j << ")\t";
	std::cout << '\n';
}
void reverseRow(int** arr,int n)
{
	for (int i = 0; i < n/2; i++)
	{
	    int *t = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = t;
	}
}
int** sudoku(int** arr, int k)
{
	int num = k / 2;
	for (int h = 0; h < k; h++)
	{
		for (int i = h; i < k - h; i++)
			for (int j = h; j < k - h; j++)
				arr[i][j] = num;
		num -= 1;
	}
	return arr;
}
int** snakeA(int** arr, int n, int m)
{
	int count = 1;
	for (int i = 0; i < m; i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < n; j++)
			{
				arr[j][i] = count;
				count += 1;
			}
		else
			for (int j = n - 1; j >= 0; j--)
			{
				arr[j][i] = count;
				count += 1;
			}
	}
	return arr;
}
int** snakeB(int** arr, int n, int m)
{
	int up = 0, right = m - 1, down = n - 1, left = 0;
	int i = 0, j = 0, count = 1;
	while (n * m > count)
	{
		for (int j = left; j <= right; j++)
		{
			i = up;
			*(*(arr + i) + j) = count;
			count++;
		}
		up++;
		for (int i = up; i<= down; i++)
		{
			j = right;
			*(*(arr + i) + j) = count;
			count++;
		}
		right--;
		for (int j = right; j >= left; j--)
		{
			i = down;
			*(*(arr + i) + j) = count;
			count++;
		}
		down--;
		for (int i = down; i >= up; i--)
		{
			j = left;
			*(*(arr + i) + j) = count;
			count++;
		}
		left++;
	}
	return arr;
}
int** deleteRow(int** arr, int* n, int k)
{
	*n -= 1;
	int** arrNew = new int* [*n];
	if (k >= 0 && k < *n + 1)
	{
		for (int i = 0; i < k; i++)
			*(arrNew + i) = *(arr + i);
		for (int i = k; i < *n; i++)
			*(arrNew + i) = *(arr + i + 1);
	}
	return arrNew;
}
std::tuple<int**, int> deleteRowsWithElement(int** arr, int* n, int m, int k)
{
	bool flag = false;
	for(int i = *n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == k)
			{
				flag = true;
				arr = deleteRow(arr, n, i);
				break;
			}
	return std::make_tuple(arr, flag);
	
}
int** createStrightArr(int k)
{
	int** arr = new int* [k];
	for (int i = 0; i < k; i++)
		*(arr + i) = new int[i + 1];
	for (int i = 0; i < k; i++)
		for (int j = 0; j <= i; j++)
			*(*(arr + i) + j) = i + 1;
	return arr;
}
void printStrightArr(int** strightArr, int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j <= i; j++)
			std::cout << *(*(strightArr + i) + j) << ' ';
		std::cout << '\n';
	}
}


