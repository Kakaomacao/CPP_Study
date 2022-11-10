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
    dataItem = nodeData;
    next = nextPtr;
}


//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int ignored)
{
    top = NULL;
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
    StackNode<DT>* temp = new StackNode<DT>(newDataItem, top);

    if (isFull())
        cout << "Stack is full." << endl;

    top = temp;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    if (isEmpty())
    {
        delete top;
    }

    else
    {
        DT pop = top->dataItem;
        top = top->next;
        return pop;
    }
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    top = NULL;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    if (this->top == NULL)   
        return true;

    else
        return false;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    StackNode<DT>* check = new StackNode<DT>(0, top);

    if ((top == NULL) && !isEmpty())
    {
        return true;
    }

    else
    {
        return false;
    }
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