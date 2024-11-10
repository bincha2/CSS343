// Program 3 - GraphM Class (Djikstras) - CSS343 Wooyoung Kim - David H. Kim

#ifndef GRAPHM_H_
#define GRAPHM_H_
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cmath>
#include <iomanip>
#include "graphl.h"
using namespace std;

class GraphM
{
public:
    GraphM();                       // DEFAULT CONSTRUCTOR, set T , all dist to inf, visit to false, and path to 0
    int buildGraph(ifstream &file); // Builds graph and adj matrix from file

    int insertEdge(int from_node, int to_node, int dist); // insert edge into graph
    int removeEdge(int from_node, int to_node);           // remove edge into graph

    void findShortestPath(); // djikstras, tabletype T is updated with path information

    void displayAll();                        // display like the provided output
    void display(int from_node, int to_node); // display a path from from_node to to_node w/ node details

private:
    struct TableType
    {
        bool visited; // whether node has been visited
        int dist;     // shortest distance from source known so far
        int path;     // previous node in path of min dist
    };

    string data[MAXNODES];           // HOLDS THE DATA FOR EACH NODE
    int C[MAXNODES][MAXNODES];       // COST ARRAY ADJ MATRIX
    int size;                        // N number of nodes in each graph
    TableType T[MAXNODES][MAXNODES]; // stores visited, distance, and prev path

    //helper functions for dispalying the path and the path names recuirsivly 
    void printPath(int from_node, int to_node);
    void printName(int from_node, int to_node);
};
#endif