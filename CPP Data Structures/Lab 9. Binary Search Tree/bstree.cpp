#include "bstree.h"

template < class DT, class KF >
BSTreeNode<DT, KF>::BSTreeNode(const DT& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
{

}

template < class DT, class KF >
BSTree<DT, KF>::BSTree()
{

}

template < class DT, class KF >
BSTree<DT, KF>::~BSTree()
{

}

//--------------------------------------------------------------------

// Insert

template < class DT, class KF >
void BSTree<DT, KF>::insert(const DT& newDataItem)
{

}

template < class DT, class KF >
void BSTree<DT, KF>::insertSub(BSTreeNode<DT, KF>*& p, const DT& newDataItem)
{

}

//--------------------------------------------------------------------

// Retrieve

template < class DT, class KF >
bool BSTree<DT, KF>::retrieve(KF searchKey, DT& searchDataItem) const
{

}

template < class DT, class KF >
bool BSTree<DT, KF>::retrieveSub(BSTreeNode<DT, KF>* p, KF searchKey, DT& searchDataItem) const
{

}

//--------------------------------------------------------------------

// Remove

template < class DT, class KF >
bool BSTree<DT, KF>::remove(KF deleteKey)
{

}

template < class DT, class KF >
bool BSTree<DT, KF>::removeSub(BSTreeNode<DT, KF>*& p, KF deleteKey)
{

}

template < class DT, class KF >
void BSTree<DT, KF>::cutRightmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr)
{

}

//--------------------------------------------------------------------

// Write Keys

template < class DT, class KF >
void BSTree<DT, KF>::writeKeys() const
{

}

template < class DT, class KF >
void BSTree<DT, KF>::writeKeysSub(BSTreeNode<DT, KF>* p) const
{

}

//--------------------------------------------------------------------

// Clear

template < class DT, class KF >
void BSTree<DT, KF>::clear()
{

}

template < class DT, class KF >
void BSTree<DT, KF>::clearSub(BSTreeNode<DT, KF>* p)
{

}

//--------------------------------------------------------------------

// Empty / Full

template < class DT, class KF >
bool BSTree<DT, KF>::isEmpty() const
{

}

template < class DT, class KF >
bool BSTree<DT, KF>::isFull() const
{

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

}

template < class DT, class KF >
int BSTree<DT, KF>::getHeightSub(BSTreeNode<DT, KF>* p) const
{

}

//--------------------------------------------------------------------

// In-lab 3
template < class DT, class KF >
void BSTree<DT, KF>::writeLessThan(KF searchKey) const
{

}

template < class DT, class KF >
void BSTree<DT, KF>::writeLTSub(BSTreeNode <DT, KF>* p, const KF searchKey) const
{

}