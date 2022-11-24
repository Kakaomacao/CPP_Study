//--------------------------------------------------------------------
//		Lab 12									exprtree.cpp
//
//--------------------------------------------------------------------

#include "exprtree.h"

//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
{
    dataItem = elem;
    left = leftPtr;
    right = rightPtr;
}

//--------------------------------------------------------------------

ExprTree::ExprTree()
{
    root = nullptr;
}

ExprTree::~ExprTree()
{
    // 다 다니면서 삭제
}

//--------------------------------------------------------------------

void ExprTree::build()
{
    buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
    char c;
    cin >> c;

    if (p == nullptr)
    {
        ExprTreeNode* newNode = new ExprTreeNode(c, nullptr, nullptr);
        p = newNode;
    }

    if (isdigit(c))
        return;

    else
    {
        buildSub(p->left);
        buildSub(p->right);
    }
}

//--------------------------------------------------------------------

void ExprTree::expression() const
{
    exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
    if (p != nullptr)
    {
        cout << "(";
        exprSub(p->left);
        cout << p->dataItem;
        exprSub(p->right);
        cout << ")";
    }
}

//--------------------------------------------------------------------

float ExprTree::evaluate() const
{
    return evaluateSub(root);
}

float ExprTree::evaluateSub(ExprTreeNode* p) const
{
    if (isdigit(p->dataItem))
    {
        return (float)(p->dataItem - '0');
    }

    else
    {
        switch (p->dataItem)
        {
        case '+':
            return evaluateSub(p->left) + evaluateSub(p->right);

        case '-':
            return evaluateSub(p->left) - evaluateSub(p->right);

        case '*':
            return evaluateSub(p->left) * evaluateSub(p->right);

        case '/':
            return evaluateSub(p->left) / evaluateSub(p->right);
        }
    }
}

//--------------------------------------------------------------------

void ExprTree::clear()
{
    clearSub(root);
    root = nullptr;
}

void ExprTree::clearSub(ExprTreeNode* p)
{
    if (p == nullptr)
        return;

    clearSub(p->left);
    clearSub(p->right);
    delete p;
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
ExprTree::ExprTree(const ExprTree& valueTree)
{
    ExprTree newTree;
    copySub(newTree.root, valueTree.root);
    root = newTree.root;
}


void ExprTree::copySub(ExprTreeNode*& dest, ExprTreeNode* source)
{
    if (dest == nullptr)
    {
        ExprTreeNode* newNode = new ExprTreeNode(source->dataItem, nullptr, nullptr);
        dest = newNode;
    }

    if (isdigit(dest->dataItem))
        return;
    else
    {
        copySub(dest->left, source->left);
        copySub(dest->right, source->right);
    }
}

//--------------------------------------------------------------------
void ExprTree::commute()
{
    commuteSub(root);
}


void ExprTree::commuteSub(ExprTreeNode*& p)
{
    ExprTreeNode* temp;

    if (p == nullptr)
        return;

    temp = p->left;
    p->left = p->right;
    p->right = temp;

    if (isdigit(p->dataItem))
        return;

    else
    {
        commuteSub(p->left);
        commuteSub(p->right);
    }
}