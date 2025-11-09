#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07_03_rec/lab_07_03_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_RecursiveMatrix
{
	TEST_CLASS(RecursiveCalcTests)
	{
	public:

		TEST_METHOD(Test_Calc_MixedRows)
		{
			const int K = 3;
			int** arr = new int* [K];
			for (int i = 0; i < K; ++i)
				arr[i] = new int[K];

			arr[0][0] = 10; arr[0][1] = -5; arr[0][2] = 20;

			arr[1][0] = 1;  arr[1][1] = 2;  arr[1][2] = 3;

			arr[2][0] = -1; arr[2][1] = 0;  arr[2][2] = 1;

			int expected_sum = 25;

			int actual_sum = Calc(arr, K, K);

			Assert::AreEqual(expected_sum, actual_sum, L"Calc обчислив неправильну суму для змішаних рядків.");

			for (int i = 0; i < K; ++i) delete[] arr[i];
			delete[] arr;
		}

		TEST_METHOD(Test_Calc_NoNegatives)
		{
			const int K = 2;
			int** arr = new int* [K];
			for (int i = 0; i < K; ++i) arr[i] = new int[K];

			arr[0][0] = 1; arr[0][1] = 2;
			arr[1][0] = 3; arr[1][1] = 4;

			int expected_sum = 0;
			int actual_sum = Calc(arr, K, K);

			Assert::AreEqual(expected_sum, actual_sum, L"Calc мав повернути 0, бо від'ємних чисел немає.");

			for (int i = 0; i < K; ++i) delete[] arr[i];
			delete[] arr;
		}

		TEST_METHOD(Test_Calc_AllNegatives)
		{
			const int K = 2;
			int** arr = new int* [K];
			for (int i = 0; i < K; ++i) arr[i] = new int[K];

			arr[0][0] = -1; arr[0][1] = -2;
			arr[1][0] = -3; arr[1][1] = -4;

			int expected_sum = -10;
			int actual_sum = Calc(arr, K, K);

			Assert::AreEqual(expected_sum, actual_sum, L"Calc обчислив неправильну суму, коли всі рядки з від'ємними.");

			for (int i = 0; i < K; ++i) delete[] arr[i];
			delete[] arr;
		}
	};
}