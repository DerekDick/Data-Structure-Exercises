#ifndef _PATTERN_MATCHING_H_
#define _PATTERN_MATCHING_H_

class PatternMatching {
public:
	// Function members
	PatternMatching() = default;
	~PatternMatching() = default;

	int search(const char *str);
	void setKey(const char *word);

private:
	// Data members
	char _word[20];
	int _next[20];
	int _keyLength;

	// Function members
	void setNext();
};

#endif // _PATTERN_MATCHING_H_
