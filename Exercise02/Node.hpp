#ifndef _LINKED_LIST_NODE_HPP_
#define _LINKED_LIST_NODE_HPP_

template <class T>
class Node {
public:
	// Function members
	Node() = default; // Default constructor
	~Node() = default; // Default destructor

	Node(T & data) {
		_data = data;
		_next = NULL;
	}

	T getData(void) {
		return _data;
	}

	void setData(T & data) {
		_data = data;
	}

	Node<T>* getNext(void) {
		return _next;
	}

	void setNext(Node<T>* next) {
		_next = next;
	}

private:
	// Data members
	T _data;
	Node<T>* _next;
};

#endif // _NODE_HPP_
