#include "pch.h"
#include "CppUnitTest.h"
#include "../DoublyLinkedList/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTests
{
	TEST_CLASS(LinkedListUnitTests)
	{
	public:
		
		TEST_METHOD(TestPushFront)
		{
			List list;
			list.PushFront(14);
			Assert::AreEqual(list.First(), 14);
		}
	};
}
