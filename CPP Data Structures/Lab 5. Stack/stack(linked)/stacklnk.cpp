//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stacklnk.h"

//--------------------------------------------------------------------

template <class DT>
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr)
{

}


//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int ignored)
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

// Linked list implementation. Outputs the data items in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    StackNode<DT>* p;   // Iterates through the stack

    if (top == 0)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top ";
        for (p = top; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "bottom" << endl;
    }
}