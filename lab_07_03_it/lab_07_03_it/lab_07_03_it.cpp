#include <iostream>
#include <iomanip>

using namespace std;

void Input(int** arr, const int rowcount, const int colcount);
void Print(int** arr, const int rowcount, const int colcount);
int Calc(int** arr, const int rowcount, const int colcount);
void Match(int** arr, const int rowcount, const int colcount);

int main()
{
	int k;

	cout << "Enter matrix size: ";
	cin >> k;

	int** arr = new int* [k];
	for (int i = 0; i < k; i++)
		arr[i] = new int[k];

	Input(arr, k, k);
	Print(arr, k, k);

	int totalsum = Calc(arr, k, k);
	cout << "Total sum of rows with negative elements: " << totalsum << endl;

	Match(arr, k, k);

	for (int i = 0; i < k; i++)
		delete[] arr[i];
	delete[] arr; 
	return 0;

}

void Input(int **arr, const int rowcount, const int colcount)
{
	for (int i = 0; i < rowcount; i++)
		for (int j = 0; j < colcount; j++)
		{
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
}

void Print(int **arr, const int rowcount, const int colcount)
{
	cout << endl;
	for (int i = 0; i < rowcount; i++)
	{
		for (int j = 0; j < colcount; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
	cout << endl;
}

void Match(int ** arr, const int rowcount, const int colcount)
{
	cout << "Indices k where k-th row matches k-th column: ";
	bool foundAny = false;

	int limit = (rowcount < colcount) ? rowcount : colcount;

	for (int k = 0; k < limit; k++)
	{
		bool match = true;
		for (int i = 0; i < rowcount; i++)
		{
			if (arr[k][i] != arr[i][k])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			cout << k << " ";
			foundAny = true;
		}
	}
	if (!foundAny)
	{
		cout << "None";
		cout << endl;
	}
} 


int Calc(int** arr, const int rowcount, const int colcount)
{
	int sum = 0;
	for (int i = 0; i < rowcount; i++)
	{
		bool hasneg = false;
		for (int j = 0; j < colcount; j++)
		{
			if (arr[i][j] < 0)
			{
				hasneg = true;
				break;
			}
		}
		if (hasneg)
		{
			int rowsum = 0;
			for (int j = 0; j < colcount; j++)
			{
				rowsum += arr[i][j];
			}
			sum += rowsum;
		}
	}
	return sum;
}
