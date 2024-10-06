// Test program to evaluate linked list performance
// Written 10/4/19 by Michael Stiber
//
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// Replace the following include with alternative linked list class. Currently
// it tests CDLinkedList
#include "CDLinkedList.h"
//#include "TransposeList.h"
//#include "MtfList.h"

using namespace std;

int main() {
    // Alter the following declaration to change the linked list class name.
     CDLinkedList theList;
    //TransposeList theList;
    //MtfList theList;

    const int numValues = 1000;
    const int numAccesses = 100000;

    // Create a linked list of the numbers 0..numValues-1
    for (int i = numValues - 1; i >= 0; i--) {
        theList.add(i);
    }

    // Reset the traversal counter, just in case
    theList.resetTraverseCount();

    // Now, access the elements randomly many times
    int theNumber;
    default_random_engine generator;
    uniform_int_distribution<int> uniform(0, numValues - 1);
    normal_distribution<double> normal(numValues / 2.0, numValues / 5.0);

    // As the statistic of comparison, we use a uniform
    // distribution. For sequential search, even a "smart" algorithm
    // shouldn't be able to improve performance.
    for (int i = 0; i < numAccesses; i++) {
        // Access a random item by value
        theNumber = uniform(generator);
        assert(theList.contains(theNumber));
    }

    cout << "Average number of nodes traversed per access (uniform): "
         << theList.getTraverseCount() / double(numAccesses) << endl;

    // Reset the traversal counter.
    theList.resetTraverseCount();

    // We use a normal distribution so that some values are accessed
    // much more frequently. It will be peaked around numValues/2 and fall off
    // rapidly above and below. Note that there is some chance of
    // generating a number outside the legal range, so we test and get a
    // new number if that happens (this is because a uniform
    // distribution goes to +/- infinity). A smart algorithm could in
    // principle take advantage of the higher frequency of access of
    // certain items to lower the average access time. On the other hand,
    // without any "smarts", the mean number of nodes traversed should still
    // be the mean of the distribution, the same as for the uniform distribution.
    for (int i = 0; i < numAccesses; i++) {
        theNumber = 0;
        do {
            theNumber = int(normal(generator));
        } while ((theNumber < 0) || (theNumber >= numValues));
        assert(theList.contains(theNumber));
    }

    cout << "Average number of nodes traversed per access (normal): "
         << theList.getTraverseCount() / double(numAccesses) << endl;

    return 0; // end LinkedListStats
}
