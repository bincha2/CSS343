//---------------------------------------------------------------------------
// driver.cpp
//---------------------------------------------------------------------------
// This code tests the basic functionality of the classes to perform
// Dijkstra's algorihms and depth-first search.
// It is not meant to exhaustively test the class.
//
// Assumptions:
// -- students can follow the directions to interface with this file
// -- text files "data31.txt" and "data32.txt" are formatted as described
// -- Data file dataUWB provides an additional data set for part 1;
// it must be edited, as it starts with a description how to use it
//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "graphl.h"
#include "graphm.h"
using namespace std;
int main()
{
    cout << "\n"
         << "Part 1" << endl;
    ifstream infile1("data31.txt");
    if (!infile1)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }
    // for each graph, find the shortest path from every node to all other nodes
    for (;;)
    {
        if (infile1.eof())
        {
            cout << "No more graphs to read" << endl;
            break;
        }
        GraphM G;
        if (G.buildGraph(infile1) > 0)
        {
            G.findShortestPath();
            cout << "Display all shortest paths" << endl;
            G.displayAll(); // display shortest distance, path to cout
            cout << "Display a shortest paths from data[3] to data[1]" << endl;
            G.display(3, 1); // display path from node 3 to 1 to cout
            cout << "Display a shortest paths from data[1] to data[2]" << endl;
            G.display(1, 2);
            cout << "Display a shortest paths from data[1] to data[4]" << endl;
            G.display(1, 4);
        }
    }

    cout << "\n" << "Part 2" << endl;
    ifstream infile2("data32.txt");
    if (!infile2)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }
    // for each graph, find the depth-first search ordering
    for (;;)
    {
        GraphL G;
        if (infile2.eof())
        {
            cout << "No more graphs to read" << endl;
            break;
        }
        if (G.buildGraph(infile2) > 0)
        {
            cout << "Display Graph" << endl;
            G.displayGraph();
            cout << "Display DFS" << endl;
            G.depthFirstSearch(); // find and display depth-first ordering to cout
        }
    }
    cout << endl;
    return 0;
}