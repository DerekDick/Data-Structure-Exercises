#include <iostream>
#include "Queen.h"

int main(int argc, char* argv[]) {
	// Display the welcoming information
	std::cout << "***********************************" << std::endl;
	std::cout << "*           Exercise 04           *" << std::endl;
	std::cout << "*            N 皇后问题           *" << std::endl;
	std::cout << "*          1552719 侯剑锋         *" << std::endl;
	std::cout << "***********************************" << std::endl;

	// Prompt the user to input the number of Queens
	int N = 0;
	std::cout << "现有N*N的棋盘， 放入N个皇后，要求所有皇后不在同一列、和同一斜线上。" << std::endl << std::endl;
	std::cout << "请输入皇后的个数N: (不要超过20)";
	std::cin >> N;

	// Search for all the available situations
	Queen queen = Queen(N);
	std::cout << std::endl << "皇后摆法：" << std::endl << std::endl;
	queen.search(0);

	// Print the number of situations available
	std::cout << "一共有 " << queen.getNum() << " 种摆法。" << std::endl;

	return 0;
}
