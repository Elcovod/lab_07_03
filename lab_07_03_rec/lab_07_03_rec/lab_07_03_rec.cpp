#include <iostream>
#include <iomanip>

using namespace std;

void InputRecursive(int** arr, const int rowcount, const int colcount, int i, int j);
void PrintRecursive(int** arr, const int rowcount, const int colcount, int i, int j);
int CalcRecursive(int** arr, const int rowcount, const int colcount, int i, int currentSum);
bool RowHasNegativeRecursive(int* row, const int colcount, int j);
int SumRowRecursive(int* row, const int colcount, int j, int currentSum);
void MatchRecursive(int** arr, const int rowcount, const int colcount, int k, int limit, bool& foundAny);
bool CheckMatchRecursive(int** arr, int k, int rowcount, int i);

void Input(int** arr, const int rowcount, const int colcount) {
    InputRecursive(arr, rowcount, colcount, 0, 0);
}

void Print(int** arr, const int rowcount, const int colcount) {
    cout << endl;
    PrintRecursive(arr, rowcount, colcount, 0, 0);
    cout << endl;
}

int Calc(int** arr, const int rowcount, const int colcount) {
    return CalcRecursive(arr, rowcount, colcount, 0, 0);
}

void Match(int** arr, const int rowcount, const int colcount) {
    cout << "Indices k where k-th row matches k-th column: ";
    bool foundAny = false;
    int limit = (rowcount < colcount) ? rowcount : colcount;
    MatchRecursive(arr, rowcount, colcount, 0, limit, foundAny);

    if (!foundAny) {
        cout << "None";
    }
    cout << endl;
}

void InputRecursive(int** arr, const int rowcount, const int colcount, int i, int j) {
    if (i == rowcount) return;

    cout << "arr[" << i << "][" << j << "] = ";
    cin >> arr[i][j];

    if (j + 1 < colcount) {
        InputRecursive(arr, rowcount, colcount, i, j + 1);
    }
    else {
        InputRecursive(arr, rowcount, colcount, i + 1, 0);
    }
}

void PrintRecursive(int** arr, const int rowcount, const int colcount, int i, int j) {
    if (i == rowcount) return;

    cout << setw(4) << arr[i][j];

    if (j + 1 < colcount) {
        PrintRecursive(arr, rowcount, colcount, i, j + 1);
    }
    else {
        cout << endl;
        PrintRecursive(arr, rowcount, colcount, i + 1, 0);
    }
}

bool RowHasNegativeRecursive(int* row, const int colcount, int j) {
    if (j == colcount) return false; 
    if (row[j] < 0) return true;   
    return RowHasNegativeRecursive(row, colcount, j + 1);
}

int SumRowRecursive(int* row, const int colcount, int j, int currentSum) {
    if (j == colcount) return currentSum;
    return SumRowRecursive(row, colcount, j + 1, currentSum + row[j]);
}

int CalcRecursive(int** arr, const int rowcount, const int colcount, int i, int currentSum) {
    if (i == rowcount) return currentSum;

    if (RowHasNegativeRecursive(arr[i], colcount, 0)) {
        currentSum += SumRowRecursive(arr[i], colcount, 0, 0);
    }

    return CalcRecursive(arr, rowcount, colcount, i + 1, currentSum);
}
bool CheckMatchRecursive(int** arr, int k, int rowcount, int i) {
    if (i == rowcount) return true;
    if (arr[k][i] != arr[i][k]) return false;
    return CheckMatchRecursive(arr, k, rowcount, i + 1);
}

void MatchRecursive(int** arr, const int rowcount, const int colcount, int k, int limit, bool& foundAny) {
    if (k == limit) return;

    if (CheckMatchRecursive(arr, k, rowcount, 0)) {
        cout << k << " ";
        foundAny = true;
    }

    MatchRecursive(arr, rowcount, colcount, k + 1, limit, foundAny);
}

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