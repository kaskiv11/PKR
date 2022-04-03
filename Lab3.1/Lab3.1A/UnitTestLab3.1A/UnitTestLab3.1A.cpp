#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.1A/Lab3.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab31A
{
	TEST_CLASS(UnitTestLab31A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int N = 1;
			Student* s = new Student[N];
			s->lastName = "Kaskiv";
			s->сourse = 2;
			s->specialty = (Specialty)1;
			s->physics = 5;
			s->maths = 5;
			s->comp_science = 3;

			Assert::IsTrue(LineSearchPhysics(s, N) >= 0.0);
		}
		TEST_METHOD(TestMethod2)
		{

			int N = 1;
			Student* s = new Student[N];
			s->lastName = "Kaskiv";
			s->сourse = 2;
			s->specialty = (Specialty)1;
			s->physics = 5;
			s->maths = 5;
			s->comp_science = 3;

			Assert::IsTrue(LineSearchPhysics(s, N) >= 0.0);
		}

		TEST_METHOD(TestMethod3)
		{

			int N = 2;
			Student* s = new Student[N];
			s[0].lastName = "Kaskiv";
			s[0].сourse = 2;
			s[0].specialty = (Specialty)1;
			s[0].physics = 5;
			s->comp_science = 3;

			s[1].lastName = "K";
			s[1].сourse = 3;
			s[1].specialty = (Specialty)2;
			s[1].physics = 5;
			s->comp_science = 3;
			Assert::IsTrue(LineSearchPhysics5(s, N) >= 2);
		}

		TEST_METHOD(TestMethod4)
		{

			int N = 2;
			Student* s = new Student[N];
			s[0].lastName = "Kaskiv";
			s[0].сourse = 2;
			s[0].specialty = (Specialty)1;
			s[0].physics = 4;
			s->comp_science = 3;

			Assert::IsTrue(LineSearchPhysics4(s, N) >= 1);
		}

		TEST_METHOD(TestMethod5)
		{

			int N = 3;
			Student* s = new Student[N];
			s[0].lastName = "Kaskiv";
			s[0].сourse = 2;
			s[0].specialty = (Specialty)1;
			s[0].physics = 3;
			s->comp_science = 3;

			s[1].lastName = "K";
			s[1].сourse = 3;
			s[1].specialty = (Specialty)2;
			s[1].physics = 5;
			s->comp_science = 3;

			s[2].lastName = "Kom";
			s[2].сourse = 2;
			s[2].specialty = (Specialty)4;
			s[2].physics = 3;
			Assert::IsTrue(LineSearchPhysics3(s, N) >= 2);
		}
	};
}
