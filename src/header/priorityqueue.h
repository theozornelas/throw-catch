#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include <queue>
#include <iterator>

template <class T>
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

    std::priority_queue<T> myQueue;
};

template <class T>
PriorityQueue<T> :: PriorityQueue()
{

}

template <class T>
PriorityQueue<T> :: ~PriorityQueue()
{

}

template <class T>
void PriorityQueue<T> :: insert(T element)
{
    myQueue.push(element);
}

template <class T>
T PriorityQueue<T> :: min()
{

    T minVal = myQueue.top();

    return minVal;
}

template <class T>
T PriorityQueue<T> :: removeMin()
{

    T temp = myQueue.top();
    myQueue.pop();

    return temp;
}

template <class T>
int PriorityQueue<T> :: size()
{
    return myQueue.size();
}

template <class T>
bool PriorityQueue<T> ::  empty()
{
    return myQueue.empty();
}



#endif // PRIORITYQUEUE_H

