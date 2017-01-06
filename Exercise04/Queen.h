#ifndef _QUEEN_H_
#define _QUEEN_H_

#define MAXSIZE 20

class Queen {
public:
	// Function members
	Queen(int N);
	~Queen() = default;
	void search(int r);
	void print();
	int getNum() {
		return _num;
	};

private:
	// Data members
	int _N;
	int _chessBoard[MAXSIZE];
	int _num = 0;
};

#endif // _QUEEN_H_
