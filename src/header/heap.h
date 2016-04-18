#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iterator>
#include "team.h"

/**************************************************************************
 * This is the Heap Class. It implements a heap by using a vector of type
 * Team(class). The heap is used to sort a certain number of Items. The
 * Vector accommodates the data [x][R][L][R][LL][LR][RL][RR]....
 * The Heap will store the smallest number at the top.
 *************************************************************************/

template <class K, class V>
class Heap
{
public:

    //constructor
    Heap();

    //destructor
    ~Heap();

    //size of the vector heap
    int Size();

    //if the vector is empty
    bool IsEmpty();


    //inserts in to the heap. Bubbles up is necessary.
    void Insert(K key, V value);


    //returns the last element in the list
    Team<K,V> MinElement();


    //removes the last element in the heap
    void removeMin();

    //left child team
    Team<K,V> Left(int index);


    //reight child team
    Team<K,V> Right(int index);

    //index of the parent
    int ParentIndex(int index);


    //bubble up the element if is less than the parent(used in insert)
    void BubbleUp(int index);

    //bubble down the element if is less than the parent(used in delete)
    void BubbleDown(int index);


    //swaps the elements in the heap(used in bubble down and bubble up)
    void Swap(int a, int b);

    //index of the left child
    int LeftPosition(int index);

    //index of the right child
    int RightPosition(int index);


    //prints the heap
    string Print();

private:

    vector<Team<K,V>> myTree;  //container for the heap
    int size;//size/tail of the heap
    int root;//index of the root(always 1)

};

template <class K, class V>
Heap<class K, class V> :: Heap()
{
    size = 0;
    root = 1;
    Team<K,V> aTeam(0," ");
    myTree.push_back(aTeam);

}

//destroys the heap
template <class K, class V>
Heap<class K, class V> :: ~Heap()
{
    myTree.clear();
}

template <class K, class V>
int Heap<class K, class V> ::  Size()
{
    return myTree.size()-1;
}

//checks if the heap is empty
template <class K, class V>
bool Heap<class K, class V> ::  IsEmpty()
{
    return myTree.empty();
}

//this insertion uses the bubble up method to arrange the contents in the heap.
template <class K, class V>
void Heap<class K, class V> :: Insert(K key, V value)
{

    Team<K,V> newTeam(key,value);

    //insert in the heap
    myTree.push_back(newTeam);

    //increment the size
    size++;

    //arrange values by bubbling up
    BubbleUp(size);

}

template <class K, class V>
Team<K,V> Heap<class K, class V> :: MinElement()
{
    //return the root of the heap(smallest element)
    return myTree[root];
}

template <class K, class V>
void Heap<class K, class V> :: removeMin()
{
    //last is now the first
    myTree[root] = myTree.at(size);

    //pop the last
    myTree.pop_back();

    //decrease the size of the heap
    size--;
    if(size>0)
    {
        //rearange the heap
        BubbleDown(root);
    }

}

template <class K, class V>
Team<K,V> Heap<class K, class V> :: Left(int index)
{
    return myTree[index *2];
}

template <class K, class V>
Team<K,V> Heap<class K, class V> :: Right(int index)
{
    return myTree[(index *2) + 1];
}

//this method arranges the heap after an insertion. It searches the
//appropiate spot and and swaps in order to keep order.
template <class K, class V>
void Heap<class K, class V> :: BubbleUp(int index)
{
    //swap(index1 , index2/2)//depends if swapping from left or right
    if(index > 0)
    {
        //get the index of the parent
        int parentIndex = ParentIndex(index);

        //if the parent is bigger than the child at the index passed
        if(myTree[parentIndex].getKey() > myTree[index].getKey())
        {
            //swap them
            Swap(parentIndex,index);

            //repeat by recursevely calling the function at the parent
            BubbleUp(parentIndex);
        }
    }
}

//this method swaps the last with the root and pops it, then rearanges the
//heap in order to maintain its property.
template <class K, class V>
void Heap<class K, class V> :: BubbleDown(int index)
{
    int leftIndex;
    int rightIndex;
    int minIndex;

    //get index of left child
    leftIndex = LeftPosition(index);

    //get index of right child
    rightIndex = RightPosition(index);

    //if the index is bigger than the size
    if(rightIndex >= size)
    {
        //end the function
        if(leftIndex >= size)
        {
            return;
        }
        else
        {
            //the lowest index is the left index
            minIndex = leftIndex;
        }

    }else{

        //if the left is less than equal to the right
        if(myTree[leftIndex].getKey() <= myTree[rightIndex].getKey())
        {
            //lowest is the left
            minIndex = leftIndex;
        }
        else
        {
            //lowest is the right
            minIndex = rightIndex;
        }
    }

    //if the index is greater than the minimum index
    if(myTree[index].getKey() > myTree[minIndex].getKey())
    {
        //swap objects and use recursion for upper levels
        Swap(minIndex,index);
        BubbleDown(minIndex);
    }

}

//swaps a and b of spot
template <class K, class V>
void Heap<class K, class V> ::  Swap(int a, int b)
{
    Team<K,V> temp;

    temp = myTree[a];
    myTree[a] = myTree[b];
    myTree[b] = temp;


}
//returns the parent of that index
template <class K, class V>
int  Heap<class K, class V> :: ParentIndex(int index)
{
    return (index)/2;
}

template <class K, class V>
int  Heap<class K, class V> :: LeftPosition(int index)
{
    return index*2;
}

template <class K, class V>
int  Heap<class K, class V> :: RightPosition(int index)
{
    return (index*2) + 1;
}

//prints the heap
template <class K, class V>
string Heap<class K, class V> :: Print()
{
    vector<Team<K,V>>::iterator it;
    ostringstream out;
    int count = 1;


    for(it = myTree.begin()+1; it != myTree.end(); it++)
    {
        out <<left<< setw(5)<< it->getKey()  << setw(12) << it->getName()
            << " Index: " << "[" << count << "] "<< endl;
        count++;
    }

    return out.str();
}

#endif // HEAP_H

