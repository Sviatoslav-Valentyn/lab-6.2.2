#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab 6.2.2\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int A[] = { 3, -8, 7, -1 };
			Modify(A, 4);
			Assert::AreEqual(A[1], 3);
		}
	};
}
