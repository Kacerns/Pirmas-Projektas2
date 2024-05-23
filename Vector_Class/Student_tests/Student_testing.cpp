#include "pch.h"
#include "CppUnitTest.h"
#include "student.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Studenttesting
{
	TEST_CLASS(Studenttesting)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			stud A;
			Assert::AreEqual(A.getName(), string(""));
			Assert::AreEqual(A.getSurname(), string(""));
			Assert::AreEqual(A.getFinalMark(), float(0.0));
			Assert::AreEqual(A.getEgzamRez(), float(0.0));
			Assert::AreEqual(A.getHomeWorkSize(), 0);
		}

		TEST_METHOD(AssignmentConstructor)
		{
			vector<int> nd{ 8,10 };
			stud A(string("Test"), string("Test"), 0.0, nd);
			Assert::AreEqual(A.getName(), string("Test"));
			Assert::AreEqual(A.getSurname(), string("Test"));
			Assert::AreEqual(A.getFinalMark(), float(3.6));
			Assert::AreEqual(A.getEgzamRez(), float(0.0));
			Assert::AreEqual(A.getHomeWorkSize(), 2);
		}

		TEST_METHOD(CopyConstructor)
		{
			vector<int> nd{ 8,10 };
			stud A(string("Test"), string("Test"), 0.0, nd);
			stud B(A);
			Assert::AreEqual(A.getName(), B.getName());
			Assert::AreEqual(A.getSurname(), B.getSurname());
			Assert::AreEqual(A.getFinalMark(), B.getFinalMark());
			Assert::AreEqual(A.getEgzamRez(), B.getEgzamRez());
			Assert::AreEqual(A.getHomeWorkSize(), B.getHomeWorkSize());
		}

		TEST_METHOD(MoveOperator)
		{
			vector<int> nd{ 8,10 };
			stud A(string("Test"), string("Test"), 0.0, nd);
			stud B;
			B = std::move(A);
			Assert::AreEqual(B.getName(), string("Test"));
			Assert::AreEqual(B.getSurname(), string("Test"));
			Assert::AreEqual(B.getFinalMark(), float(3.6));
			Assert::AreEqual(B.getEgzamRez(), float(0.0));
			Assert::AreEqual(B.getHomeWorkSize(), 2);
		}
	};
}
