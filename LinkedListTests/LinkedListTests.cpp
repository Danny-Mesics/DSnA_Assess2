#include "pch.h"
#include "CppUnitTest.h"
#include "../Dynamic Array/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{
	TEST_CLASS(LinkedListTests)
	{
	public:
		
		TEST_METHOD(TestPushBack)
		{
			List testList;
			testList.PushBack(5);
			Assert::AreEqual(testList.Last(), 5);
		}

		TEST_METHOD(TestInsert) 
		{
			List testList;
			for (int i = 0; i < 5; i++) {
				testList.PushBack(i);
			}

			for (auto i = testList.Begin(); i != testList.End(); i++) {
				if (*i == 3) {
					testList.Insert(i, 14);
				}
			}

			for (auto i = testList.Begin(); i != testList.End(); i++) {
				if (*i == 3) {
					Assert::AreEqual(*(++i), 14);
				}
			}

		}
	};
}
