/*Testing with Mtflist. If want to test with transposelist or CDLinkedList, comment
this, and uncomment to include other list*/
//#include "mtflist.h" // uncomment to test Mtflist
#include "transposelist.h" // uncomment to test transposelist
//#include "CDLinkedList.h"// uncomment to test CDLinkedList
#include <iostream>
#include <string>
using namespace std;
int main() {
/*Test with Mtflist. If want to test with transposelist or CDLinkedList, comment
this declaration, and uncomment to declare ohter list*/
//MtfList testList; // uncomment to test Mtflist
TransposeList testList; // uncomment to test transposelist
// CDLinkedList testList; // uncomment to test CDLinkedList
// Reset all traverse count first
testList.resetTraverseCount();
cout << "Make a list" << endl;
testList.add(1);
testList.add(7);
testList.add(8);
testList.add(5);
testList.add(1);
cout<<"Reset traverse count: traverseCount="<<testList.getTraverseCount()<<endl;
cout << "#members 1->7->8->5->1: size=" << testList.getCurrentSize() << ",
traverseCount="<<testList.getTraverseCount()<<endl;;
cout<<"traverse count="<<testList.getTraverseCount()<<endl;
for (int i = 0; i < testList.getCurrentSize(); i++)
cout << testList.retrieve(i) << endl;
cout << endl;
testList.remove(8);
cout << "#After remove 8, : size= " << testList.getCurrentSize() << ",
traverseCount="<<testList.getTraverseCount()<<endl;;
cout<<"traverse count="<<testList.getTraverseCount()<<endl;
for (int i = 0; i < testList.getCurrentSize(); i++)
cout << testList.retrieve(i) << endl;
cout << endl;
cout<<"testList.contains(8)="<<testList.contains(8)<<endl;
cout << "# members, after access 8: size= " << testList.getCurrentSize() << ",
traverseCount="<<testList.getTraverseCount()<<endl;;
for (int i = 0; i < testList.getCurrentSize(); i++)
cout << testList.retrieve(i) << endl;
cout<<"testList.contains(7)="<<testList.contains(7)<<endl;
cout << "# members, after access 7: size= " << testList.getCurrentSize() << ",
traverseCount="<<testList.getTraverseCount()<<endl;
for (int i = 0; i < testList.getCurrentSize(); i++)
cout << testList.retrieve(i) << endl;
return 0;
}