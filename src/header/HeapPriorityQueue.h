/**
 * @file  HeapPriorityQueue.h
 * @brief Assignment #7 - Heap Sort
 *
 * @author Ethan 
 * @date   06-Mar-2016
 */
#ifndef PROJECT_HEAPPRIORITYQUEUE_H
#define PROJECT_HEAPPRIORITYQUEUE_H

#include "CompleteTree.h"

/**
 * @brief A heap based priority queue
 * This class implements a heap based priority queue, using a vector as the underlying
 * structure. The data to be stored and the comparator is templated.
 *   typename E - The data to store in the heap
 *   typename C - The comparator to use while sorting the queue
 *
 * @author Ethan Slattery
 * @date   12APR2016
 */
template <typename E, typename C>
class HeapPriorityQueue {
public:
  /*** CONSTANT UTILITY METHODS ***/
  // Returns the size of the queue
    /**
   * @brief size
   * @return
   */
  int size() const { return tree_.size(); }
  // Returns TRUE if the queue is empty
  /**
   * @brief empty
   * @return
   */
  bool empty() const { return tree_.size() == 0; }

  /*** NON-CONSTANT UTILITY METHODS ***/
  // Returns the min element in the queue
  /**
   * @brief top
   * @return
   */
  E& top() { return *(tree_.root());}
  // Inserts an element into the queue
  /**
   * @brief push
   * @param e
   */
  void push(const E &e);
  // Removes the minimum element from the queue
  /**
   * @brief pop
   */
  void pop();

private:
  CompleteTree<E> tree_;    //< The contents of the PQueue
  C isLess_;                //< Comparitor for the tree contents

  // Typedef the position in the tree for ease of use within the queue class
  typedef typename CompleteTree<E>::Position Position;
};

#endif //PROJECT_HEAPPRIORITYQUEUE_H

/**
 *  This method adds the element e to the heap.
 *  It then performs a bubble up to restore heap order.
 *  @param e [IN] The element to add
 */
template <typename E, typename C>
void HeapPriorityQueue<E,C>::push(const E &e) {
  Position v = tree_.addLast(e);

  while(!tree_.isRoot(v)) {
    // Add e to the heap and get position variable
    Position u = tree_.parent(v);

    // If v is in order then done!
    if(!isLess_(*v, *u)) break;

    // Else swap with the parent
    tree_.swap(v,u);
    v = u;
  } // END WHILE LOOP
} // END INSERT METHOD

/**
 *  This method removes the next element from the queue.
 *  It then restores heap order by bubbling down
 */

template <typename E, typename C>
void HeapPriorityQueue<E,C>::pop() {
  // If there is only one node left, remove it!
  if(size() == 1) {
    tree_.removeLast();
  }
  // If there is more than one node then swap last and root and bubble down
  else {
    // Swap the last element and the root, then remove the last element (the ex-root)
    Position u = tree_.root();
    tree_.swap(u, tree_.last());
    tree_.removeLast();

    // Bubble down
    while(tree_.hasLeft(u)){
      // grab the left child of u
      Position v = tree_.left(u);

      // if there is a right child and it is less than the left child, make it v
      if(tree_.hasRight(u) && isLess_(*(tree_.right(u)), *v)){
        v = tree_.right(u);
      }

      // if v (the lesser of any children) is less than u (our node) then swap them.
      if(isLess_(*v, *u)) {
        tree_.swap(u,v);
        u = v;
      }
      else break; //else... WE ARE DONE
    } // END OF BUBBLE DOWN WHILE LOOP
  } // END ELSE
} // END METHOD
