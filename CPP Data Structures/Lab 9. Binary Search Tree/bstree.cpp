#include "bstree.h"

template < class DT, class KF >
BSTreeNode<DT, KF>::BSTreeNode(const DT& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
{
    dataItem = nodeDataItem;
    left = leftPtr;
    right = rightPtr;
}

template < class DT, class KF >
BSTree<DT, KF>::BSTree()
{
    root = nullptr;
}

template < class DT, class KF >
BSTree<DT, KF>::~BSTree()
{
    clear();
}

//--------------------------------------------------------------------

// Insert

template < class DT, class KF >
void BSTree<DT, KF>::insert(const DT& newDataItem)
{
    insertSub(root, newDataItem);
}

template < class DT, class KF >
void BSTree<DT, KF>::insertSub(BSTreeNode<DT, KF>*& p, const DT& newDataItem)
{
    if (p == nullptr)
    {
        BSTreeNode<DT, KF>* newNode = new BSTreeNode<DT, KF>(newDataItem, nullptr, nullptr);
        p = newNode;
    }

    else 
    {
        if (p->dataItem.getKey() > newDataItem.getKey())
            insertSub(p->left, newDataItem);

        else if (p->dataItem.getKey() < newDataItem.getKey())
            insertSub(p->right, newDataItem);
    }
}

//--------------------------------------------------------------------

// Retrieve

template < class DT, class KF >
bool BSTree<DT, KF>::retrieve(KF searchKey, DT& searchDataItem) const
{
    bool found = false;

    if (retrieveSub(root, searchKey, searchDataItem))
        found = true;

    return found;
}

template < class DT, class KF >
bool BSTree<DT, KF>::retrieveSub(BSTreeNode<DT, KF>* p, KF searchKey, DT& searchDataItem) const
{
    if (p == nullptr)
        return false;

    if (p->dataItem.getKey() == searchKey)
    {
        searchDataItem.setKey(searchKey);
        return true;
    }

    else if (p->dataItem.getKey() > searchKey)
        retrieveSub(p->left, searchKey, searchDataItem);

    else if (p->dataItem.getKey() < searchKey)
        retrieveSub(p->right, searchKey, searchDataItem);

    else
        return false;
}

//--------------------------------------------------------------------

// Remove

template < class DT, class KF >
bool BSTree<DT, KF>::remove(KF deleteKey)
{
    return removeSub(root, deleteKey);
}

template < class DT, class KF >
bool BSTree<DT, KF>::removeSub(BSTreeNode<DT, KF>*& p, KF deleteKey)
{
    if (p->dataItem.getKey() == deleteKey)
    {
        // leaf인 경우
        if (p->left == nullptr && p->right == nullptr)
        {
            delete p;
            p = nullptr;
        }

        // 자식 1개 왼쪽만 null
        else if (p->left == nullptr && p->right != nullptr)
        {
            BSTreeNode<DT, KF>* temp = p;
            p = p->right;
            delete temp;
        }

        // 자식 1개 오른쪽만 null
        else if (p->right == nullptr && p->left != nullptr)
        {
            BSTreeNode<DT, KF>* temp = p;
            p = p->left;
            delete temp;
        }

        // 자식 2개
        else
        {
            cutRightmost(root, p);
        }

        return true;
    }

    else if (p->dataItem.getKey() > deleteKey)
        return removeSub(p->left, deleteKey);

    else if (p->dataItem.getKey() < deleteKey)
        return removeSub(p->right, deleteKey);

}

template < class DT, class KF >
void BSTree<DT, KF>::cutRightmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr)
{
    BSTreeNode<DT, KF>* temp = r->left;
    BSTreeNode<DT, KF>* temp2 = nullptr;
    while (temp->right != nullptr)
    {
        temp2 = temp;
        temp = temp->right;
    }
    delPtr->dataItem.setKey(temp->dataItem.getKey());
    temp2->right = nullptr;
  
    delete temp;
    temp = nullptr;
}

//--------------------------------------------------------------------

// Write Keys

template < class DT, class KF >
void BSTree<DT, KF>::writeKeys() const
{
    writeKeysSub(root);
}

template < class DT, class KF >
void BSTree<DT, KF>::writeKeysSub(BSTreeNode<DT, KF>* p) const
{
    if (p == nullptr)
        return;

    writeKeysSub(p->left);
    cout << p->dataItem.getKey() << " ";
    writeKeysSub(p->right);
}

//--------------------------------------------------------------------

// Clear

template < class DT, class KF >
void BSTree<DT, KF>::clear()
{
    clearSub(root);
    root = nullptr;
}

template < class DT, class KF >
void BSTree<DT, KF>::clearSub(BSTreeNode<DT, KF>* p)
{
    if (p == nullptr)
        return;

    clearSub(p->left);
    clearSub(p->right);
    delete p;

}

//--------------------------------------------------------------------

// Empty / Full

template < class DT, class KF >
bool BSTree<DT, KF>::isEmpty() const
{
    return (root == nullptr);
}

template < class DT, class KF >
bool BSTree<DT, KF>::isFull() const
{
    bool isFull = false;
    DT a;
    BSTreeNode<DT, KF>* newNode = new BSTreeNode<DT, KF>(a, nullptr, nullptr);

    if (newNode == nullptr)
        isFull = true;

    delete newNode;

    return isFull;
}

//--------------------------------------------------------------------

// Show Structure

template < class DT, class KF >
void BSTree<DT, KF>::showStructure() const
{
    if (root == 0)
        cout << "Empty tree" << endl;
    else
    {
        cout << endl;
        showSub(root, 1);
        cout << endl;
    }
}

template < class DT, class KF >
void BSTree<DT, KF>::showSub(BSTreeNode<DT, KF>* p, int level) const
{
    int j;   // Loop counter

    if (p != 0)
    {
        showSub(p->right, level + 1);         // Output right subtree
        for (j = 0; j < level; j++)    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem.getKey();  // Output key
        if ((p->left != 0) &&           // Output "connector"
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);          // Output left subtree
    }
}

//--------------------------------------------------------------------

// In-lab 2
template < class DT, class KF >
int BSTree<DT, KF>::getHeight() const
{
    return getHeightSub(root);
}

template < class DT, class KF >
int BSTree<DT, KF>::getHeightSub(BSTreeNode<DT, KF>* p) const
{
    if (p == nullptr)
        return 0;

    if (getHeightSub(p->left) > getHeightSub(p->right))
        return getHeightSub(p->left) + 1;

    else
        return getHeightSub(p->right) + 1;
}

//--------------------------------------------------------------------

// In-lab 3
template < class DT, class KF >
void BSTree<DT, KF>::writeLessThan(KF searchKey) const
{
    writeLTSub(root, searchKey);
}

template < class DT, class KF >
void BSTree<DT, KF>::writeLTSub(BSTreeNode <DT, KF>* p, const KF searchKey) const
{
    if (p == nullptr)
        return;

    writeLTSub(p->left, searchKey);
    if (p->dataItem.getKey() < searchKey)
    {
        cout << p->dataItem.getKey() << " ";
    }
    writeLTSub(p->right, searchKey);
}