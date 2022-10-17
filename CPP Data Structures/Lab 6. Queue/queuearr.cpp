#include "queuearr.h"
#include <iostream>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber)
{
    maxSize = maxNumber;
    front = -1;
    rear = -1;
    dataItems = new DT[maxSize];
}

template < class DT >
Queue<DT>::~Queue()
{
    delete dataItems;
}

template < class DT >
void Queue<DT>::enqueue(const DT& newDataItem)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
    }

    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            dataItems[rear] = newDataItem;
        }

        else
        {
            rear = (rear + 1) % 8;
            dataItems[rear] = newDataItem;
        }
    }
}

template < class DT >
DT Queue<DT>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }

    else
    {
        DT temp = dataItems[front];

        front = (front + 1) % 8;

        return temp;
    }
}

template < class DT >
void Queue<DT>::clear()
{
    front = -1;
    rear = -1;
}

template < class DT >
bool Queue<DT>::isEmpty() const
{
    if (rear == front)
        return true;

    else
        return false;
}

template < class DT >
bool Queue<DT>::isFull() const
{
    if ((rear + 1) % 8 == front)
        return true;
    else
        return false;
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
template < class dt >
void Queue<dt>::putFront(const dt& newDataItem)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
    }

    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            dataItems[rear] = newDataItem;
        }

        else
        {
            front = (front + 7) % 8;
            dataItems[front] = newDataItem;
        }
    }
}

template < class DT >
DT Queue<DT>::getRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }

    else
    {
        DT temp = dataItems[rear];

        rear = (rear + 7) % 8;

        return temp;
    }
}

//template < class DT >
//int Queue<DT>::getLength() const
//{
//    // In-lab 3
//
//}