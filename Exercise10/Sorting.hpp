#ifndef _SORTING_HPP_
#define _SORTING_HPP_

#include <cmath> // For floor(), log10(), abs() and pow()

class Sorting {
public:
	Sorting() = default;
	~Sorting() = default;

	template <class T>
	static int bubble_sort(T TArray[], int begin, int end);

	template <class T>
	static void quick_sort(T TArray[], int begin, int end, int& swapTimes);

	template <class T>
	static int selection_sort(T TArray[], int begin, int end);

	template <class T>
	static int insertion_sort(T TArray[], int begin, int end);

	template <class T>
	static void merge_sort(T TArray[], int begin, int end, int& compareTimes);

	static void radix_sort(int intArray[], int begin, int end) {
		/*
		* Sorts the array of integers using radix sorting algorithm
		* Using bubble sorting algorithm for every layer of sorting
		* Soring range: [begin, end)
		* Return the number of swap times
		*/

		int swapTimes = 0;

		// Find the maximum value among the elements to be sorted
		int maxValue = intArray[begin];
		for (int i = begin; i < end; i++) {
			if (maxValue < intArray[i]) {
				maxValue = intArray[i];
			}
		}

		// Get the max digit length
		int digitLength = (int)floor(log10(abs(maxValue))) + 1;

		// Sort the array in loops according to every single digit of the integers
		for (int i = 0; i < digitLength; i++) {
			insertion_sort_for_radix_sort(intArray, begin, end, i);
		}

		return;
	}

	template <class T>
	static void heap_sort(T TArray[], int begin, int end, int & swapTimes, int & compareTimes);

	template <class T>
	static int shell_sort(T TArray[], int begin, int end);

private:
	static int getDigitAtIndex(int integer, int index) {
		// Return the digit at the index of an integer
		if (!index) {
			return integer % (int)pow(10, index + 1);
		}
		else {
			return (integer % (int)pow(10, index + 1)) / (int)pow(10, index);
		}
	}

	static void insertion_sort_for_radix_sort(int intArray[], int begin, int end, int digitIndex) {
		/*
		* Sorts the array of the type int using insertion sorting algorithm
		* Soring range: [begin, end)
		*/
		for (int i = begin; i < end; i++) {
			int current = intArray[i];
			int j = i - 1;
			while (j >= begin) {
				if (getDigitAtIndex(current, digitIndex) < getDigitAtIndex(intArray[j], digitIndex)) {
					intArray[j + 1] = intArray[j];
				}
				else {
					intArray[j + 1] = current;
					break;
				}
				j--;
			}
			if (j == begin - 1) {
				intArray[begin] = current;
			}
		}

		return;
	}
	/*template <class T>
	void heapRebuild(T V[], const int root, const int size, int& count, int& compareNum);*/
};

template <class T>
static int Sorting::bubble_sort(T TArray[], int begin, int end) {
	/*
	* Sorts the array of the type T using bubble sorting algorithm
	* Soring range: [begin, end)
	* Return the number of swap times
	*/

	int swapTimes = 0;

	for (int i = end - 1; i > begin; i--) {
		for (int j = begin; j < i; j++) {
			if (TArray[j] > TArray[j + 1]) {
				swapTimes++;
				T temp = TArray[j];
				TArray[j] = TArray[j + 1];
				TArray[j + 1] = temp;
			}
		}
	}

	return swapTimes;
}

template <class T>
static void Sorting::quick_sort(T TArray[], int begin, int end, int& swapTimes) {
	/*
	* Sorts the array of the type T using quick sorting algorithm
	* Soring range: [begin, end)
	* Return the number of swap times
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
			swapTimes++;

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
		quick_sort(TArray, begin, rightIndex + 1, swapTimes);
	}
	if (leftIndex < end - 1) {
		quick_sort(TArray, leftIndex, end, swapTimes);
	}

	return;
}

template <class T>
static int Sorting::selection_sort(T TArray[], int begin, int end) {
	/*
	* Sorts the array of the type T using selection sorting algorithm
	* Soring range: [begin, end)
	* Return the number of swap times
	*/

	int swapTimes = 0;

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
		swapTimes++;
	}

	return swapTimes;
}

template <class T>
static int Sorting::insertion_sort(T TArray[], int begin, int end) {
	/*
	* Sorts the array of the type T using insertion sorting algorithm
	* Soring range: [begin, end)
	* Return the number of swap times
	*/

	int swapTimes = 0;

	for (int i = begin; i < end; i++) {
		T current = TArray[i];
		int j = i - 1;
		while (j >= begin) {
			if (current < TArray[j]) {
				TArray[j + 1] = TArray[j];
				swapTimes++;
			}
			else {
				TArray[j + 1] = current;
				swapTimes++;
				break;
			}
			j--;
		}
		if (j == begin - 1) {
			TArray[begin] = current;
		}
	}

	return swapTimes;
}

template <class T>
static void Sorting::merge_sort(T TArray[], int begin, int end, int& compareTimes) {
	/*
	* Sorts the array of the type T using merge sorting algorithm
	* Soring range: [begin, end)
	* Return the number of swap times
	*/

	if (end - begin == 1) {
		return;
	}

	else {
		// Partition
		int middle = (begin + end - 1) / 2;
		merge_sort(TArray, begin, middle + 1, compareTimes);
		merge_sort(TArray, middle + 1, end, compareTimes);

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
				compareTimes++;
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

template <class T>
static void Sorting::heap_sort(T TArray[], int begin, int end, int & swapTimes, int & compareTimes) {
	/*
	* Sorts the array of the type T using heap sorting algorithm
	* Soring range: [begin, end)
	* Return the number of swap times
	*/

	for (int i = end - 1; i >= 0; i--) {
		heapRebuild(TArray, i, end, swapTimes, compareTimes);
	}
	int last = end - 1;
	for (int i = 1; i <= end; i++, last--) {
		swapTimes++;
		T temp = TArray[0];
		TArray[0] = TArray[last];
		TArray[last] = temp;
		heapRebuild(TArray, 0, last, swapTimes, compareTimes);
	}

	return;
}

template <class T>
static int Sorting::shell_sort(T TArray[], int begin, int end) {
	/*
	* Sorts the array of the type T using Shell sorting algorithm
	* Soring range: [begin, end)
	* Return the number of swap times
	*/

	int swapTimes = 0;
	int left = begin, right = end - 1;
	int i, j, gap = right - left + 1;
	T temp;
	do {
		gap = gap / 3 + 1;
		for (i = left + gap; i <= right; i++) {
			if (TArray[i] < TArray[i - gap]) {
				temp = TArray[i];
				j = i - gap;
				do {
					swapTimes++;
					TArray[j + gap] = TArray[j];
					j = j - gap;
				} while (j >= left && temp < TArray[j]);
				TArray[j + gap] = temp;
			}
		}
	} while (gap > 1);
	return swapTimes;
}

template <class T>
void heapRebuild(T V[], const int root, const int size, int& count, int& compareNum) {
	int child = 2 * root + 1;
	compareNum++;
	if (child <= size - 1) {
		int rightChild = child + 1;
		compareNum++;
		if (rightChild <= size - 1) {
			compareNum++;
			if (V[child] < V[rightChild]) {
				child = rightChild;
			}
		}
		compareNum++;
		if (V[root]<V[child]) {
			count++;
			T temp = V[child];
			V[child] = V[root];
			V[root] = temp;
			heapRebuild(V, child, size, count, compareNum);
		}
	}
}

#endif // _SORTING_HPP_
