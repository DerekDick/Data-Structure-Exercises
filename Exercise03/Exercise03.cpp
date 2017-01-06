#include <iostream>
#include "Maze.h"

int main(int argc, char* argv[]) {
	// Display the welcoming information
	std::cout << "***********************************" << std::endl;
	std::cout << "*           Exercise 03           *" << std::endl;
	std::cout << "*        迷宫问题 The Maze        *" << std::endl;
	std::cout << "*          1552719 侯剑锋         *" << std::endl;
	std::cout << "***********************************" << std::endl;

	// Input the map of the maze
	int row, col;
	std::cout << "请输入迷宫的行数和列数:";
	std::cin >> row >> col;
	std::cout << std::endl << "请输入迷宫地图：" << std::endl;
	Maze maze = Maze(row, col);
	maze.inputMap();

	// Display the map of the maze
	std::cout << "迷宫地图:" << std::endl;
	maze.displayMap();

	// Search all the available routes
	maze.searchRoute();
	if (!maze.isWin()) {
		std::cout << "没有任何可选路径！！！" << std::endl;
	}

	return 0;
}
