//--------------------------------------------------------------------
//
//  Laboratory 13                                             heap.cpp
//
//  Actual implementation of class in the Heap ADT
//--------------------------------------------------------------------

#include "heap.h"

//--------------------------------------------------------------------


template<class DT>
Heap<DT>::Heap(int maxNumber)
{
    maxSize = maxNumber;
    size = 0;
    dataItems = new DT[maxSize];
}

template < class DT >
Heap<DT>::~Heap()
{
    delete[] dataItems;
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::insert(const DT& newDataItem)
{
    if (!isFull())
    {
        dataItems[size].setPty(newDataItem.pty());
        size++;

        int child = size - 1;
        int parent = (child - 1) / 2;
        while (child > 0 && dataItems[parent].pty() < dataItems[child].pty())
        {
            DT temp = dataItems[parent];
            dataItems[parent].setPty(dataItems[child].pty());
            dataItems[child].setPty(temp.pty());
            
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    else
        cout << "Heap is Full" << endl;
}

template < class DT >
DT Heap<DT>::removeMax()
{
    // 처음과 마지막 교환
    DT temp = dataItems[0];
    dataItems[0].setPty(dataItems[size - 1].pty());
    size--;

    // 자식과 비교해서 더 큰 것과 교환
    int parent = 0;
    int child = parent * 2 + 1;
    if (child + 1 <= size) {
        child = (dataItems[child].pty() > dataItems[child + 1].pty()) ? child : child + 1;
    }

    while (child <= size && dataItems[parent].pty() < dataItems[child].pty()) {
        DT temp = dataItems[parent];
        dataItems[parent].setPty(dataItems[child].pty());
        dataItems[child].setPty(temp.pty());

        parent = child;
        child = child * 2 + 1;
        if (child + 1 <= size) {
            child = (dataItems[child].pty() > dataItems[child + 1].pty()) ? child : child + 1;
        }
    }

    return temp;
}

template < class DT >
void Heap<DT>::clear()
{
    size = 0;
}

//--------------------------------------------------------------------

template < class DT >
bool Heap<DT>::isEmpty() const
{
    return (size == 0);
}

template < class DT >
bool Heap<DT>::isFull() const
{
    return (size == maxSize);
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::showStructure () const

// Outputs the priorities of the data in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
       cout << "Empty heap" << endl;
    else
    {
       cout << "size = " << size << endl;       // Output array form
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << dataItems[j].pty() << "\t";
       cout << endl << endl;
       showSubtree(0,0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>::showSubtree ( int index, int level ) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
     int j;   // Loop counter

     if ( index < size )
     {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].pty();   // Output dataItems's pty
        if ( 2*index+2 < size )                // Output "connector"
           cout << "<";
        else if ( 2*index+1 < size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>::writeLevels() const
{
    int level = 0;

    while (true)
    {
        int k = 1;
        int sum = 0;
        for (int i = 0; i < level; i++)
        {
            if (level == 0)
            {
                break;
            }

            k = k * 2;
        }

        sum += k;

        if (sum > size)
            break;

        for (int j = k - 1; j <= 2 * (k - 1); j++)
        {
            if (j >= size)
                break;

            cout << dataItems[j].pty() << " ";
        }
        
        level++;
        cout << endl;
    }
}