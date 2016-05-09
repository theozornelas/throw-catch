#ifndef COMPLETEBINARYTREE
#define COMPLETEBINARYTREE


#include <vector>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

template <typename E>
class CompleteBinaryTree
{
public:
    /****************************
     * CONSTRUCTOR & DESTRUCTOR *
     ****************************/
    CompleteBinaryTree();
    ~CompleteBinaryTree();

    /************
     * MUTATORS *
     ************/

    /*************
     * ACCESSORS *
     *************/
    //These are used to get the index of the connected nodes
    int Parent(int childIndex) const;
    int LChild(int parentIndex) const;
    int RChild(int parentIndex) const;

    E   GetTop() const;
    int GetHeight() const;   //Gets the depth of the entire tree
    int GetSize() const;     //Gets the number of nodes in the ree
    int GetCapacity() const; //Gets the capacity of the vector
    bool IsEmpty() const;    //Returns true if the tree is empty
    bool IsComplete() const; //Returns true if the tree is complete
    bool IsPerfect() const;  //Returns true if the tree is perfect

    //These are used to traverse the tree
    string InorderTraversal() const; //Returns the inorder traversal of the tree

    /**************
     * EXCEPTIONS *
     **************/
    friend std::ostream& operator<< (ostream &out,
                                     const CompleteBinaryTree<E> &tree)
    {
        out << tree;

        return out;
    }

protected:
    /**************
     * ATTRIBUTES *
     **************/
    vector<E> tree; //The binary tree
    int root;       //Root starts at 0
    int end;        //The index right after the last node (starts at 0)

private:
    /*************
     * RECURSIVE *
     *************/
    string Inorder(int node) const; //Returns the inorder traversal of the node

    /*************
     * UTILITIES *
     *************/
    int MaxNum(int num1,        //Returns the maximum of the two numbers
               int num2) const;

};/*************************  IMPLEMENTATION  *********************************/

                    /****************************
                     * CONSTRUCTOR & DESTRUCTOR *
                     ****************************/
/*------------------------------------------------------------------------------
  Default constructor
------------------------------------------------------------------------------*/
template <typename E>
CompleteBinaryTree<E>::CompleteBinaryTree()
{
//	tree.resize(100);
    root = 0;
    end  = 0;
}

/*------------------------------------------------------------------------------
  Destructor
------------------------------------------------------------------------------*/
template <typename E>
CompleteBinaryTree<E>::~CompleteBinaryTree()
{
}

                            /************
                             * MUTATORS *
                             ************/

                            /*************
                             * ACCESSORS *
                             *************/
/*------------------------------------------------------------------------------
  int Parent(int i) const;

  POST: Returns the index of the location that the parent of childIndex should
        be at
------------------------------------------------------------------------------*/
template <typename E>
int CompleteBinaryTree<E>::Parent(int childIndex) const
{
    return (childIndex - 1) / 2;
}

/*------------------------------------------------------------------------------
  int LChild(int i) const;

  POST: Returns the index of the location that the left child of parentIndex
        should be at
------------------------------------------------------------------------------*/
template <typename E>
int CompleteBinaryTree<E>::LChild(int parentIndex) const
{
    return (2 * parentIndex) + 1;
}

/*------------------------------------------------------------------------------
  int RChild(int i) const;

  POST: Returns the index of the location that the left child of parentIndex
        should be at
------------------------------------------------------------------------------*/
template <typename E>
int CompleteBinaryTree<E>::RChild(int parentIndex) const
{
    return (2 * parentIndex) + 2;
}

/*------------------------------------------------------------------------------
  E GetTop() const;

  POST: Returns the top of the tree
------------------------------------------------------------------------------*/
template <typename E>
E CompleteBinaryTree<E>::GetTop() const
{
    return tree[root];
}

/*------------------------------------------------------------------------------
  int GetHeight() const;

  POST: Returns the height of the tree (0 if there is 0/1 node)
------------------------------------------------------------------------------*/
template <typename E>
int CompleteBinaryTree<E>::GetHeight() const
{
    return static_cast<int>(log2(GetSize()));
}

/*------------------------------------------------------------------------------
  int GetSize() const;

  POST: Returns the number of nodes in the tree
------------------------------------------------------------------------------*/
template <typename E>
int CompleteBinaryTree<E>::GetSize() const
{
    return end;
}

/*------------------------------------------------------------------------------
  int GetCapacity() const;

  POST: Returns the capacity of the vector
------------------------------------------------------------------------------*/
template <typename E>
int CompleteBinaryTree<E>::GetCapacity() const
{
    return tree.capacity();
}

/*------------------------------------------------------------------------------
  bool IsEmpty() const;

  POST: Returns true if the tree is empty
------------------------------------------------------------------------------*/
template <typename E>
bool CompleteBinaryTree<E>::IsEmpty() const
{
    return end == 0;
}

/*------------------------------------------------------------------------------
  bool IsComplete() const;

  POST: Returns true if the tree is complete
------------------------------------------------------------------------------*/
template <typename E>
bool CompleteBinaryTree<E>::IsComplete() const
{
    return true;
//    return end == 0;
}

//Perfect tree has 2^(n+1) - 1 nodes, n is the height

/*------------------------------------------------------------------------------
  bool IsPerfect() const;

  Perfect tree has 2^(n+1) - 1 nodes, n is the height

  POST: Returns true if the tree is a perfect tree
------------------------------------------------------------------------------*/
template <typename E>
bool CompleteBinaryTree<E>::IsPerfect() const
{
    int n = GetHeight();
    return GetSize() == (pow(2, (n + 1)) - 1 );
}

/*------------------------------------------------------------------------------
  string InorderTraversal() const;

  POST: Returns a string with the inorder traversal of the entire tree
------------------------------------------------------------------------------*/
template <typename E>
string CompleteBinaryTree<E>::InorderTraversal() const
{
    return Inorder(root);
}
                            /*************
                             * RECURSIVE *
                             *************/
/*------------------------------------------------------------------------------
  string Inorder(int i) const;

  POST: Returns a string with the inorder traversal of the node passed in
------------------------------------------------------------------------------*/
template <typename E>
string CompleteBinaryTree<E>::Inorder(int node) const
{
    ostringstream traversal;

    if (node >= root && node < end)
    {
        traversal << Inorder(LChild(node));
        traversal << tree[node] << ' ';
        traversal << Inorder(RChild(node));
    }

    return traversal.str();
}

                            /*************
                             * UTILITIES *
                             *************/
/*------------------------------------------------------------------------------
  int MaxNum(int num1,
             int num2) const;

  POST: Returns the largest of the two numbers
------------------------------------------------------------------------------*/
//Returns the max of the two numbers
template <typename E>
int CompleteBinaryTree<E>::MaxNum(int num1,
                                  int num2) const
{
    return num1 >= num2 ? num1 : num2;
}


#endif // COMPLETEBINARYTREE

