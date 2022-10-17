#include "queuelnk.h"
#include <iostream>

using namespace std;

template <class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}

template <class DT>
Queue<DT>::Queue(int ignored)
{
    front = NULL;
    rear = NULL;
}

template<class DT>
Queue<DT>::~Queue()
{

}

template<class DT>
void Queue<DT>::enqueue(const DT& newDataItem)
{
    QueueNode<DT>* temp = new QueueNode<DT>(newDataItem, NULL);

    if (isFull())
    {
        cout << "Queue is full" << endl;
    }
    
    else
    {
        if (isEmpty())
        {
            front = temp;
            rear = temp;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

template<class DT>
DT Queue<DT>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }

    else
    {
        DT temp = front->dataItem;

        front = front->next;

        return temp;
    }
}

template <class DT>
void Queue<DT>::clear()
{
    while (front != NULL)
    {
        dequeue();
    }
}

template<class DT>
bool Queue<DT>::isEmpty() const
{
    if (front == NULL)
        return true;

    else
        return false;
}

template<class DT>
bool Queue<DT>::isFull() const
{
    QueueNode<DT>* check = new QueueNode<DT>(0, NULL);

    if ((check == NULL) && !isEmpty())
    {
        return true;
    }

    else
    {
        return false;
    }
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