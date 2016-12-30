#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

// The definition of the node stored in the binary search tree
template <class T>
struct BinarySearchTreeNode {
	// Data members
	T data;
	BinarySearchTreeNode<T> * left;
	BinarySearchTreeNode<T> * right;

	// Function members
	BinarySearchTreeNode() : left(NULL), right(NULL) {}

	BinarySearchTreeNode(const T d, BinarySearchTreeNode<T> * L = NULL,
		BinarySearchTreeNode<T> * R = NULL) :
		data(d), left(L), right(R)
	{}

	void setData(T d) {
		this->data = d;
	}

	T getData(void) {
		return data;
	}
};

template <class T>
class BinarySearchTree {
public:
	// Function members
	BinarySearchTree() : root(NULL) {}

	~BinarySearchTree() {
		makeEmpty();
	}

	void makeEmpty() {
		makeEmpty(root);
	}
	
	bool search(const T x) const {
		return search(x, root) ? true : false;
	}

	void printTree(void) const {
		printTree(root);
		std::cout << std::endl;
	}

	T min(void) {
		return min(root)->data;
	}

	T max(void) {
		return max(root)->data;
	}

	bool insert(const T & el) {
		return insert(el, root);
	}

	bool remove(const T x) {
		return remove(x, root);
	}

	BinarySearchTreeNode<T> * search(const T x) {
		return search(x, root);
	}

private:
	void makeEmpty(BinarySearchTreeNode<T> * & binarySearchTreeNode) {
		if (binarySearchTreeNode) {
			makeEmpty(binarySearchTreeNode->left);
			makeEmpty(binarySearchTreeNode->right);
			delete binarySearchTreeNode;
		}

		binarySearchTreeNode = NULL;
	}

	// Data members
	BinarySearchTreeNode<T> * root;

	// Function members
	BinarySearchTreeNode<T> * search(const T x, BinarySearchTreeNode<T> * binarySearchTreeNode) {
		if (!binarySearchTreeNode) {
			return NULL;
		}
		else if (x < binarySearchTreeNode->data) {
			return search(x, binarySearchTreeNode->left);
		}
		else if (x > binarySearchTreeNode->data) {
			return search(x, binarySearchTreeNode->right);
		}
		else {
			return binarySearchTreeNode;
		}
	}

	bool insert(const T & el, BinarySearchTreeNode<T> * & binarySearchTreeNode) {
		if (!binarySearchTreeNode) {
			binarySearchTreeNode = new BinarySearchTreeNode<T>(el);
			if (!binarySearchTreeNode) {
				std::cout << "Out of space!!!\a" << std::endl;
				exit(1);
			}

			return true;
		}
		else if (el < binarySearchTreeNode->data) {
			insert(el, binarySearchTreeNode->left);
		}
		else if (el > binarySearchTreeNode->data) {
			insert(el, binarySearchTreeNode->right);
		}
		else {
			return false;
		}
	}

	void printTree(BinarySearchTreeNode<T> * binarySearchTreeNode) const {
		if (binarySearchTreeNode) {
			printTree(binarySearchTreeNode->left);
			std::cout << binarySearchTreeNode->data << ' ';
			printTree(binarySearchTreeNode->right);
		}
	}
};

#endif // _BINARY_SEARCH_TREE_HPP_
