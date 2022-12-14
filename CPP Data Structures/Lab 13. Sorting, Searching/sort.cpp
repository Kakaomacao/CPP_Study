//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------

template < class DT >
void selectionSort(DT keyList[], int numKeys)

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
    for (int i = 0; i < numKeys - 1; i++)
    {
        DT temp;
        DT min = keyList[i];
        int location = i;

        for (int j = i + 1; j < numKeys; j++)
        {
            if (min > keyList[j])
            {
                min = keyList[j];
                location = j;
            }
        }

        temp = keyList[location];
        keyList[location] = keyList[i];
        keyList[i] = temp;
    }
}

//--------------------------------------------------------------------

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right);

template < class DT >
void quickSort(DT keyList[], int numKeys)

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList, numKeys, 0, numKeys - 1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void quickPartition(DT keyList[], int numKeys,
    int left, int right)

    // Recursive partner of the quickSort routine. Partitions the array
    // entries between left and right into two subarrays. One subarray
    // contains the keys that are less than or equal to splitValue, and
    // the other contains the keys that are greater than splitValue.
    // Recursively sorts each of these subarrays.

{
    if (left >= right) return;

    int pivot = left;
    int i = left + 1;
    int j = right;
    int tmp;

    while (i <= j)
    {
        while (keyList[i] < keyList[pivot] && i <= right) 
            i++;

        while (keyList[j] >= keyList[pivot] && j > left)
            j--;

        if (i >= j) break;

        tmp = keyList[i];
        keyList[i] = keyList[j];
        keyList[j] = tmp;
    }

    tmp = keyList[j];
    keyList[j] = keyList[pivot];
    keyList[pivot] = tmp;

    quickPartition(keyList, numKeys, left, j - 1);
    quickPartition(keyList, numKeys, j + 1, right);
}

//--------------------------------------------------------------------

template < class DT >
void bubbleSort(DT keyList[], int numKeys)
{
    DT temp;

    for (int i = 0; i < numKeys; i++)
        for(int j = 0; j < numKeys - 1 - i; j++)
            if (keyList[j] > keyList[j + 1])
            {
                temp = keyList[j];
                keyList[j] = keyList[j + 1];
                keyList[j + 1] = temp;

            }
}