#include "PatternMatching.h"
#include <cstring>

void PatternMatching::setKey(const char *word) {
	strcpy(_word, word);
	_keyLength = strlen(_word);
}

void PatternMatching::setNext() {
	int j = 0, k = -1;
	int lengthP = _keyLength;
	_next[0] = -1;
	while (j < lengthP) {
		if (k == -1 || _word[j] == _word[k]) {
			j++, k++;
			_next[j] = k;
		}
		else k = _next[k];
	}
}

int PatternMatching::search(const char *str) {
	setNext();

	int time = 0;
	int posP = 0;
	int posT = 0;
	int lengthP = _keyLength;
	int lengthT = strlen(str);
	while (posT < lengthT) {
		if (posP == -1 || _word[posP] == str[posT]) {
			posP++;
			posT++;
			if (posP == lengthP) {
				time++;
				posP = _next[posP];
			}
		}
		else posP = _next[posP];
	}
	return time;
}
