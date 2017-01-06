#include "Maze.h"
#include <iostream>
#include <iomanip>
#include <string>

Maze::Maze(int row, int column) {
	/* The constructor */
	this->_row = row;
	this->_column = column;
}

void Maze::inputMap(void) {
	/* Input the map from std::in */
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _column; j++) {
			std::cin >> _map[i][j];
		}
	}
}

void Maze::displayMap(void) {
	/* Display the map */
	std::cout << "    ";
	for (int i = 0; i < this->_column; i++) {
		std::cout << std::left << std::setw(4) << (char)('0' + i) + std::string("列");
	}
	std::cout << std::endl;
	
	for (int i = 0; i < this->_row; i++) {
		std::cout << std::left << std::setw(4) << (char)('0' + i) + std::string("行");
		for (int j = 0; j < this->_column; j++) {
			std::cout << std::left << std::setw(4) << _map[i][j];
		}
		std::cout << std::endl;
	}
}

bool Maze::isWin() {
	return this->_win;
}

int Maze::getStartX() {
	return this->_startX;
}

int Maze::getStartY() {
	return this->_startY;
}

void Maze::printRoute(void) {
	if (!this->_win) {
		std::cout << "迷宫路径：" << std::endl;
	}
	int i = 0;
	for (i = 0; (_route[i].x != _endX) || (_route[i].y != _endY); i++) {
		if (i % 8 == 0) {
			std::cout << std::endl;
		}
		std::cout << "(" << _route[i].x << "," << _route[i].y << ")--->";
	}
	std::cout << "(" << _endX << "," << _endY << ")";
	std::cout << std::endl << std::endl;
}

void Maze::findStartPoint() {
	/* Find the start point of the map */

	// Search the first row
	for (int i = 0; i < _column; i++) {
		if (!_map[0][i]) {
			_startX = 0;
			_startY = i;
			return;
		}
	}

	// Search the first column
	for (int i = 0; i < _row; i++) {  // 在第一列查找
		if (!_map[i][0]) {
			_startX = i;
			_startY = 0;
			return;
		}
	}
}

void Maze::findEndPoint() {
	/* Find the end point of the map */

	// Search the last row
	for (int i = 0; i < _column; i++) {
		if (_map[_row - 1][i] == 0) {
			_endX = _row - 1;
			_endY = i;
			return;
		}
	}

	// Search the last column
	for (int i = 0; i < _row; i++) {
		if (_map[i][_column - 1] == 0) {
			_endX = i;
			_endY = _column - 1;
			return;
		}
	}
}

void Maze::searchRoute(int x, int y) {
	/* Search all the routes available in the map */

	_map[x][y] = 1;
	_route[_index].x = x;
	_route[_index].y = y;
	_index++;

	// If reach the end point
	if ((x == _endX) && (y == _endY)) {
		printRoute();
		_win = true;
	}

	// Up
	if (y < (_column - 1) && _map[x][y + 1] == 0) {
		searchRoute(x, y + 1);
	}
	// Right
	if (x < (_row - 1) && _map[x + 1][y] == 0) {
		searchRoute(x + 1, y);
	}
	// Down
	if (y > 0 && _map[x][y - 1] == 0) {
		searchRoute(x, y - 1);
	}
	// Left
	if (x > 0 && _map[x - 1][y] == 0) {
		searchRoute(x - 1, y);
	}

	// Back
	_map[x][y] = 0;
	_index--;

	return;
}

void Maze::searchRoute(void) {
	/* Search all the available routes in the map */

	// Find the start point and the end point
	findStartPoint();
	findEndPoint();
	
	// Search
	this->searchRoute(getStartX(), getStartY());
}
