//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 1                      search.cpp
//
//  Implementation of a set of searching routines
//
//--------------------------------------------------------------------

template < class DT >
int linearSearch(DT keyList[], int numKeys,
    DT searchKey, int& index)

    // Linear search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns -1 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey

{
    bool found = false;
    DT temp = keyList[0];

    for (int i = 0; i < numKeys; i++)
    {
        if (keyList[i] == searchKey)
        {
            index = i;
            found = true;
        }

        else if(temp < keyList[i])
            if (temp < searchKey)
            {
                temp = keyList[i];
                index = i;
            }
    }

    if (found)
        return 1;

    else
        return -1;

}

//--------------------------------------------------------------------

template < class DT >
int binarySearch(DT keyList[], int numKeys,
    DT searchKey, int& index)

    // Binary search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns -1 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey

{
    bool found = false;
    int first = 0;
    int last = numKeys - 1;
    int mid;

    while (first <= last) {
        mid = (first + last) / 2;

        if (keyList[mid] == searchKey)
        {
            index = mid;
            return 1;
        }

        else if (keyList[mid] > searchKey) 
            last = mid - 1;

        else 
            first = mid + 1;
    }
    
    return -1;
}