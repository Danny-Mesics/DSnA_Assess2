//#pragma once
//#include <iostream>
//
//class DynamicArray
//{
//protected:
//	int elementsCount;
//	int elementsUsed;
//	int* elements;
//
//public:
//	DynamicArray() : DynamicArray(10) {
//	}
//
//	DynamicArray(int size) : elementsCount{ size }, elementsUsed{ 0 }, elements{ new int[elementsCount] } {
//	}
//
//	~DynamicArray() {
//		delete[] elements;
//	}
//
//	void PushBack(int data) {
//		if (IsAtCapacity()) {
//			if (elementsCount < 100) {
//				DoubleSize();
//			}
//			else {
//				IncreaseSize(20);
//			}
//		}
//
//		elements[elementsUsed] = data;
//		elementsUsed++;
//	}
//
//	int PopBack() {
//		elementsUsed--;
//		return elements[elementsUsed];
//	}
//
//	void IncreaseSize(int amountToAdd) {
//		int* newArray = new int[elementsCount + amountToAdd];
//
//		for (int i = 0; i < elementsUsed; i++) {
//			newArray[i] = std::move(elements[i]);
//		}
//
//		delete elements;
//		elements = newArray;
//	}
//
//	void DoubleSize() {
//		IncreaseSize(elementsCount * 2);
//	}
//
//	bool IsEmpty() {
//		return elementsCount == 0;
//	}
//	bool IsAtCapacity() {
//		return elementsCount == elementsUsed;
//	}
//
//
//	int operator[](const int i) {
//		return elements[i];
//	}
//
//
//
//
//
//
//
//
//
//
//	//Copy
//	DynamicArray(const DynamicArray& other) {
//		// set values to be the other's values
//		elementsCount = other.elementsCount;
//		elementsUsed = other.elementsUsed;
//		elements = new int[std::max(elementsCount, 10)];
//
//		// loop through array and set each elements value to the value of the old array
//		for (int i = 0; i < elementsUsed; i++) {
//			elements[i] = other.elements[i];
//		}
//
//
//	}
//
//	//Move
//	DynamicArray(DynamicArray&& other) noexcept {
//		elementsCount = other.elementsCount;
//		elementsUsed = other.elementsUsed;
//
//		elements = std::move(other.elements);
//
//		other.elementsCount = 0;
//		other.elementsUsed = 0;
//		other.elements = nullptr;
//
//	}
//
//	//Assignment Copy
//
//	DynamicArray& operator=(const DynamicArray& other) {
//		// set values to be the other's values
//		elementsCount = other.elementsCount;
//		elementsUsed = other.elementsUsed;
//		elements = new int[std::max(elementsCount, 10)];
//
//		// loop through array and set each elements value to the value of the old array
//		for (int i = 0; i < elementsUsed; i++) {
//			elements[i] = other.elements[i];
//		}
//		return *this;
//	}
//
//	//Assignment Move
//	DynamicArray& operator=(DynamicArray&& other) noexcept {
//		elementsCount = other.elementsCount;
//		elementsUsed = other.elementsUsed;
//
//		elements = std::move(other.elements);
//
//		other.elementsCount = 0;
//		other.elementsUsed = 0;
//		other.elements = nullptr;
//
//		return *this;
//	}
//
//};
