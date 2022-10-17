#include "queuearr.h"
#include <iostream>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber)
{

}

template < class DT >
Queue<DT>::~Queue()
{

}

template < class DT >
void Queue<DT>::enqueue(const DT& newDataItem)
{

}

template < class DT >
DT Queue<DT>::dequeue()
{

}

template < class DT >
void Queue<DT>::clear()
{

}

template < class DT >
bool Queue<DT>::isEmpty() const
{

}

template < class DT >
bool Queue<DT>::isFull() const
{

}

template < class DT >
void Queue<DT>::showStructure() const
{
    int j;   // Loop counter

    if (front == -1)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front = " << front << "  rear = " << rear << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        if (rear >= front)
            for (j = 0; j < maxSize; j++)
                if ((j >= front) && (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for (j = 0; j < maxSize; j++)
                if ((j >= front) || (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        cout << endl;
    }

}

// In-lab operations
//template < class DT >
//void Queue<DT>::putFront(const DT& newDataItem)
//{
//    // In-lab 2
//
//}

//template < class DT >
//DT Queue<DT>::getRear()
//{
//    // In-lab 2
//
//}

//template < class DT >
//int Queue<DT>::getLength() const
//{
//    // In-lab 3
//
//}