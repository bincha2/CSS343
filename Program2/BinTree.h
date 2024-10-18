//Program 2 Binary Search Tree - CSS343A Wooyoung Kim - BinTree class by David H. Kim

#ifndef BINTREE_H_
#define BINTREE_H_
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int ARRAYSIZE = 100;

//BST Node contains pointer for left, right, and data
struct Node
{
    string data;
    Node *left;
    Node *right;
};

class BinTree
{
    //output overload to correctly print BinTree
    friend ostream& operator<<(ostream& out, const BinTree& tree);

public:
    //constructor, copy constructor, destructor
    BinTree();
    BinTree(const BinTree &tree);
    ~BinTree();

    //functions
    bool isEmpty() const; //check if tree is empty
    bool insert(const string &string); //insert node with the node data
    bool retrieve(const string &string, Node *&node); //retrieve the pointer of the node of given data
    int getHeight(const string &string) const; //get height of a node starting from leaf (=1)

    //display functions
    void displayTree() const; //displays the tree in pre-order, provide the prefix (Root, L--, R--)
    void displaySideways() const; //displays the tree sideways rotated 90 degrees

    //misc functions
    void bstreeToArray(string arr[]); //fill an array of string by using inorder traversal of tree. Leaves tree empty

    /*builds a balanced BinTree from a sorted array of string leaving the array empty (filled with nulls)
      root (recursively) is at (low+high)/2 */
    void arrayToBSTree(string arr[]); 

     //operator overloads
    BinTree &operator=(const BinTree &tree); //this = rhs, used in copy constructor (deep copy)
    bool operator==(const BinTree &tree) const; //this == rhs
    bool operator!=(const BinTree &tree) const; //this != rhs

private:
    Node *root; //points to the root of bstree

    //recursive helpers
    bool recursiveInsert(Node *&curr, const string &string);
    bool recursiveRetrieve(Node *curr, const string &string, Node *&node);
    int recursiveGetHeight(Node *curr, const string &string) const;
    void recursiveDisplayTree(Node *curr) const;
    void recursiveDisplaySideways(Node *curr) const;
    void recursiveBSTreeToArray(Node *curr, string arr[]);
    void recursiveArrayToBSTree(Node *curr, string arr[]);
    void recursiveCopy(Node *curr, Node *&new_node);
    bool recursiveCompare(Node *curr, Node *rhs) const;
    void recursiveDestroy(Node *curr);
};
#endif