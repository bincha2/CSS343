#include "BinTree.h"

BinTree::BinTree()
{
    root = NULL;
}

BinTree::BinTree(const BinTree &tree)
{
    *this = tree;
}

BinTree::~BinTree()
{
    recursiveDestroy(root);
}

bool BinTree::isEmpty() const
{
    return (root == NULL);
}

bool BinTree::insert(const string &string)
{
    return (recursiveInsert(root, string));
}

bool BinTree::retrieve(const string &string, Node *&node)
{
    return (recursiveRetrieve(root, string, node));
}

int BinTree::getHeight(const string &string) const
{
    return (recursiveGetHeight(root, string));
}

void BinTree::displayTree() const
{
    recursiveDisplayTree(root);
}

void BinTree::displaySideways() const
{
    recursiveDisplaySideways(root);
}

void BinTree::bstreeToArray(string arr[ARRAYSIZE])
{
    recursiveBSTreeToArray(root, arr);
}

void BinTree::arrayToBSTree(string arr[ARRAYSIZE])
{
    recursiveArrayToBSTree(root, arr);
}

BinTree &BinTree::operator=(const BinTree &tree)
{
    if (this != &tree)
    {
        recursiveDestroy(root);
        recursiveCopy(tree.root, root);
    }
    return *this;
}

bool BinTree::operator==(const BinTree &tree) const
{
    return (recursiveCompare(root, tree.root));
}

bool BinTree::operator!=(const BinTree &tree) const
{
    return (!(*this == tree));
}


