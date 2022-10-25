#include "listdbl.h"

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
{
    dataItem = data;
    prior = priorPtr;
    next = nextPtr;
}

// Constructor
template < class DT >
List<DT>::List(int ignored)
{
    head = NULL;
    cursor = NULL;
}

// Destructor
template < class DT >
List<DT>::~List()
{
    ListNode<DT>* tempPtr1 = cursor;
    ListNode<DT>* tempPtr2 = tempPtr1;

    while (tempPtr2->next != cursor)
    {
        tempPtr2 = tempPtr2->next;
        delete tempPtr1;
        tempPtr1 = tempPtr2;
    }

    delete tempPtr1;
    head = NULL;
}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{
    if (isFull())
    {

    }

    else
    {
        if (isEmpty())
        {
            ListNode<DT>* newNode = new ListNode<DT>(newDataItem, NULL, NULL);

            head = newNode;
            cursor = newNode;
            newNode->prior = newNode;
            newNode->next = newNode;
        }

        else
        {
            ListNode<DT>* newNode = new ListNode<DT>(newDataItem, cursor, cursor->next);
            cursor->next = newNode;
            newNode->next->prior = newNode;
            cursor = newNode;
        }
    }
}

// Remove data item
template < class DT >
void List<DT>::remove()
{
    if (isEmpty())
    {

    }

    else
    {
        ListNode<DT>* tempPtr = cursor;

        if (cursor->next == cursor)
        {
            delete head;
            head = NULL;
        }
       
        
        else {

            if (cursor == head)
                head = cursor->next;

            cursor->next->prior = cursor->prior;
            cursor->prior->next = cursor->next;
            cursor = cursor->next;

            delete tempPtr;
        }
    }
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement)
{
    if (cursor == head)
        head = cursor->next;

    ListNode<DT>* tempPtr = cursor;

    ListNode<DT>* newNode = new ListNode<DT>(newElement, cursor->prior, cursor->next);
    cursor->prior->next = newNode;
    cursor->next->prior = newNode;
    cursor = newNode;

    delete tempPtr;
}

// Clear list
template < class DT >
void List<DT>::clear()
{
    ListNode<DT>* tempPtr1 = cursor;
    ListNode<DT>* tempPtr2 = tempPtr1;
    
    while (tempPtr2->next != cursor)
    {
        tempPtr2 = tempPtr2->next;
        delete tempPtr1;
        tempPtr1 = tempPtr2;
    }

    delete tempPtr1;
    head = NULL;

}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{
    if (head == NULL)
        return true;

    else
        return false;
}

// List is full
template < class DT >
bool List<DT>::isFull() const
{
    ListNode<DT>* newNode = new ListNode<DT>(0, NULL, NULL);

    if (newNode == NULL)
    {
        delete newNode;
        return true;
    }

    else
    {
        delete newNode;
        return false;
    }
}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{
    cursor = head;
}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{
    cursor = head->prior;
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{
    if (isEmpty())
    {

    }

    else
    {
        if (cursor->next != NULL)
        {
            cursor = cursor->next;
            return true;
        }

        else
            return false;
    }
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior()
{
    if (isEmpty())
    {

    }

    else
    {
        if (cursor->prior != NULL)
        {
            cursor = cursor->prior;
            return true;
        }

        else
            return false;
    }
}


template < class DT >
DT List<DT>::getCursor() const
{
    return cursor->dataItem;
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
template <class DT>
void List<DT>::reverse()
{
    ListNode<DT>* tempPtr;
    ListNode<DT>* tempNext = head;
    ListNode<DT>* tempCursor = head;
    ListNode<DT>* reverseHead = head->prior;

    while (tempCursor != reverseHead)
    {
        tempNext = tempNext->next;

        tempPtr = tempCursor->next;
        tempCursor->next = tempCursor->prior;
        tempCursor->prior = tempPtr;


        tempCursor = tempNext;
    }

    tempPtr = tempCursor->next;
    tempCursor->next = tempCursor->prior;
    tempCursor->prior = tempPtr;

    head = reverseHead;
}

// In-lab3 operation
template <class DT>
int List<DT>::getLength() const
{
    int count = 0;

    ListNode<DT>* p; 

    if (head == nullptr)
        return count;

    else
    {
        p = head;
        do
        {
            count++;
            p = p->next;

        } while (p != head);
    }

    return count;
}

template <class DT>
int List<DT>::getPosition() const
{
    int count = 0;

    ListNode<DT>* p;   

    if (head == cursor)
        return 0;

    else
    {
        p = head;
        do
        {
            count++;
            p = p->next;

        } while (p != cursor);
    }

    return count;
}