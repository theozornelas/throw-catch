/**
 * @file   CompleteTree.h
 * @brief  Assignment #7 - Heap Sort
 *
 * @author Ethan Slattery
 * @date   3-MAR-2016
 */
#ifndef PROJECT_COMPLETETREE_H
#define PROJECT_COMPLETETREE_H

#include <vector>   // Underlying container for the class

/**
 * @brief A Complete binary tree class
 * This class creates a complete binary tree, or a tree where every level has the
 * maximum number of nodes possible, and the nodes in the last level fill from
 * left to right.
 */
template <typename E>
class CompleteTree {
public:
  // Constructor: Initialized the vector to a size of one, since we do not use index 0
  CompleteTree() : V(1) {}

  // Typedef for a position in the tree
  typedef typename std::vector<E>::iterator Position;

  /*** CONSTANT UTILITY METHODS ***/
  // Returns TRUE if the tree is empty
  bool empty() const { return size() == 0; }
  // Returns the size of the tree
  int size() const { return V.size()-1; }
  // returns TRUE if the position has a LEFT child
  bool hasLeft(const Position& p) const { return 2*idx(p) <= size(); }
  // returns TRUE if the position has a RIGHT child
  bool hasRight(const Position& p) const { return 2*idx(p)+1 <= size(); }
  // returns TRUE if the position is ROOT
  bool isRoot(const Position& p) const { return idx(p) == 1; }

  /*** NON-CONSTANT UTILITY METHODS FOR THE TREE ***/
  // Returns the root of the tree
  Position root() { return pos(1); }
  // Returns the last element in the tree
  Position last() { return pos(size()); }
  // Add an element to the end of the tree and RETURN ITS POSITION
  Position addLast(const E& e) { V.push_back(e); return last(); }
  // Remove an element from the end of the tree
  void removeLast() { V.pop_back(); }
  // Swaps the contents of two positions in the tree
  void swap(const Position& p, const Position& q) { E e = *q; *q = *p; *p = e; }

  /*** NON-CONSTANT UTILITY METHODS FOR NODES ***/
  // Returns the left child of the position
  Position left(const Position& p) { return pos(2*idx(p)); }
  // Returns the right child of the position
  Position right(const Position& p) { return pos(2*idx(p) + 1); }
  // Returns the parent node of the current position
  Position parent(const Position& p) { return pos(idx(p)/2); }

protected:
  /*** UTILITY METHODS ***/
  // Maps an index in the vector to a position in the tree
  Position pos(int i) { return V.begin()+i; }
  // Maps a position in the tree to an index in the vector
  int idx(const Position& p) const { return p - V.begin(); }

private:
  std::vector<E> V;   //< The vector to hold the tree contents
};

#endif //PROJECT_COMPLETETREE_H
