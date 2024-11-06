#include "graphm.h"

GraphM::GraphM() // default constructor
{
    size = 0;

    // intialize the detail array to empty
    for (int i = 1; i < MAXNODES; i++)
    {
        data[i] = "";
    }

    // initalize the cost adj matrix to INF
    for (int i = 1; i < MAXNODES; i++)
    {
        for (int j = 1; j < MAXNODES; j++)
        {
            C[i][j] = INT_MAX;
        }
    }

    // initalize table struct to default, (visited = false, dist = INF, path = 0)
    for (int i = 1; i < MAXNODES; i++)
    {
        for (int j = 1; j < MAXNODES; j++)
        {
            T[i][j].visited = false;
            T[i][j].dist = INT_MAX;
            T[i][j].path = 0;
        }
    }
}

int GraphM::buildGraph(ifstream &infile)
{
    // initialize edges, # of nodes, and the name of the nodes
    int from_node;
    int to_node;
    int weight;
    string name;

    infile >> size; // stores N nodes into size
    infile.ignore();

    if (size < 1 || size > 100)
    {
        cerr << "Cannot have less than 1 node or more than 100 nodes per graph" << endl;
        return -1; // failed
    }

    for (int i = 1; i <= size; i++)
    {
        getline(infile, data[i]); // since theres N nodes, theres N lines of Names, store into data array
    }

    while (infile >> from_node >> to_node >> weight)
    {
        if (from_node == 0) // first int = 0, end of graph
        {
            break;
        }
        else // create the cost array
        {
            C[from_node][to_node] = weight; // store the edge ex.C[1][2] = 50
        }
    }

    return 1; // success
}

int GraphM::insertEdge(int from_node, int to_node, int weight)
{
    // check to see if its valid edge
    if (from_node < 1 || from_node > size || to_node < 1 || to_node > size || from_node == to_node || weight < 0) 
    {
        cerr << "invalid edge" << endl;
        return -1; // failed
    }
    else
    {
        C[from_node][to_node] = weight; // store the edge
        return 1;                       // success
    }
}

int GraphM::removeEdge(int from_node, int to_node)
{
    // chek to see if its a valid edge
    if (from_node < 1 || from_node > size || to_node < 1 || to_node > size || from_node == to_node)
    {
        cerr << "invalid edge" << endl;
        return -1; // failed
    }
    else
    {
        C[from_node][to_node] = INT_MAX; // set edge to infinity
        return 1;                         // success
    }
}