// Douglas Keller
// Data Structures
// Programming Assignment 3

#ifndef BINARY_HPP
#define BINARY_HPP

#include <iostream>

template <class T>
class BinarySearchTree {
public:
  bool search(T const&) const;
  T delete(T const&);
  void insert(T);
  int depth() const;
  
  
  std::ostream& print(std::ostream&);
  
private:
  template <class T>
  struct Node {
    T val;
    Node* left;
    Node* right;
  };
  
  Node* head;
  
  bool search(Node*, T const&);
  T delete(Node*, T const&);
  void insert(Node*, T const&);
  int depth(Node*);
  
};

template <class T>
std::ostream& operator<<(std::ostream& os, BinarySearchTree<T>& bst) {
  return bst.print(os);
}

#endif // BINARY_HPP
