#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.2B/Lab3.2B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab32B
{
	TEST_CLASS(UnitTestLab32B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int N = 3;
			Student* s = new Student[N];
			s[0].lastName = "b";
			s[0].сourse = (Course)1;
			s[0].specialty = (Specialty)1;
			s[0].physics = 3;
			s[0].maths = 3;
			s[0].numMethods = 3;

			s[1].lastName = "c";
			s[1].сourse = (Course)2;
			s[1].specialty = (Specialty)2;
			s[1].physics = 4;
			s[1].maths = 4;
			s[1].numMethods = 4;

			s[2].lastName = "d";
			s[2].сourse = (Course)3;
			s[2].specialty = (Specialty)3;
			s[2].physics = 5;
			s[2].maths = 5;
			s[2].numMethods = 5;

			Sort(s, N);
			Assert::AreEqual(1, BinSearch(s, N, "c", (Course)2, 4));
			
		}

		TEST_METHOD(TestMethod2)
		{

			int N = 3;
			Student* s = new Student[N];
			s[0].lastName = "b";
			s[0].сourse = (Course)1;
			s[0].specialty = (Specialty)1;
			s[0].physics = 3;
			s[0].maths = 3;
			s[0].numMethods = 3;

			s[1].lastName = "c";
			s[1].сourse = (Course)2;
			s[1].specialty = (Specialty)2;
			s[1].physics = 4;
			s[1].maths = 4;
			s[1].numMethods = 4;

			s[2].lastName = "d";
			s[2].сourse = (Course)3;
			s[2].specialty = (Specialty)3;
			s[2].physics = 5;
			s[2].maths = 5;
			s[2].numMethods = 5;

			Sort(s, N);
			Assert::AreEqual(2, BinSearch(s, N, "d", (Course)3, 5));

		}
	};
}
