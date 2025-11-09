#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_07_03_it\lab_07_03_it\lab_07_03_it.cpp"
int Calc(int** arr, const int rowcount, const int colcount);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_MatrixOps
{
	TEST_CLASS(CalcTests)
	{
	public:

		TEST_METHOD(Test_Calc_MixedRows)
		{
			const int ROWS = 3;
			const int COLS = 3;
			int** arr = new int* [ROWS];
			for (int i = 0; i < ROWS; ++i)
				arr[i] = new int[COLS];

			arr[0][0] = 10; arr[0][1] = -5; arr[0][2] = 20;

			arr[1][0] = 1;  arr[1][1] = 2;  arr[1][2] = 3;

			arr[2][0] = -1; arr[2][1] = 0;  arr[2][2] = 1;

			int expected = 25;

			int actual = Calc(arr, ROWS, COLS);

			Assert::AreEqual(expected, actual, L"Calc обчислив неправильну суму.");

			for (int i = 0; i < ROWS; ++i)
				delete[] arr[i];
			delete[] arr;
		}

		TEST_METHOD(Test_Calc_AllPositive)
		{
			const int ROWS = 2;
			const int COLS = 2;
			int** arr = new int* [ROWS];
			for (int i = 0; i < ROWS; ++i)
				arr[i] = new int[COLS];

			arr[0][0] = 1; arr[0][1] = 2;
			arr[1][0] = 3; arr[1][1] = 4;

			int expected = 0;
			int actual = Calc(arr, ROWS, COLS);

			Assert::AreEqual(expected, actual, L"Calc мав повернути 0 для матриці без від'ємних елементів.");

			for (int i = 0; i < ROWS; ++i)
				delete[] arr[i];
			delete[] arr;
		}
	};
}