//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber)
{

}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{

}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{

}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{

}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{

}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{

}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{

}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if (top == -1)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top = " << top << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j <= top; j++)
            cout << dataItems[j] << "\t";
        cout << endl;
    }
}