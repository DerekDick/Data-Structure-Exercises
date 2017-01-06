#ifndef _CIRCULAR_LINKED_LIST_HPP_
#define _CIRCULAR_LINKED_LIST_HPP_

#include "Node.hpp"

template <class T>
class CircularLinkedList {
public:
	// Function members
	CircularLinkedList() {
		/*
		The constructor
		Initialize _head and _tail
		*/

		_head = NULL;
		_tail = NULL;
	}

	~CircularLinkedList() {
		/*
		The destrustor
		Release the memory allocated for every node
		*/

		if (_head) {
			Node<T>* current = _head;
			Node<T>* temp = NULL;
			do {
				temp = current;
				current = current->getNext();
				delete temp;
			} while (current != _head);
		}
	}

	T at(int index) {
		/* Get the data of the node at the certain index of the linked list */
		Node<T>* current = _head;
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
		return current->getData();
	}

	void push_back(T & data) {
		if (!_head) {
			Node<T>* newNode = new Node<T>(data);
			newNode->setNext(newNode);
			_head = _tail = newNode;
		}
		else {
			Node<T>* newNode = new Node<T>(data);
			_tail->setNext(newNode);
			newNode->setNext(_head);
			_tail = newNode;
		}
	}

	Node<T>& operator[] (int index) {
		return getNodeAt(index);
	}

private:
	// Data members
	Node<T>* _head;
	Node<T>* _tail;

	// Function members
	Node<T>& getNodeAt(int index) {
		Node<T>* current = _head;
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
		return *current;
	}
};

#endif // _CIRCULAR_LINKED_LIST_HPP_
