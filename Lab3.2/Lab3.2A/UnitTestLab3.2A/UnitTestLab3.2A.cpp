#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.2A/Lab3.2A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab32A
{
	TEST_CLASS(UnitTestLab32A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 3;
			Student* s = new Student[N];
			s[0].lastName = "b";
			s[0].сourse = 1;
			s[0].specialty = (Specialty)1;
			s[0].physics = 3;
			s[0].maths = 3;
			

			s[1].lastName = "c";
			s[1].сourse = 2;
			s[1].specialty = (Specialty)2;
			s[1].physics = 4;
			s[1].maths = 4;
			

			s[2].lastName = "d";
			s[2].сourse = 3;
			s[2].specialty = (Specialty)3;
			s[2].physics = 5;
			s[2].maths = 5;

			Sort(s, N);
			Assert::AreEqual(1, BinSearch(s, N, "c", 2, 4));
		}
	};
}
