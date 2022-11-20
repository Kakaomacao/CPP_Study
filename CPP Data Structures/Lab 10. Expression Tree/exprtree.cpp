//--------------------------------------------------------------------
//		Lab 12									exprtree.cpp
//
//--------------------------------------------------------------------

#include "exprtree.h"

//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
{

}

//--------------------------------------------------------------------

ExprTree::ExprTree()
{

}

ExprTree::~ExprTree()
{

}

//--------------------------------------------------------------------

void ExprTree::build()
{

}

void ExprTree::buildSub(ExprTreeNode*& p)
{

}

//--------------------------------------------------------------------

void ExprTree::expression() const
{

}

void ExprTree::exprSub(ExprTreeNode* p) const
{

}

//--------------------------------------------------------------------

float ExprTree::evaluate() const
{

}

float ExprTree::evaluateSub(ExprTreeNode* p) const
{

}

//--------------------------------------------------------------------

void ExprTree::clear()
{

}

void ExprTree::clearSub(ExprTreeNode* p)
{

}

//--------------------------------------------------------------------

void ExprTree::showStructure() const
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

void ExprTree::showSub(ExprTreeNode* p, int level) const
{
    int j;

    if (p != 0)
    {
        showSub(p->right, level + 1);
        for (j = 0; j < level; j++)
            cout << "\t";
        cout << " " << p->dataItem;
        if ((p->left != 0) &&
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);
    }
}

//--------------------------------------------------------------------
//ExprTree::ExprTree(const ExprTree& valueTree)
//{
//
//}


//void ExprTree::copySub(ExprTreeNode*& dest, ExprTreeNode* source)
//{
//
//}

//--------------------------------------------------------------------
//void ExprTree::commute()
//{
//
//}


//void ExprTree::commuteSub(ExprTreeNode*& p)
//{
//
//}