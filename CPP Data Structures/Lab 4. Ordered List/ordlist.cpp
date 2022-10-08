#include "ordlist.h"

OrdList::OrdList(int maxNumber)
{
	cursor = -1;
	size = 0;
	dataItems = new DataType[maxNumber];
	maxSize = maxNumber;
}

void OrdList::insert(const DataType& newDataItem)

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
			int index = 0;

			binarySearch(newDataItem.getKey(), index);

			size++;

			for (int i = 0; i < size - cursor; i++)
			{
				dataItems[size - i] = dataItems[size - 1 - i];
			}

			dataItems[cursor] = newDataItem;
		}
	}
}

void OrdList::replace(const DataType& newDataItem)

{
	if (isEmpty())
	{
		cout << "Empty List" << endl;
	}

	else
	{
		int i, j;

		dataItems[cursor] = newDataItem;

		for (i = 1; i < size; i++)
		{
			DataType key = dataItems[i];

			for (j = i - 1; j >= 0 && dataItems[j].getKey() > key.getKey(); j--)
			{
				dataItems[j + 1] = dataItems[j];
			}

			dataItems[j + 1] = key;

			cursor = 0;
			while (dataItems[cursor].getKey() != newDataItem.getKey())
			{
				cursor++;
			}
		}
	}
}

bool OrdList::retrieve(char searchKey, DataType& searchDataItem)
{
	int c = cursor;
	cursor = 0;

	searchDataItem.setKey(searchKey);

	for (int i = 0; i < size - cursor; i++)
	{
		if (dataItems[cursor + i].key == searchKey)
		{
			cursor += i;
			return true;
		}
		
		if (cursor + i == size - 1)
		{
			cursor = c;
			return false;
		}
	}
	
}

bool OrdList::binarySearch(char searchKey, int& index)
{
	int first = 0;
	int last = size - 1;
	int mid = index;
	bool moreToSearch = (first <= last);
	bool found = false;

	// »ðÀÔ À§Ä¡ Å½»ö
	while (moreToSearch && !found) {

		mid = (first + last) / 2;

		if (searchKey == dataItems[mid].getKey())
		{
			found = true;
			cursor = mid;
			return true;
		}

		else if (searchKey > dataItems[mid].getKey())
		{
			moreToSearch = (first <= last);
			first = mid + 1;
		}

		else if (searchKey < dataItems[mid].getKey())
		{
			moreToSearch = (first <= last);
			last = mid - 1;
		}
	}

	cursor = mid;

	if (searchKey < dataItems[mid].getKey())
	{
		return false;
	}

	else if (searchKey > dataItems[mid].getKey())
	{
		cursor = mid + 1;
		return false;
	}

	else
	{
		return true;
	}
}

//--------------------------------------------------------------------


void OrdList::merge(const OrdList& fromL)
{
	for (int i = 0; i < fromL.size; i++)
	{
		insert(fromL.dataItems[i]);
	}

}

bool OrdList::isSubset(const OrdList& subL)
{
	int count = 0;

	for (int i = 0; i < subL.size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (subL.dataItems[i].getKey() == dataItems[j].getKey())
			{
				count++;
			}
		}
	}
	
	if (count == subL.size)
		return true;
	else
		return false;
}