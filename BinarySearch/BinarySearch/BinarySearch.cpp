#include <iostream>
#include "BinarySearch.h"
#include <limits>
#include <ios>

void printArr(const int iarr[], const int& size) {
	for (int i = 0; i < size; i++) {
		std::cout << "[" << iarr[i] << "] ";
	}
	std::cout << "\n";
}

void insertionSort(int iarr[], int size) {
	int j = 1;
	int currentPoint = j;

	std::cout << "Sorting this array: \n";
	printArr(iarr, size);

	while (j < size) {
		while (j != 0) {
			if (iarr[j] < iarr[j - 1]) {
				// Swap the elements
				int aux = iarr[j];
				iarr[j] = iarr[j-1];
				iarr[j-1] = aux;
				
			}
			--j;
		}
		currentPoint++;
		j = currentPoint;
	}
	
	std::cout << "Result: \n";
	printArr(iarr, size);
}

int seqSearch(int iarr[], int num, int size) {

	int index = -1;

	for (int i = 0; i < size; i++) {
		if (iarr[i] == num) {
			index = i;
		}
	}
	if (index != -1) {
		std::cout << "Seq search found integer at index: #" << index << ".\n";
	}
	else {
		std::cout << "Seq search could not find the number " << num << "!\n";
	}

	return index;
}

int binarySearch(const int iarr[], const int& num, const int& size) {
	int start = 0;
	int end = size-1;

	int index = -1;

	while (start <= end && index == -1) {
		
		int mid = start + ((end - start) / 2);

		int v = iarr[mid];
		if (num == iarr[mid]) {
			index = mid;
		}
		else if (num < iarr[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	
	if (index != -1) {
		std::cout << "Binary search found integer at index: #" << index << ".\n";
	}
	else {
		std::cout << "Binary search could not find the number " << num << "!\n";
	}

	return index;
}

void output(int iarr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Index #" << i << ": " << iarr[i] << "\n";
	}
}


int main()
{
	const int SIZE = 8;
	int myArr[SIZE] = { 4, 1, 7, 12, 8, 13, 9, 21 };

	insertionSort(myArr, SIZE);

	bool running = true;
	while (running) {
		int num = 0;
		std::cout << "Enter an integer to search for: ";
		if (std::cin >> num) {
			binarySearch(myArr, num, SIZE);
		}
		else {
			std::cout << "Please enter a valid number!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

