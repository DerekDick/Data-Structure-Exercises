#ifndef _SORTING_HPP_
#define _SORTING_HPP_

#include <cmath> // For floor(), log10(), abs() and pow()

class Sorting {
public:
	template <class T>
	static void bubble_sort(T TArray[], int begin, int end) {
		/*
		* Sorts the array of the type T using bubble sorting algorithm
		* Soring range: [begin, end)
		*/

		for (int i = end - 1; i > begin; i--) {
			for (int j = begin; j < i; j++) {
				if (TArray[j] > TArray[j + 1]) {
					T temp = TArray[j];
					TArray[j] = TArray[j + 1];
					TArray[j + 1] = temp;
				}
			}
		}

		return;
	}

	template <class T>
	static void quick_sort(T TArray[], int begin, int end) {
		/*
		* Sorts the array of the type T using quick sorting algorithm
		* Soring range: [begin, end)
		*/

		// Set the pivot
		int pivot = TArray[end - 1];

		// Partition
		int leftIndex = begin, rightIndex = end - 1;
		while (leftIndex < rightIndex) {
			while (TArray[leftIndex] < pivot) {
				leftIndex++;
			}
			while (pivot < TArray[rightIndex]) {
				rightIndex--;
			}
			if (leftIndex < rightIndex) {
				T temp = TArray[leftIndex];
				TArray[leftIndex] = TArray[rightIndex];
				TArray[rightIndex] = temp;
				leftIndex++;
				rightIndex--;
			}
			else if (leftIndex == rightIndex) {
				leftIndex++;
				rightIndex--;
			}
		}

		// Recursion
		if (begin < rightIndex) {
			quick_sort(TArray, begin, rightIndex + 1);
		}
		if (leftIndex < end - 1) {
			quick_sort(TArray, leftIndex, end);
		}

		return;
	}

	template <class T>
	static void selection_sort(T TArray[], int begin, int end) {
		/*
		* Sorts the array of the type T using selection sorting algorithm
		* Soring range: [begin, end)
		*/

		for (int i = begin; i < end - 1; i++) {
			int minIndex = i;
			for (int j = i; j < end; j++) {
				if (TArray[minIndex] > TArray[j]) {
					minIndex = j;
				}
			}
			T temp = TArray[i];
			TArray[i] = TArray[minIndex];
			TArray[minIndex] = temp;
		}

		return;
	}

	template <class T>
	static void insertion_sort(T TArray[], int begin, int end) {
		/*
		* Sorts the array of the type T using insertion sorting algorithm
		* Soring range: [begin, end)
		*/

		for (int i = begin; i < end; i++) {
			T current = TArray[i];
			int j = i - 1;
			while (j >= begin) {
				if (current < TArray[j]) {
					TArray[j + 1] = TArray[j];
				}
				else {
					TArray[j + 1] = current;
					break;
				}
				j--;
			}
			if (j == begin - 1) {
				TArray[begin] = current;
			}
		}

		return;
	}

	template <class T>
	static void merge_sort(T TArray[], int begin, int end) {
		/*
		* Sorts the array of the type T using merge sorting algorithm
		* Soring range: [begin, end)
		*/

		if (end - begin == 1) {
			return;
		}

		else {
			// Partition
			int middle = (begin + end - 1) / 2;
			merge_sort(TArray, begin, middle + 1);
			merge_sort(TArray, middle + 1, end);

			// Merge
			int leftLength = (middle + 1) - begin;
			int rightLength = end - (middle + 1);
			T* leftCopy = new T[leftLength];
			T* rightCopy = new T[rightLength];
			for (int i = 0; i < leftLength; i++) {
				leftCopy[i] = TArray[begin + i];
			}
			for (int i = 0; i < rightLength; i++) {
				rightCopy[i] = TArray[middle + 1 + i];
			}
			int leftIndex = 0;
			int rightIndex = 0;
			for (int i = begin; i < end; i++) {
				if (leftIndex == leftLength) {
					TArray[i] = rightCopy[rightIndex];
					rightIndex++;
				}
				else if (rightIndex == rightLength) {
					TArray[i] = leftCopy[leftIndex];
					leftIndex++;
				}

				else if (leftCopy[leftIndex] < rightCopy[rightIndex]) {
					TArray[i] = leftCopy[leftIndex];
					leftIndex++;
				}
				else {
					TArray[i] = rightCopy[rightIndex];
					rightIndex++;
				}
			}
			delete[] leftCopy;
			delete[] rightCopy;

			return;
		}
	}

	static void radix_sort(int intArray[], int begin, int end) {
		/*
		* Sorts the array of integers using radix sorting algorithm
		* Using bubble sorting algorithm for every layer of sorting
		* Soring range: [begin, end)
		*/

		// Find the maximum value among the elements to be sorted
		int maxValue = intArray[begin];
		for (int i = begin; i < end; i++) {
			if (maxValue < intArray[i]) {
				maxValue = intArray[i];
			}
		}

		// Get the max digit length
		int digitLength = floor(log10(abs(maxValue))) + 1;

		// Sort the array in loops according to every single digit of the integers
		for (int i = 0; i < digitLength; i++) {
			for (int j = end - 1; j > begin; j--) {
				for (int k = begin; k < j; k++) {
					// Get the two digit of the two numbers to be compared
					int digit_k = getDigitAtIndex(intArray[k], i);
					int digit_k_1 = getDigitAtIndex(intArray[k + 1], i);
					
					// Compare the two numbers
					if (digit_k > digit_k_1) {
						int temp = intArray[k];
						intArray[k] = intArray[k + 1];
						intArray[k + 1] = temp;
					}
				}
			}
		}


		return;
	}

	static int getDigitAtIndex(int integer, int index) {
		// Return the digit at the index of an integer
		if (!index) {
			return integer % (int)pow(10, index + 1);
		}
		else {
			return (integer % (int)pow(10, index + 1)) / (int)pow(10, index);
		}
	}

	template <class T>
	static void heap_sort(T TArray[], int begin, int end) {
		/*
		* Sorts the array of the type T using heap sorting algorithm
		* Soring range: [begin, end)
		*/



		return;
	}
};

#endif // _SORTING_HPP_
