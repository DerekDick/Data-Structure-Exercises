#include <iostream>
#include <utility> // For std::pair
#include <cstdlib> // For exit()
#include "CircularLinkedList.hpp"

void check(int N, int S, int M, int K);

int main(int argc, char* argv[]) {
	// Display the welcoming information
	std::cout << "***********************************" << std::endl;
	std::cout << "*           Exercise 02           *" << std::endl;
	std::cout << "*    约瑟夫环 Josephus Problem    *" << std::endl;
	std::cout << "*          1552719 侯剑锋         *" << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << "现有N人围成一圈，从第S个人开始依次报数，报M的人出局，" 
		<< "再由下一个人从1开始报数，如此循环，直到剩下K个人为止。" << std::endl;

	/*
	Prompt the user to input N, S, M and K
	N: The total number of people
	S: The starting index
	M: The size of the circular interval
	K: The number of the left people in the end
	*/
	int N = 0, S = 0, M = 0, K = 0;
	std::cout << std::endl;
	std::cout << "请输入生死游戏的总人数N：";
	std::cin >> N;
	std::cout << "请输入游戏开始的位置S：";
	std::cin >> S;
	std::cout << "请输入死亡数字M：";
	std::cin >> M;
	std::cout << "请输入剩余的生者人数：";
	std::cin >> K;

	// Check if the input is illegal
	check(N, S, M, K);

	// Create a CircularLinkedList and initialize it
	CircularLinkedList<std::pair<int, bool>> circularLinkedList = 
		CircularLinkedList<std::pair<int, bool>>();
	for (int i = 0; i < N; i++) {
		circularLinkedList.push_back(std::pair<int, bool>(i + 1, true));
	}

	// Kill (N - K) people in loops
	int currentIndex = S - 2;
	for (int i = 0; i < N - K; i++) {
		// Find the index of the people to kill
		int count = 0;
		while (count - M) {
			currentIndex = (currentIndex + 1) % N;
			if (circularLinkedList.at(currentIndex).second) {
				count++;
			}
		}

		// Kill one people
		circularLinkedList[currentIndex]
			.setData(std::pair<int, bool>(circularLinkedList.at(currentIndex).first, false));

		std::cout << "第" << i + 1 << "个死者的位置：" << circularLinkedList.at(currentIndex).first << std::endl;
	}
	
	// Display the result
	std::cout << "最后剩下的人数：" << K << std::endl;
	std::cout << "剩余的生者位置：";
	for (int i = 0; i < N; i++) {
		if (circularLinkedList.at(i).second) {
			std::cout << circularLinkedList.at(i).first << "  ";
		}
	}
	std::cout << std::endl;

	return 0;
}

void check(int N, int S, int M, int K) {
	/* Check if the combination of N, S, M and K is illegal */
	if (N <= 0 || S <= 0 || M <= 0 || K <= 0) {
		std::cout << "Illegal input!!!\a" << std::endl 
			<< "All the numbers should be positive integers!!!" << std::endl;
		exit(0);
	}
	else if (N < K) {
		std::cout << "Illegal input!!!\a" << std::endl 
			<< "N should be no less than K" << std::endl;
		exit(0);
	}
	else if (N < S) {
		std::cout << "Illegal input!!!\a" << std::endl
			<< "N should be no less than S" << std::endl;
		exit(0);
	}
}
