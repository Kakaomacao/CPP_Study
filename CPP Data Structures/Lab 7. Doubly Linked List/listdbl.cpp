#include "listdbl.h"

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
{

}

// Constructor
template < class DT >
List<DT>::List(int ignored)
{

}

// Destructor
template < class DT >
List<DT>::~List()
{

}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{

}

// Remove data item
template < class DT >
void List<DT>::remove()
{

}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement)
{

}

// Clear list
template < class DT >
void List<DT>::clear()
{

}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{

}

// List is full
template < class DT >
bool List<DT>::isFull() const
{

}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{

}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{

}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{

}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior()
{

}


template < class DT >
DT List<DT>::getCursor() const
{
	
}


//-----------------------------------------------------------

template < class DT >
void List<DT>::showStructure() const
{
    ListNode<DT>* p;   // Iterates through the list

    if (head == nullptr)
        cout << "Empty list" << endl;
    else
    {
        p = head;
        do
        {
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
}


//-----------------------------------------------------------
// In-lab2 operation
//template <class DT>
//void List<DT>::reverse()
//{
//
//}

// In-lab3 operation
//template <class DT >
//int List<DT>::getLength() const
//{
//
//}

//template <class DT>
//int List<DT>::getPosition() const
//{
//
//}