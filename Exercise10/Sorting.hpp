#ifndef _SORTING_HPP_
#define _SORTING_HPP_

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
		int i = begin, j = end - 1;
		while (i < j) {
			while (TArray[i] < pivot) {
				i++;
			}
			while (pivot < TArray[j]) {
				j--;
			}
			if (i < j) {
				T temp = TArray[i];
				TArray[i] = TArray[j];
				TArray[j] = temp;
				i++;
				j--;
			}
			else if (i == j) {
				i++;
				j--;
			}
		}

		// Recursion
		if (begin < j) {
			quick_sort(TArray, begin, j + 1);
		}
		if (i < end - 1) {
			quick_sort(TArray, i, end);
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


		return;
	}
};

#endif // _SORTING_HPP_
