// Douglas Keller
// dwk24@zips.uakron.edu
// Data Structures
// Programming Assignment 3
// 31 March 2015

#include "bst.h"
#include <iostream>
#include <cmath>

// Insert functions
//

void BST::insert(int value) {
	insert(value, root, nullptr);
	print();
}

void BST::insert(int value, Node*& curn, Node* p) {
	if(!curn) {
		curn = new Node();
		curn->val = value;
		curn->parent = p;
	} else if(value < curn->val)
		insert(value, curn->left, curn);
	else
		insert(value, curn->right, curn);
}

// Remove functions
//

void BST::remove(int value) {
	remove(value, root);
	print();
}

void BST::remove(int value, Node*& n) {
	if(!n)
		return;

	if(value < n->val)
		remove(value, n->left);
	else if(value > n->val)
		remove(value, n->right);
	else if (value == n->val) {
		if(n->left && n->right) {
			Node* pre = n->left; // Finds in-order predeccessor
			while(pre->right)
				pre = pre->right;

			n->val = pre->val;
			remove(pre->val, pre->parent->right); // Reaccessing the node through the parent gets the correct reference pointer to remove.
		} else if(n->left) { 
			// Only a left child
			replaceNode(n, n->left);
		} else if(n->right) {
			// Only a right child
			replaceNode(n, n->right);
		} else { 
			// No children
			replaceNode(n, nullptr);
		}
	}
}

// Replace node function
//

// This function replaces the current node with a new value.
void BST::replaceNode(Node* n, Node* newVal) {
	if(newVal)
		newVal->parent = n->parent;
	if(n->parent) { // If the node has a parent...
		if(n->val == n->parent->left->val) {
			// If this node is its parent's left child
			n->parent->left = newVal; // Replace the node with the new value
		} else {
			// If this node is its parent's right child
			n->parent->right = newVal; // Replace the node with the new value
		}
	} else {
		// This is the root node
		root = newVal;
	}

	delete n;
}

// Print functions
//

void BST::print() {
	std::cout << "[ ";
	print(root);
	std::cout << "]";
}

void BST::print(Node* n) {
	if(!n)
		return;

	print(n->left);
	std::cout << n->val << ' ';
	print(n->right);
}

void BST::printReverse() {
	std::cout << "[ ";
	printReverse(root);
	std::cout << "]";
}

void BST::printReverse(Node* n) {
	if(!n)
		return;

	printReverse(n->right);
	std::cout << n->val << ' ';
	printReverse(n->left);
}

void BST::printPre() {
	std::cout << "[ ";
	printPre(root);
	std::cout << "]";
}

void BST::printPre(Node* n) {
	if(!n)
		return;
	
	std::cout << n->val << ' ';
	printPre(n->left);
	printPre(n->right);
}

void BST::printPost() {
	std::cout << "[ ";
	printPost(root);
	std::cout << "]";
}

void BST::printPost(Node* n) {
	if(!n)
		return;

	printPost(n->left);
	printPost(n->right);
	std::cout << n->val << ' ';
}

// Height functions
//

int BST::height() {
	return height(root);
}

int BST::height(Node* n) {
	if(!n)
		return -1;
	return 1 + std::max(height(n->left), height(n->right));
}

// Depth functions
//

int BST::depthOf(int val) {
	if(!contains(val))
		return -1;
	return depthOf(val, root);
}

int BST::depthOf(int val, Node* n) { // Since this method can only be called if a tree contains a value, there's no way to
									  // encounter null nodes. That is why they are not checked for.
	if(val == n->val)
		return 0;
	if(val < n->val)
		return 1 + depthOf(val, n->left);
	return 1 + depthOf(val, n->right);
}

// Cost functions
//

int BST::highestCost() {
	return highestCost(root);
}

int BST::highestCost(Node* n) {
	if(!n)
		return 0;
	return n->val + std::max( highestCost(n->left), highestCost(n->right) );
}

// Search functions
//

bool BST::contains(int val) {
	return contains(val, root);
}

bool BST::contains(int val, Node* n) {
	if(!n)
		return false;
	if(n->val == val)
		return true;
	return contains(val, n->left) || contains(val, n->right);
}

// Balanced functions
//

bool BST::balanced() {
	return balanced(root);
}

bool BST::balanced(Node* n) {
	if(!n)
		return true;

	int dL = height(n->left);	// Depth values are assigned to integers so that the program
	int dR = height(n->right);	// doesn't have to continuously call the depth function for each tree.

	return balanced(n->left) && balanced(n->right)
		&& std::max(dL, dR) - std::min(dL, dR) < 2;
}