#ifndef PROJECT_SKIPLIST_H
#define PROJECT_SKIPLIST_H

#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "entry.h"
using std::endl;

/**
 * @brief  A skip list implementation of a map, keys must be unique
 * @author Ethan Slattery
 * @date   12APR2016
 *******************************************************************************************/
template <typename K, typename V>
class skiplist {
    /*** forward declare nested classes and initiate typedefs***/
public:
    class   Iterator;
protected:
    class   node;
    typedef Entry<K,V> item;

public:
    /*** CONSTRUCTORS AND DESTRUCTORS***/
    // Basic skip list constructor
    skiplist();

    /***  UTILITY METHODS ***/
    /// Inserts an item into the list using key and value
    void insert(const K &k, const V &v) { insert(item(k, v)); }
    // Removes a key and associated values from the list
    void erase(const K &k);
    // Gets the value with the specified key
    V get(const K &k);


    /*** CONSTANT UTILITY FUNCTIONS ***/
    /// Returns the size of the list
    int size() const { return size_; }
    /// Returns the height of the list, or the number of levels in the skip list
    int height() const { return height_; }
    // Outputs the skiplist in the returned string (ASCII OUTPUT)
    std::string print() const;
    // Outputs the skiplist vertically in the returned string (ASCII OUTPUT)
    std::string printVert() const;

    /*** Iterator Methods ***/
    // TODO - Returns an Iterator to the first item in the list
    Iterator begin() { Iterator temp(head_); temp++; return temp; }
    // TODO - Returns an Iterator to the end() of the list
    Iterator end() { return Iterator(tail_); }

protected:
    /*** UTILITY METHODS ***/
    // inserts an entry into the list
    void insert(const item &e);
    /// Gets a random value between 0 and 1
    bool flipCoin() { return static_cast<bool>(rand()%2); }
    // Returns the column of the node
    int column(node* n) const;
    // Finds the location in the base list of the key of the largest key less
    node* search(const K &k) const;
    // Adds a new empty level above all the current levels in the list
    void addBlankLevel();

private:
    node* head_;   //< The head of the upper-most list level (-infinity)
    node* tail_;   //< The tail of the upper-most list level (infinity)
    int   height_; //< The Height of the structure
    int   size_;   //< The total number of nodes in the full list (bottom level)

public:
    /**
     * @brief Skip List Iterator
     * This class describes a skip list iterator for moving through the skip list
     *******************************************************************************************/
    class Iterator {
    public:
        /// Basic Iterator constructor to the given position, always points to bottom level
        Iterator(node* position) : pos_(position) { while(pos_->down() != nullptr){ pos_ = pos_->down(); } }

        /*** OPERATOR OVERLOADS ***/
        /// Returns a read only version of value at this location
        const V& operator*() const {return pos_->value(); }
        /// Returns a read/write version of the value at this location
        V& operator*() {return pos_->value(); }
        /// Returns TRUE if iterators point to the same position
        bool operator==(const Iterator& p) const { return pos_ == p.pos_; }
        /// Traverse the list in the forward direction
        Iterator& operator++(int) { pos_ = pos_->right(); return *this; }
        Iterator& operator++() { pos_ = pos_->right(); return *this; }
        /// Traverse the list in the reverse direction
        Iterator& operator--() { pos_ = pos_->left(); return *this; }

    private:
        node* pos_;  // Position of the iterator
    };// END OF ITERATOR CLASS****************************************************************

protected:
   /**
    * @brief A skip list node
    *******************************************************************************************/
    class node {
    public:
        /*** ENUM FOR NODE TYPE - USED FOR SEARCHING AND COMPARING ***/
        enum nodeType { REGULAR, HEAD, TAIL };

        /*** CONSTRUCTOR FOR THE NODE ***/
        /// Default constructor for the node sets all values to null
        node() : up_(nullptr), down_(nullptr), left_(nullptr), right_(nullptr), nodeType_(REGULAR) { }
        // Non default constructor
        node(node* up, node* down, node* left, node* right, nodeType Type = REGULAR);

        /*** SET METHODS - SETS THE POINTERS ***/
        /// Sets the node up from this node
        void setUp(node* up)       { up_ = up; }
        /// Sets the node down from this node
        void setDown(node* down)   { down_ = down; }
        /// Sets the node left from this node
        void setLeft(node* left)   { left_ = left; }
        /// Sets the node right from this node
        void setRight(node* right) { right_ = right; }

        /*** GET METHODS - GETS THE DIFFERENT POINTERS***/
        /// Gets the node up from this node
        node* up() const { return up_; }
        /// Gets the node down from this node
        node* down() const { return down_; }
        /// Gets the node left from this node
        node* left() const { return left_; }
        /// Gets the node right from this node
        node* right() const { return right_; }

        /*** UTILITY METHODS ***/
        /// Returns the type of node for comparison purposes
        nodeType type() const { return nodeType_; }
        /// returns the key of this node
        K key() const { return data_.key(); }
        /// Returns the value in this node
        V& value() {return data_.value(); }
        /// Returns TRUE if the data list for this node is empty
        bool empty() const { return data_.empty(); }
        /// sets the node status as a head node
        void setNodeType(const nodeType& n) { nodeType_ = n; }
        /// Adds an element to this node
        void add(const item &e) { data_ = e; }
        /// Adds an element to this node by values
        void add(const K &k, const V &v) { add(item(k,v)); }
        /// Clears the data from this node
        void clear() { data_.clear(); }

        /*** COMPARISON OPERATOR OVERLOADS ***/
        bool operator<(const node& that)  const;
        bool operator>(const node& that)  const;
        bool operator<=(const node& that) const;
        bool operator>=(const node& that) const;
        bool operator==(const node& that) const;
        bool operator!=(const node& that) const;

    private:
        item     data_;     //< List of Entries for this node, should have matching keys
        node*    up_;       //< Pointer to the node the next level up
        node*    down_;     //< Pointer to the node the next level down
        node*    left_;     //< Pointer to the last node in the current level
        node*    right_;    //< Pointer to the next node in the current level
        nodeType nodeType_; //< marks the node as a head, tail or normal
    }; // END OF NODE CLASS***********************************************************

}; // END OF SKIP-LIST CLASS**********************************************************

#endif //PROJECT_SKIPLIST_H

/*************************************************************************************
 *                        IMPLEMENTATION OF SKIP LIST METHODS
 *************************************************************************************/

/**
 * @breif The constructor for the skip-list, it makes the basic linkage
 */
template <typename K, typename V>
skiplist<K,V>::skiplist() : size_(0), height_(1)
{
  head_ = new node(nullptr, nullptr, nullptr, nullptr, node::HEAD);
  tail_ = new node(nullptr, nullptr, nullptr, nullptr, node::TAIL);
  head_->setRight(tail_);
  tail_->setLeft(head_);
  srand(std::time(NULL));
}

/**
 * @breif Finds the key in the list
 * This search will find the node in the base list with the largest key equal to or less
 * than the value of the key being searched for.
 * @param k [IN] The key to find
 */
template <typename K, typename V>
typename skiplist<K,V>::node *skiplist<K,V>::search(const K &k) const {
  node  tempNode;
  node* itr = head_;
  tempNode.add(item(k, "FINDER"));

  while(itr->down() != nullptr) {
    if (tempNode == *itr->right() ) {
      // Move right if equal
      itr = itr->right();
    }
    else if (tempNode < *itr->right() ) {
      // Move down if less than
      itr = itr->down();
    }
    else if (tempNode > *itr->right() ) {
      // Move right if greater than
      itr = itr->right();
    }
  }

  // If the bottom is encountered before we get to the desired position, the iterator
  // Needs to move along the bottom till it gets to the right position for RIGHT insert
  while(itr->right()->type() != node::TAIL && tempNode >= *itr->right()) {
    itr = itr->right();
  }
  return itr;
}

/**
 * @brief Removes the given key and associated value from the list
 * @param k [IN] The key to erase from the list
 */
template <typename K, typename V>
void skiplist<K,V>::erase(const K &k) {
  node* itr = search(k);

  // If the key of the found location matches the key we want to delete then do the dirty
  if(itr->key() == k) {
    while(itr != nullptr) {
      // If there is a node to the left, link it to the right
      if (itr->left() != nullptr) {
        itr->left()->setRight(itr->right());
      }
      // If there is a node to the right, link it to the left
      if (itr->right() != nullptr) {
        itr->right()->setLeft(itr->left());
      }
      // Move up in the stack
      node *tempItr = itr->up();
      delete itr;
      itr = tempItr;
    }// END OF WHILE LOOP
  }// END OF IF STATEMENT
  size_--;
}// END OF ERASE KEY METHOD

/**
 * @brief Adds an entry to the skip list
 * @param e [IN] the entry to add to the skip list
 */
template <typename K, typename V>
void skiplist<K,V>::insert(const item &e) {
  node* newNode = new node;
  node* location;
  newNode->add(e);
  location = search(e.key());

  // If the key already exists, add the new item to each node in the tower
  if(*location == *newNode){
    while(location != nullptr) {
      location->add(e);
      location = location->up();
    }
  }
  // If the key did not exist in the table add it and create a tower of random height
  else {
    // Insert the new node to the RIGHT of the position found
    // First link the new node to its neighbors
    newNode->setLeft(location);
    newNode->setRight(location->right());
    // Then the neighbors to the new node
    newNode->left()->setRight(newNode);
    newNode->right()->setLeft(newNode);

    node* leftScan = location;    // Pointer for scanning left to find a horizontal links
    int level = 1;                // Counter to keep track of the current level

    // Make a new column of a random height by flipping a "coin" repeatedly
    while(flipCoin()) {
      // If the top level is reached, make a new one!
      if(level >= height_) { addBlankLevel(); }

      // Scan left for a node with an up-pointer
      while(leftScan->up() == nullptr) {
        leftScan = leftScan->left();
      }
      // Move the scanner up one
      leftScan  = leftScan->up();

      // insert the new node above the previous level, with data
      newNode->setUp(new node(nullptr, newNode, leftScan, leftScan->right()));
      newNode->up()->add(e);
      // Connect the neightbors to the new node
      leftScan->right()->setLeft(newNode->up());
      leftScan->setRight(newNode->up());

      //Prepare for next iteration if there is one
      newNode = newNode->up();
      level++;

    }//END OF TOWER BUILDING WHILE LOOP
    //increment the size of the skpi list
    size_++;
  }//END OF NEW NODE INSERT
}//END OF INSERT METHOD

/**
 * @brief Returns an iterator to the beginning of the vector of Entry objects
 * @param k [IN] The key of the item to get
 */
template <typename K, typename V>
V skiplist<K,V>::get(const K &k) {
  node* item = search(k);
  return item->value();
}

/**
 * @brief Adds a new empty level above all the current levels in the list
 */
template <typename K, typename V>
void skiplist<K,V>::addBlankLevel() {
  node* newHead = new node(nullptr, head_, nullptr, nullptr, node::HEAD);
  node* newTail = new node(nullptr, tail_, newHead, nullptr, node::TAIL);
  newHead->setRight(newTail);
  head_->setUp(newHead);
  tail_->setUp(newTail);
  head_ = newHead;
  tail_ = newTail;
  height_++;
}

/**
 * @brief generates ASCII output of the list and returns it through the string
 * @returns string containing horizontal ASCII representation of the skip list
 */
template <typename K, typename V>
std::string skiplist<K,V>::print() const {
  node *tempPtr;
  std::ostringstream out;

  // outputs each row
  for (int currentRow = 0; currentRow < height_; currentRow++) {
    // sets the tempPtr to the proper row
    tempPtr = head_;
    for (int k = 0; k < currentRow; k++)
      tempPtr = tempPtr->down();

    // outputs each element of the row
    for (int i = 0; i < size_ + 2; ++i) {
      if (column(tempPtr) == i) {
        if(tempPtr->type() == node::REGULAR)
          out << '[' << std::setw(3) << tempPtr->key() << "]";
        else if(tempPtr->type() == node::HEAD)
          out << '[' << std::setw(3) << "-inf" << "]";
        else if(tempPtr->type() == node::TAIL)
          out << '[' << std::setw(3) << "+inf" << "]";

        if (tempPtr->right() != NULL)
          tempPtr = tempPtr->right();
      }
      else {
        out << "-----";
      }
    }
    out << std::endl;
  }
  return out.str();
}

/**
 * @returns the column of the node
 * @param n [IN] the node to find the column of
 */
template <typename K, typename V>
int skiplist<K,V>::column(node* n) const
{
  int   counter = 0;
  node *tempPtr = n;

  // travels down the list
  while(tempPtr->down() != NULL)
  {
    tempPtr = tempPtr->down();
  }

  // counts the number of nodes to the left
  while(tempPtr->left() != NULL)
  {
    counter++;
    tempPtr = tempPtr->left();
  }
  return counter;
}

/**
 * @brief generates ASCII output of the list and returns it through the string
 * @returns string containing vertical ASCII representation of the skip list
 */
template <typename K, typename V>
std::string skiplist<K,V>::printVert() const {
  std::ostringstream out;
  int val_width  = 4;
  int size_width = 1;

  // get bottom left head pointer
  node* itr = head_;
  while(itr->down() != nullptr) {
    itr = itr->down();
  }

  // Print each column as a row
  while(itr != nullptr) {
    node* p = itr;
    int height = 1;
    // Prints the current column
    while(p != nullptr) {
      if(p->type() == node::HEAD) {
        out << std::setw(val_width+size_width) << "   -   ";
      }
      else if(p->type() == node::TAIL) {
        out << std::setw(val_width+size_width) << "   +   ";
      }
      else {
        out << std::setw(val_width) << p->key()
            << "[" << std::setw(size_width) << "]";
      }
      p = p->up();
      height++;
    }

    while(height <= height_) {
      out << std::setw(val_width+size_width) << "   |   ";
      height++;
    }
    out << endl;
    itr = itr->right();
  }

  return out.str();
}

/*************************************************************************************
 *                     IMPLEMENTATION OF NODE CLASS METHODS
 *************************************************************************************/


/**
 * @brief The non-default constructor of the node class, where you can set the links
 */
template <typename K, typename V>
skiplist<K,V>::node::node(node *up, node *down, node *left, node *right, nodeType Type)
{
  up_       = up;
  down_     = down;
  left_     = left;
  right_    = right;
  nodeType_ = Type;
}

/**
 * @brief overloads the < operator
 */
template <typename K, typename V>
bool skiplist<K,V>::node::operator<(const node& that) const
{
  if(this->nodeType_ == HEAD || that.nodeType_ == TAIL) {
    return true;
  }
  else if(this->nodeType_ == TAIL || that.nodeType_ == HEAD) {
    return false;
  }
  else{
    return this->data_ < that.data_;
  }
}

/**
 * @brief overloads the > operator
 */
template <typename K, typename V>
bool skiplist<K,V>::node::operator>(const node& that) const
{
  if(this->nodeType_ == HEAD || that.nodeType_ == TAIL) {
    return false;
  }
  else if(this->nodeType_ == TAIL || that.nodeType_ == HEAD) {
    return true;
  }
  else{
    return this->data_ > that.data_;
  }
}

/**
 * @breif overloads the <= operator
 */
template <typename K, typename V>
bool skiplist<K,V>::node::operator<=(const node& that) const
{
  if(this->nodeType_ == HEAD) { return true; }
  else if(this->nodeType_ == TAIL) { return false; }
  else{ return this->data_ <= that.data_; }
}

/**
 * @breif overloads the >= operator
 */
template <typename K, typename V>
bool skiplist<K,V>::node::operator>=(const node& that) const
{
  if(this->nodeType_ == HEAD) { return false; }
  else if(this->nodeType_ == TAIL) { return true; }
  else{ return this->data_ >= that.data_; }
}

/**
 * @breif overloads the == operator
 */
template <typename K, typename V>
bool skiplist<K,V>::node::operator==(const node &that) const {
  if(this->nodeType_ == that.nodeType_) {
    if(this->nodeType_ == REGULAR && !this->empty() && !that.empty()){
      return this->data_ == that.data_;
    }
    else {
      return true;
    }
  }
  return false;
}

/**
 * @breif overloads the != operator
 */
template <typename K, typename V>
bool skiplist<K,V>::node::operator!=(const node &that) const {
  return !(*this == that);
}
