//#include "TransposeList.h"  // uncomment to test transposelist
//#include "MtfList.h"      // uncomment to test MtfList
#include "CDLinkedList.h" // uncomment to test CDLinkedList
#include <iostream>
#include <string>
using namespace std;



//testing CDLinked List functions
void testDefConstructor()
{
    cout << "Testing Default Constructor " << endl;
    CDLinkedList list;
    cout << "Checking if empty, True(1) False(0): " << list.isEmpty() << endl;
    cout << "Checking if size = 0, Size: " << list.getCurrentSize() << endl;
    cout << endl;
}

void testCopyConstructor()
{
    cout << "Testing copy constructor " << endl;
    CDLinkedList list1;
    list1.add(2);
    list1.add(4);
    list1.add(6);

    CDLinkedList list2(list1);
    cout << "List1 Size: " << list1.getCurrentSize() << endl;
    cout << "List2 Size: " << list2.getCurrentSize() << endl;

    cout << "List1: "; 
    for (int i = 0; i < list1.getCurrentSize(); i++)
    {
        cout << list1.retrieve(i) << " ";
    }
    cout << "List2: "; 
    for (int i = 0; i < list2.getCurrentSize(); i++)
    {
        cout << list2.retrieve(i) << " ";
    }
    cout << endl << endl;

}

void testGetCurrentSize(CDLinkedList &list)
{
    cout << "Testing Get Curr Size" << endl;
    cout << "Correct Size: 5, Actual Size: " << list.getCurrentSize() << endl;
    cout << endl;
}

void testIsEmpty(CDLinkedList &list)
{
    cout << "Testing IsEmpty" << endl;
    cout << "Should return 0 (false), Actual Return: " << list.isEmpty() << endl;
    cout << endl;
}

void testAdd(CDLinkedList &list)
{
    cout << "Testing Add" << endl;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(1);

    cout << "Correct Size: 5, Actual Size: " << list.getCurrentSize() << endl;

    cout << "Correct Order: 5-4-3-2-1, Actual Order: ";
    for (int i = 0; i < list.getCurrentSize(); i++)
    {
        cout << list.retrieve(i) << " ";
    }
    cout << endl << endl;
}

void testRemove(CDLinkedList &list)
{
    cout << "Testing Remove" << endl;
    list.remove(1);
    list.remove(2);
    list.remove(1); //already removed

    cout << "Correct Size: 3, Actual Size: " << list.getCurrentSize() << endl;

    cout << "Correct Order: 5-4-3, Actual Order: ";
    for (int i = 0; i < list.getCurrentSize(); i++)
    {
        cout << list.retrieve(i) << " ";
    }
    cout << endl << endl;
}

void testClear(CDLinkedList &list)
{
    cout << "Testing Clear " << endl;
    list.clear();
    cout << "Size: 0, Size: " << list.getCurrentSize() << endl;
    cout << "Empty: true(1), Empty: " << list.isEmpty() << endl;
    cout << endl;
}

void testContains(CDLinkedList &list)
{
    cout << "Testing Contains " << endl;
    cout << "Contains(5) (true), Actual: " << list.contains(5) << endl;
    cout << "Contains(1) (false), Actual: " << list.contains(1) << endl;
    cout << endl;
}

void testGetTraverseCount(CDLinkedList &list)
{
    cout << "Testing Get Traverse Count " << endl;
    cout << list.getTraverseCount() << endl;
    cout << endl;
}

void testRetrieve(CDLinkedList &list)
{
    cout << "Testing Retrieve " << endl;
    cout << "Retrieve(1), Should return 4: Returns: " << list.retrieve(1) << endl;
    cout << "Retrieve(-1), (INVALID -1): Actual: " << list.retrieve(-1) << endl;
    cout << "Retrieve(100), (INVALID -1): Actual: " << list.retrieve(100) << endl;
    cout << endl;
}

void testResetTraverseCount(CDLinkedList &list)
{
    cout << "Testing Reset Traverse Count " << endl;
    cout << "Traverse Count Pre-reset: " << list.getTraverseCount() << endl;

    list.resetTraverseCount();
    cout << "Traverse Count After-reset: " << list.getTraverseCount() << endl;
    cout << endl;
}


int main() {

    cout << "Testing all functions in CDLinkedList.cpp to ensure they are working" << endl;
    cout << "Output may not correctly align with the correct answers when testing with MTF & Transpose" << endl;

    testDefConstructor();
    testCopyConstructor();

    CDLinkedList list;
    //MtfList list;
    //TransposeList list;

    testAdd(list);
    testGetCurrentSize(list);
    testIsEmpty(list);
    testRemove(list);
    testContains(list);
    testRetrieve(list);
    testGetTraverseCount(list);
    testResetTraverseCount(list);
    testClear(list);

    // Reset all traverse counts first
    //MtfList testList;   // Uncomment to test MtfList
    //TransposeList testList; // Uncomment to test transposelist
    CDLinkedList testList; // Uncomment to test CDLinkedList

    cout << "Now Testing given driver file code " << endl;

    testList.resetTraverseCount();
    cout << "Make a list" << endl;

    testList.add(1);
    testList.add(7);
    testList.add(8);
    testList.add(5);
    testList.add(1);

    cout << "Reset traverse count: traverseCount=" << testList.getTraverseCount() << endl;
    cout << "#members 1->7->8->5->1: size=" << testList.getCurrentSize()
         << ", traverseCount=" << testList.getTraverseCount() << endl;

    cout << "traverse count=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << endl;
    }
    cout << endl;

    testList.remove(8);
    cout << "#After remove 8, : size= " << testList.getCurrentSize()
         << ", traverseCount=" << testList.getTraverseCount() << endl;

    cout << "traverse count=" << testList.getTraverseCount() << endl;
    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << endl;
    }
    cout << endl;

    cout << "testList.contains(8)=" << testList.contains(8) << endl;
    cout << "# members, after access 8: size= " << testList.getCurrentSize()
         << ", traverseCount=" << testList.getTraverseCount() << endl;

    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << endl;
    }

    cout << "testList.contains(7)=" << testList.contains(7) << endl;
    cout << "# members, after access 7: size= " << testList.getCurrentSize()
         << ", traverseCount=" << testList.getTraverseCount() << endl;

    for (int i = 0; i < testList.getCurrentSize(); i++) {
        cout << testList.retrieve(i) << endl;
    }

    return 0;
}
