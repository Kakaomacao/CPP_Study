//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr.h"

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize)
// 동적 할당
{
	cursor = -1;
	size = 0;
	dataItems = new DataType[maxNumber];
	maxSize = maxNumber;
}

//--------------------------------------------------------------------

List:: ~List()

// Frees the memory used by a list.
{
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.
{
	if (isFull())
	{
		cout << "List is Full" << endl;
	}
	else
	{
		if (isEmpty())
		{
			size += 1;
			cursor += 1;
			dataItems[cursor] = newDataItem;
		}
		else
		{
			cursor++;
			size += 1;
			for (int i = 0; i < size; i++)
			{
				dataItems[cursor + 1 + i] = dataItems[cursor + i];
			}
			dataItems[cursor] = newDataItem;
		}
	}
}

//--------------------------------------------------------------------

void List::remove()

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	if (cursor == size - 1)
	{
		size -= 1;
		cursor = 0;
	}
	else
	{
		size -= 1;
		for (int i = 0; i <= size; i++)
		{
			dataItems[cursor + i] = dataItems[cursor + 1 + i];
		}
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	if (isEmpty())
	{
		cout << "Empty List" << endl;
	}
	else
	{
		dataItems[cursor] = newDataItem;
	}
}

//--------------------------------------------------------------------

void List::clear()

// Removes all the data items from a list.
{
	size = 0;
	cursor = 0;
}

//--------------------------------------------------------------------

bool List::isEmpty() const

// Returns true if a list is empty. Otherwise, returns false.
{
	if (size == 0)
		return true;
	else
		return false;
}

//--------------------------------------------------------------------

bool List::isFull() const

// Returns true if a list is full. Otherwise, returns false.
{
	if (size == maxSize)
		return true;
	else
		return false;

}

//--------------------------------------------------------------------

void List::gotoBeginning()

// Moves the cursor to the beginning of the list.
{
	cursor = 0;
}

//--------------------------------------------------------------------

void List::gotoEnd()

// Moves the cursor to the end of the list.

{
	cursor = size - 1;
}

//--------------------------------------------------------------------

bool List::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	if (cursor != size - 1)
	{
		cursor += 1;
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.
{
	if (cursor == 0)
	{
		return false;
	}
	else
	{
		cursor -= 1;
		return true;
	}
}

//--------------------------------------------------------------------

DataType List::getCursor() const

// Returns the item marked by the cursor.
{
	if (isEmpty())
		cout << "Empty List" << endl;
	else
		return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.
{
    // pre-lab
	cout << "size = " << size << "\t" << "cursor = " << cursor << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << "[ " << i << " ]\t";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << dataItems[i] << "  \t";
	}
	cout << endl;
}

//--------------------------------------------------------------------

void List::moveToNth(int n)
{
	char c = 'a';
	c = dataItems[cursor];
	dataItems[cursor] = dataItems[n];
	dataItems[n] = c;
	cursor = n;
}

bool List::find(const DataType& searchDataItem)
{
	for (int i = 0; i < size - cursor; i++)
	{
		if (dataItems[cursor + i] == searchDataItem)
		{
			cursor += i;
			return true;
		}
		if (cursor + i == size - 1)
		{
			cursor += i;
			return false;
		}
	}
}