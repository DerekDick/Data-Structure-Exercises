#include<iostream>
#include "Queen.h"

Queen::Queen(int N) {
	this->_N = N;
}

void Queen::print() {
	for (int i = 0; i < _N; ++i) {
		for (int j = 0; j< _N; ++j) {
			if (j == _chessBoard[i]) {
				std::cout << "★";
			}
			else {
				std::cout << "■";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Queen::search(int r) {
	if (r == _N) {
		print();
		_num++;
		return;
	}
	for (int i = 0; i< _N; i++) {
		_chessBoard[r] = i;
		int ok = 1;
		for (int j = 0; j < r; j++) {
			if (_chessBoard[r] == _chessBoard[j] ||
				r - j == _chessBoard[r] - _chessBoard[j] ||
				r - j == _chessBoard[j] - _chessBoard[r]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			search(r + 1);
		}
	}
}
