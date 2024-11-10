// Program 3 - GraphL Class (DFS) - CSS343 Wooyoung Kim - David H. Kim

#ifndef GRAPHL_H_
#define GRAPHL_H_
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cmath>
#include <iomanip>
#include <stack>
using namespace std;

const int MAXNODES = 101; // max nodes cant exceed 100 in graph, 101 for 1 based indexing

class GraphL
{
public:
    GraphL();                       // Default constructor
    ~GraphL();                      // Destructor
    int buildGraph(ifstream &file); // Builds graph from file and adj list
    void displayGraph();            // Displays graph and its edges like the provided output
    void depthFirstSearch();        // DFS

private:
    struct EdgeNode; // Forward reference for compiler
    struct GraphNode
    {
        EdgeNode *edgeHead; // Head of the list of edges
        string data;        // Data description of the node
        bool visited;       // Marked if node has been visited in DFS
    };

    struct EdgeNode
    {
        int adjGraphNode;   // The index of the adjacent graph node
        EdgeNode *nextEdge; // Pointer to the next edge
    };

    int size;                       // N number of nodes in each graph
    GraphNode *nodeArray[MAXNODES]; // Array of graph nodes
};

#endif