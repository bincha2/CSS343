#include "TransposeList.h"  // uncomment to test transposelist
//#include "MtfList.h"      // uncomment to test MtfList
//#include "CDLinkedList.h" // uncomment to test CDLinkedList
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Uncomment to test MtfList or CDLinkedList
    // MtfList testList;   // Uncomment to test MtfList
    TransposeList testList; // Uncomment to test transposelist
    // CDLinkedList testList; // Uncomment to test CDLinkedList

    // Reset all traverse counts first
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
