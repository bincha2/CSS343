// Program 3 - CSS343 Wooyoung Kim - David H. Kim - GraphM (Dijkstra's Algorithm)

#ifndef GRAPHM_H_
#define GRAPHM_H_
#include <iostream>
using namespace std;

const int MAXNODES = 100;

struct TableType
{
    bool visited; // whether the node has been visited
    int dist;     // shortest distance from source that we know so far
    int path;     // previous node in path of minimum distance
};

class GraphM
{
public:
    
    //functions
    GraphM(); //def constructor, data member T is initalized to set all dist to inf, sets all visted to false, & path to 0

    int buildGraph(); //builds up graph node inforrmation and adj matrix of edges between each node from file. Return int, -1 if fail, 1 true

    int insertEdge(int from_node, int to_node, int weight); //insert an edge into graph between two given nodes. The return type is an integer. Return -1 if fail. Otherwise, return 1.

    int removeEdge(int from_node, int to_node); //remove an edge between two given nodes. The return type is an integer. Return -1 if fail. Otherwise, return 1.

    void findShortestPath(); //find the shortest path between every node to every other node in the graph, i.e., TableType T is updated with shortest path information. Return type is "void"

    //display functions
    void displayAll(); //uses "cout"s to demonstrate that the algorithm works properly. Return type is "void" 

    void display(int from_node, int to_node); //uses "cout"s to display the shortest distance with path info between the fromNode to toNode. Return type is "void"

private:
    string data[MAXNODES];           // Data for graph nodes, contains the names of the nodes as string
    int C[MAXNODES][MAXNODES];       // Cost array (Adjacency Matrix)
    int size;                        // Number of nodes in the graph
    TableType T[MAXNODES][MAXNODES]; // Stores visited, distance, path
};
#endif