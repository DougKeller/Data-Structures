// Douglas Keller
// dwk24@zips.uakron.edu
// Data Structures
// Programming Assignment 3
// 31 March 2015

#ifndef BST_H
#define BST_H

class BST {
public:
	BST() : root(nullptr) { }

	void insert(int);
	void remove(int);
	void print();
	void printReverse();
	void printPre();
	void printPost();
	int height();
	int depthOf(int);
	int highestCost();
	bool contains(int);
	bool balanced();
private:
	struct Node {
		int val;
		Node* left;
		Node* right;
		Node* parent;
	};

	void insert(int, Node*&, Node*);
	void remove(int, Node*&);
	void print(Node*);
	void printReverse(Node*);
	void printPre(Node*);
	void printPost(Node*);
	int height(Node*);
	int depthOf(int, Node*);
	int highestCost(Node*);
	bool contains(int, Node*);
	bool balanced(Node*);

	void replaceNode(Node*, Node*);

	Node* root;
};

#endif // BST_H