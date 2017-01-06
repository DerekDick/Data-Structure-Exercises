#ifndef _MAZE_H_
#define _MAZE_H_

#define MAXSIZE 100

typedef struct Point {
	int x = 0;
	int y = 0;
};

class Maze {
public:
	// Function members
	Maze(int row, int column);
	~Maze() = default;

	void inputMap(void);
	void displayMap(void);
	bool isWin(void);
	void searchRoute(void);

private:
	// Data members
	int _row;
	int _column;
	int _index = 0;                    //标记步数
	int _startX, _startY;               //起点
	int _endX, _endY;                   //终点
	bool _win = false;                 //标记是否找到出口
	bool _map[MAXSIZE][MAXSIZE];
	Point _route[MAXSIZE * MAXSIZE];   //路径

	// Function members
	void findStartPoint(void);
	void findEndPoint(void);
	void searchRoute(int x, int y);
	void printRoute();
	int getStartX(void);
	int getStartY(void);
};

#endif // _MAZE_H_
