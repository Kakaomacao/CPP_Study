//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr2.h"

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
{
	// pre-lab

}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab

}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab

}

//--------------------------------------------------------------------

void List::remove()

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab

}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab

}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	// pre-lab
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	// pre-lab

}

//--------------------------------------------------------------------

void List::gotoBeginning()
// Moves the cursor to the beginning of the list.
{
	// pre-lab

}

//--------------------------------------------------------------------

void List::gotoEnd()

// Moves the cursor to the end of the list.

{
	// pre-lab
}

//--------------------------------------------------------------------

bool List::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab

}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab

}

//--------------------------------------------------------------------

DataType List::getCursor() const
// Returns the item marked by the cursor.

{
	// pre-lab

}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	int j;   // Loop counter

	if (size == 0)
		cout << "Empty list" << endl;
	else
	{
		cout << "size = " << size
			<< "   cursor = " << cursor << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j < size; j++)
			cout << dataItems[j].getKey() << "\t";
		cout << endl;
	}
}