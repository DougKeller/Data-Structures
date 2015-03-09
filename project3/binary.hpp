// Douglas Keller
// Data Structures
// Programming Assignment 3

#ifndef BINARY_HPP
#define BINARY_HPP

#include <iostream>

template <class T>
class BinarySearchTree {
public:
  T& search(T const&) const;
  void delete(T const&);
  void insert(T);
  
private:

};

template <class T>
std::ostream& operator<<(std::ostream& os, BinarySearchTree<T>& bst) {
  return bst.print(os);
}
