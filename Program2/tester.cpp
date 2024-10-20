// Program 2 Binary Search Tree - CSS343A Wooyoung Kim - BinTree class by David H. Kim
// Testing file

#include "BinTree.h"
#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

// using buildtree from driver.cpp
void buildTree(BinTree &T, ifstream &infile)
{
    string s;
    for (;;)
    {
        infile >> s;
        // s=trim(s);
        //  cout << s << ' ';
        if (s == "$$")
            break; // at end of one line
        if (infile.eof())
            break;       // no more lines of data
        string data = s; // data takes a string
        // would do a setData if there were more than a string
        bool success = T.insert(s);
    }
}

void printArray(string a[])
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        if (!a[i].empty())
            cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "Testing Default Constructor and isEmpty" << endl;
    BinTree default_tree;
    cout << "Should return 1 (true), Actual Return: " << default_tree.isEmpty() << endl;

    cout << "--------TESTING BINTREE FUNCTIONS WITH 3 DIFFERENT TREES------" << endl;

    ifstream infile;
    infile.open("test.txt");

    if (!infile)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }

    cout << "Reading nodes from a file" << endl;
    while (!infile.eof())
    {
        BinTree test_tree;
        buildTree(test_tree, infile);

        cout << "Testing insert: If correctly implemented, tree will display correctly with the values inserted" << endl;

        cout << "Sideways: " << endl;
        test_tree.displaySideways();

        cout << "Display:" << endl;
        test_tree.displayTree();

        cout << "In-order display: (output overload)" << endl;
        cout << test_tree << endl;

        cout << "Testing retrieve: " << endl;

        string test_val = "10";
        Node *test_val_address;

        bool found = test_tree.retrieve(test_val, test_val_address);
        cout << "Retrieve " << test_val << (found ? ": found" : ": not found")<< endl;
        if (found)
        {
            cout << "Test value address is " << test_val_address << endl;
        }

        cout << "Testing getHeight: " << endl;
        cout << "Height: Height of 10 should be 1 since it is leaf, in other trees 0 as it DNE" << endl;
        cout << test_tree.getHeight(test_val) << endl;

        cout << "Testing Copy Constructor" << endl;
        BinTree copy_tree(test_tree);
        cout << "Copy Constructor: " << copy_tree << endl;

        cout << "Testing assignment overload" << endl;
        BinTree assignment_tree = test_tree;
        cout << "Assignment overload: " << assignment_tree << endl;

        cout << "Testing compare == and != overload" << endl;
        cout << "Are they same? " << ((copy_tree == assignment_tree) ? " yes " : " no") << endl;
        cout << "Are they different? " << ((copy_tree != assignment_tree) ? " yes " : " no") << endl;

        cout << "Testing BSTreeToArray" << endl;

        string test_arr[ARRAYSIZE];
        BinTree og(test_tree); // store og in a new tree w cc

        test_tree.bstreeToArray(test_arr);
        printArray(test_arr);

        cout << "Testing ArrayToBSTree. The Tree should be a balanced tree" << endl;
        test_tree.arrayToBSTree(test_arr);

        test_tree.displaySideways();
        test_tree.displayTree();

        cout << "Testing if the original tree before conversion, and new tree after conversion are the same" << endl;
        cout << "Are they same? " << ((og == test_tree) ? " yes " : " no") << endl;
        cout << "Are they different? " << ((og != test_tree) ? " yes " : " no") << endl;

        cout << "To test destructor, run valgrind ./a.out to see if there are any memory leaks" << endl;

        cout << "---------------FINISHED TESTING THE BINTREE FUNCTIONS--------------" << endl;
    }
    return 0;
}
