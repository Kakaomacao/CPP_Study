#include "queuelnk.h"
#include <iostream>

using namespace std;

template <class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr)
{

}

template <class DT>
Queue<DT>::Queue(int ignored)
{

}

template<class DT>
Queue<DT>::~Queue()
{

}

template<class DT>
void Queue<DT>::enqueue(const DT& newDataItem)
{

}

template<class DT>
DT Queue<DT>::dequeue()
{

}

template <class DT>
void Queue<DT>::clear()
{

}

template<class DT>
bool Queue<DT>::isEmpty() const
{

}

template<class DT>
bool Queue<DT>::isFull() const
{

}

template<class DT>
void Queue<DT>::showStructure() const
{
    QueueNode<DT>* p;   // Iterates through the queue

    if (front == nullptr)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front ";
        for (p = front; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "rear" << endl;
    }
}