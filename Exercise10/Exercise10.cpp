
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sorting.hpp"

void displayOptions(void);

int main(int argc, char* argv[]) {
	// Display the welcoming information
	std::cout << "***********************************" << std::endl;
	std::cout << "*           Exercise 10           *" << std::endl;
	std::cout << "*        Sorting Algorithms       *" << std::endl;
	std::cout << "*          1552719 侯剑锋         *" << std::endl;
	displayOptions();
	
	// Prompt the uset to input the number of the random numbers to generate
	std::cout << "请输入您要产生的随机数的数量：" << std::endl;
	int number = 0;
	std::cin >> number;

	// Generate an array of random numbers
	int* integers = new int[number];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < number; i++) {
		integers[i] = rand() % number;
	}

	// Get the option of the user in loops and deal with every option
	char option = '\0';
	std::cout << "请选择排序算法：" << std::endl;
	while (std::cin >> option) {
		// Bubble sort
		if (option == '1') {
			// Copy the initial array
			int* copyArray = new int[number];
			for (int i = 0; i < number; i++) {
				copyArray[i] = integers[i];
			}

			// Sort the array
			std::clock_t beginTime = std::clock();
			int swapTimes = Sorting::bubble_sort(copyArray, 0, number);
			std::clock_t endTime = std::clock();

			// Release the allocated memory
			delete[] copyArray;

			// Display the result
			std::cout << "Bubble Sort 冒泡排序：" << std::endl;
			std::cout << '\t' << "Time 时间：" << endTime - beginTime << "ms" << std::endl;
			std::cout << '\t' << "Swap Times 交换次数：" << swapTimes << std::endl;
		}

		// Quick sort
		else if (option == '2') {
			// Copy the initial array
			int* copyArray = new int[number];
			for (int i = 0; i < number; i++) {
				copyArray[i] = integers[i];
			}

			// Sort the array
			int swapTimes = 0;
			std::clock_t beginTime = std::clock();
			Sorting::quick_sort(copyArray, 0, number, swapTimes);
			std::clock_t endTime = std::clock();

			// Release the allocated memory
			delete[] copyArray;

			// Display the result
			std::cout << "Quick Sort 快速排序：" << std::endl;
			std::cout << '\t' << "Time 时间：" << endTime - beginTime << "ms" << std::endl;
			std::cout << '\t' << "Swap Times 交换次数：" << swapTimes << std::endl;
		}

		// Sslection sort
		else if (option == '3') {
			// Copy the initial array
			int* copyArray = new int[number];
			for (int i = 0; i < number; i++) {
				copyArray[i] = integers[i];
			}

			// Sort the array
			std::clock_t beginTime = std::clock();
			int swapTimes = Sorting::selection_sort(copyArray, 0, number);
			std::clock_t endTime = std::clock();

			// Release the allocated memory
			delete[] copyArray;

			// Display the result
			std::cout << "Selection Sort 选择排序：" << std::endl;
			std::cout << '\t' << "Time 时间：" << endTime - beginTime << "ms" << std::endl;
			std::cout << '\t' << "Swap Times 交换次数：" << swapTimes << std::endl;
		}

		// Insertion sort
		else if (option == '4') {
			// Copy the initial array
			int* copyArray = new int[number];
			for (int i = 0; i < number; i++) {
				copyArray[i] = integers[i];
			}

			// Sort the array
			std::clock_t beginTime = std::clock();
			int swapTimes = Sorting::insertion_sort(copyArray, 0, number);
			std::clock_t endTime = std::clock();

			// Release the allocated memory
			delete[] copyArray;

			// Display the result
			std::cout << "Insertion Sort 插入排序：" << std::endl;
			std::cout << '\t' << "Time 时间：" << endTime - beginTime << "ms" << std::endl;
			std::cout << '\t' << "Swap Times 交换次数：" << swapTimes << std::endl;
		}

		// Merge sort
		else if (option == '5') {
			// Copy the initial array
			int* copyArray = new int[number];
			for (int i = 0; i < number; i++) {
				copyArray[i] = integers[i];
			}

			// Sort the array
			int compareTimes = 0;
			std::clock_t beginTime = std::clock();
			Sorting::merge_sort(copyArray, 0, number, compareTimes);
			std::clock_t endTime = std::clock();

			// Release the allocated memory
			delete[] copyArray;

			// Display the result
			std::cout << "Merge Sort 归并排序：" << std::endl;
			std::cout << '\t' << "Time 时间：" << endTime - beginTime << "ms" << std::endl;
			std::cout << '\t' << "Compare Times 比较次数：" << compareTimes << std::endl;
		}

		// Radix sort
		else if (option == '6') {

		}

		// Heap sort
		else if (option == '7') {

		}

		// Shell sort
		else if (option == '8') {

		}

		// Exit
		else if (option == '9') {
			break;
		}

		// Exceptions
		else {
			std::cout << "Illegal input!!!\a" << std::endl;
		}

		// Prompt the user select a sorting algorithm for the next loop
		displayOptions();
		std::cout << "请选择排序算法或退出：" << std::endl;
	}

	// Prepare to exit the program
	delete[] integers;
	std::cout << "Exiting... 即将退出程序..." << std::endl;

	return 0;
}

void displayOptions(void) {
	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << "*     1--Bubble Sort 冒泡排序     *" << std::endl;
	std::cout << "*     2--Quick Sort 快速排序      *" << std::endl;
	std::cout << "*     3--Selection Sort 选择排序  *" << std::endl;
	std::cout << "*     4--Insertion Sort 插入排序  *" << std::endl;
	std::cout << "*     5--Merge Sort 归并排序      *" << std::endl;
	std::cout << "*     6--Radix Sort 基数排序      *" << std::endl;
	std::cout << "*     7--Heap Sort 堆排序         *" << std::endl;
	std::cout << "*     8-- Sort 希尔排序           *" << std::endl;
	std::cout << "*     9--Exit 退出程序            *" << std::endl;
	std::cout << "===================================" << std::endl;
}
