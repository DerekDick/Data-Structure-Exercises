#include <iostream>
#include "BinarySearchTree.hpp"

void printMenu(void);
void create(BinarySearchTree<double> * bst);
void insert(BinarySearchTree<double> * bst);
void search(BinarySearchTree<double> * bst);

int main(int argc, char* argv[]) {
	// Display the welcoming information
	// Display the welcoming information
	std::cout << "**********************************" << std::endl;
	std::cout << "*          Exercise 09           *" << std::endl;
	std::cout << "*       Binary Search Tree       *" << std::endl;
	std::cout << "*         1552719 侯剑锋         *" << std::endl;

	// Create a binary search tree
	BinarySearchTree<double> bst;
	BinarySearchTree<double> * binarySearchTree = &bst;

	// Start the dialog which receives the options of the user and process them in loops
	printMenu();
	char option = '\0';
	while (std::cin >> option) {
		switch (option) {
		case '1':
			create(binarySearchTree);
			binarySearchTree->printTree();

			break;

		case '2':
			insert(binarySearchTree);
			binarySearchTree->printTree();

			break;

		case '3':
			search(binarySearchTree);

			break;

		case '4':
			// Release the allocated memory
			binarySearchTree->makeEmpty();

			std::cout << "Exiting... 即将退出程序..." << std::endl;
			exit(0);

		// Exceptions
		default:
			std::cout << "Illegal input!!!\a" << std::endl;

			break;
		}

		// Print the welcoming information for the next loop
		printMenu();
	}

	delete binarySearchTree;

	return 0;
}

void printMenu(void) {
	// Print the menu
	std::cout << "**********************************" << std::endl;
	std::cout << "*     二叉搜索树（二叉排序树）   *" << std::endl;
	std::cout << "*         1.重新创建二叉树       *" << std::endl;
	std::cout << "*         2.插入元素             *" << std::endl;
	std::cout << "*         3.搜索元素             *" << std::endl;
	std::cout << "*         4.退出程序             *" << std::endl;
	std::cout << "**********************************" << std::endl;

	return;
}

void create(BinarySearchTree<double> * bst) {
	bst->makeEmpty();

	int number = 0;
	std::cout << "请输入您即将输入的数字的数量：" << std::endl;
	std::cin >> number;
	std::cout << "Please input some numbers to create the binary search tree:" << std::endl;
	double current = 0.0;
	for (int i = 0; i < number; i++) {
		std::cin >> current;
		bst->insert(current);
	}

	std::cout << "Binary search tree successfully created!" << std::endl;
	bst->printTree();

	return;
}

void insert(BinarySearchTree<double> * bst) {
	std::cout << "Please input the number you want to insert:" << std::endl;
	double current = 0.0;
	std::cin >> current;
	if (bst->insert(current)) {
		std::cout << "The number " << current << " was successfully inserted!" << std::endl;
	}
	else {
		std::cout << "The number " << current << " already exists in the binary search tree!" << std::endl;
	}

	bst->printTree();

	return;
}

void search(BinarySearchTree<double> * bst) {
	std::cout << "Please input the nubmer you want to search for:" << std::endl;
	double current = 0.0;
	std::cin >> current;
	//BinarySearchTreeNode<double, double> * p = NULL;
	if (bst->search(current)) {
		std::cout << "The number " << current << " found in the binary search tree!" << std::endl;
	}
	else {
		std::cout << "The number " << current << " not found in the binary search tree!" << std::endl;
	}

	bst->printTree();

	return;
}
