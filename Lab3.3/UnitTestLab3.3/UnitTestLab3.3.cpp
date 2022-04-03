#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.3/Lab3.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33
{
	TEST_CLASS(UnitTestLab33)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Note* n = new Note[N];
			n[0].lastName = "a";
			n[0].firstName = "a";
			n[0].phone ="3896078";
			n[0].date.day = 12;
			n[0].date.month = 7;
			n[0].date.year=2008;

			Assert::IsTrue(PrintNote(n, N, "3896078") == 1);
		}
	};
}
