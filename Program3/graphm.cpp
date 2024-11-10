#include "graphm.h"

// default constructor
GraphM::GraphM()
{
    size = 0; // initalize size to 0

    // initalize cost array to infinity
    for (int i = 0; i < MAXNODES; ++i)
    {
        for (int j = 0; j < MAXNODES; ++j)
        {
            C[i][j] = INT_MAX;
        }
    }

    // initalize table type T to inf, 0, and false
    for (int i = 0; i < MAXNODES; ++i)
    {
        for (int j = 0; j < MAXNODES; ++j)
        {
            T[i][j].dist = INT_MAX;
            T[i][j].path = 0;
            T[i][j].visited = false;
        }
    }
}

// build grapgh from file
int GraphM::buildGraph(ifstream &file)
{
    int from_node;
    int to_node;
    int dist;

    if (!(file >> size) || size > MAXNODES) // read in size && check for errors
    {
        return -1;
    }

    string name;
    getline(file, name);

    for (int i = 1; i <= size; i++) // since theres N (size) nodes, theres N names
    {
        getline(file, name); // store node detail into name
        data[i] = name;      // store node name in data array
    }

    while (file >> from_node >> to_node >> dist)
    {
        if (from_node == 0) // if first int is 0 then signals end of graph
        {
            break;
        }
        else
        {
            C[from_node][to_node] = dist; // create the edge
        }
    }

    return 1; // success
}

int GraphM::insertEdge(int from_node, int to_node, int dist)
{
    // check if valid edge (weight is not neg for djikstras, and valid in the range of node indexs)
    if (dist < 0 || from_node > size || to_node > size || from_node < 1 || to_node < 1)
    {
        return -1;
    }
    else
    {
        C[from_node][to_node] = dist;
        findShortestPath(); // calkl djikstras again to update the matrixs
        return 1;
    }
}

int GraphM::removeEdge(int from_node, int to_node)
{
    // check if its a valid edge i.e cant be less than index of size or greater
    if (from_node < 1 || from_node > size || to_node < 1 || to_node > size)
    {
        return -1;
    }
    else
    {
        C[from_node][to_node] = INT_MAX; // set the edge to infinity (empty)
        findShortestPath();
        return 1;
    }
}

void GraphM::findShortestPath()
{
    // intialize tabletype T to inf, 0, and false
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            T[i][j].dist = INT_MAX;
            T[i][j].path = 0;
            T[i][j].visited = false;
        }
    }

    // djikstras for each node (each node in the graph will be source at 1 point)
    for (int source = 1; source <= size; ++source)
    {
        T[source][source].dist = 0; // source dist is 0

        for (int num = 0; num < size; ++num)
        {
            // find v, not visited shortest distance at this point
            int v = 0;
            for (int i = 1; i <= size; ++i)
            {
                if (!T[source][i].visited && (v == 0 || T[source][i].dist < T[source][v].dist))
                {
                    v = i; // update v to be the next unvisited node
                }
            }

            T[source][v].visited = true; // mark v as visited

            // for each w adjacent to v , and update the path information
            for (int w = 1; w <= size; ++w)
            {
                if (!T[source][w].visited && C[v][w] < INT_MAX && T[source][v].dist < INT_MAX) // check to see if its a valid edge
                {
                    if (T[source][w].dist > T[source][v].dist + C[v][w]) // check if v to w is shorter path than the current path rn
                    {
                        T[source][w].dist = T[source][v].dist + C[v][w]; // distance is updated to reflect the new path
                        T[source][w].path = v;                           // shortest path to w goes through v now
                    }
                }
            }
        }
    }
}

void GraphM::displayAll()
{
    findShortestPath(); // redo djikstras to correctly update paths

    cout << left << setw(25) << "Description" << " " << left << setw(10) << "From Node" << " " 
    << left << setw(10) << "To Node" << " " << left << setw(10) << "Distance" << " " << left << setw(10) << "Path";

    // Loop through each source node
    for (int source = 1; source <= size; ++source)
    {
        cout << endl;
        cout << data[source] << endl; // Print description of the source node

        // Loop through each destination node
        for (int to_node = 1; to_node <= size; ++to_node)
        {
            if (to_node != source)
            {
                cout.width(35);
                cout << right << source;
                cout.width(9);
                cout << to_node;
                cout.width(12);

                if (T[source][to_node].dist == INT_MAX)
                {
                    // No path found
                    cout << "---" << endl;
                }
                else
                {
                    // Path found
                    cout << T[source][to_node].dist;
                    cout.width();
                    cout << "    ";
                    printPath(source, to_node); // call print path to output the path
                    cout << to_node << endl;
                }
            }
        }
    }
    cout << endl;
}

void GraphM::display(int from_node, int to_node)
{
    if (T[from_node][to_node].dist == INT_MAX) // no path
    {
        cout << setw(5) << from_node << setw(5) << to_node << setw(10) << "---" << endl;
    }
    else
    {
        cout << setw(5) << from_node << setw(5) << to_node << setw(10) << T[from_node][to_node].dist << setw(10);
        printPath(from_node, to_node);
        cout << to_node << endl; // Print the destination node
        printName(from_node, to_node);
    }
}

void GraphM::printName(int from_node, int to_node)
{
    if (T[from_node][to_node].path != 0) // while there is a path
    {
        printName(from_node, T[from_node][to_node].path); // reucrisvly call
        cout << data[to_node] << endl;          // output each name in path
    }
    else
    {
        cout << data[from_node] << endl; // print from node (source)
    }
}

void GraphM::printPath(int from_node, int to_node)
{
    if (T[from_node][to_node].path != 0) // if there is a path
    {
        printPath(from_node, T[from_node][to_node].path); // recursivly diospaly the path
        cout << T[from_node][to_node].path << " ";        // print each path
    }
}
