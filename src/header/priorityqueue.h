#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include <queue>
#include <iterator>
#include <vector>


//template <class T>
//struct LessThanByAge
//{
//  bool operator()(const Vertex<T>& first, const Vertex<T>& second) const
//  {
//    return first.getValue() < second.getValue();
//  }
//};

template <class T, class FU>
class PriorityQueue
{
public:

    PriorityQueue();

    ~PriorityQueue();

    void insert(T element);

    T min();

    T removeMin();

    int size();

    bool empty();



private:

    FU comparator;
    std::priority_queue<T,std::vector<T>, FU> myQueue;
};

template <class T,class FU>
PriorityQueue<T,FU> :: PriorityQueue()
{

}

template <class T,class FU>
PriorityQueue<T,FU> :: ~PriorityQueue()
{

}

template <class T,class FU>
void PriorityQueue<T,FU> :: insert(T element)
{
    myQueue.push(element);
}

template <class T,class FU>
T PriorityQueue<T,FU> :: min()
{

    T minVal = myQueue.top();

    return minVal;
}

template <class T,class FU>
T PriorityQueue<T,FU> :: removeMin()
{

    T temp = myQueue.top();
    myQueue.pop();

    return temp;
}

template <class T,class FU>
int PriorityQueue<T,FU> :: size()
{
    return myQueue.size();
}

template <class T,class FU>
bool PriorityQueue<T,FU> ::  empty()
{
    return myQueue.empty();
}



#endif // PRIORITYQUEUE_H

