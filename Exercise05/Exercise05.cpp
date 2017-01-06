#include <iostream>
#include <fstream>
#include <string>
#include "PatternMatching.h"

int main(int argc, char* argv[]) {
	// Display the welcoming information
	std::cout << "***********************************" << std::endl;
	std::cout << "*           Exercise 05           *" << std::endl;
	std::cout << "*          关键字检索系统         *" << std::endl;
	std::cout << "*          1552719 侯剑锋         *" << std::endl;
	std::cout << "***********************************" << std::endl;

	// Create a file and store the user's input into it
	std::cout << "请输入文件名：";
	std::string filename;
	std::cin >> filename;
	std::cout << "请输入一段英文(以\'*\'结束)：" << std::endl;
	std::ofstream outFile(filename);
	char c = '\0';
	while (std::cin >> std::noskipws >> c) {
		// End of the input
		if (c == '*') {
			break;
		}

		outFile << c;
	}
	outFile.close();

	// Get the keyword
	PatternMatching kmp = PatternMatching();
	std::cout << "请输入要检索的关键字：";
	std::string keyword;
	std::cin >> std::skipws >> keyword;
	kmp.setKey(keyword.c_str());

	// Output the content in the file
	std::cout << "显示原文件\"" << filename << "\":" << std::endl;
	std::string content;
	std::ifstream inFile(filename);
	while (inFile >> std::noskipws >> c) {
		std::cout << c;
		content.push_back(c);
	}
	std::cout << std::endl;
	inFile.close();

	// Search for the keyword in the content of the file
	int times = kmp.search(content.c_str());

	// Output the times
	std::cout << "在原文件中共检索到" << times << "个关键字\"" << keyword << "\"." << std::endl;

	return 0;
}
