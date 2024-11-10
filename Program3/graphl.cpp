#include "graphl.h"

// default constructor
GraphL::GraphL()
{
    size = 0; // initialize size to 0

    // initialize node array to nullptr
    for (int i = 1; i <= MAXNODES; i++)
    {
        nodeArray[i] = nullptr;
    }
}

// destructor
GraphL::~GraphL()
{
    // for each node in the array deallocate all of its memory
    for (int i = 1; i <= size; i++)
    {
        if (nodeArray[i] != nullptr)
        {
            // for each edge in the adjacency list deallocate it
            EdgeNode *curr = nodeArray[i]->edgeHead;
            while (curr)
            {
                EdgeNode *next = curr->nextEdge;
                delete curr;
                curr = next;
            }
            // delete the array
            delete nodeArray[i];
        }
    }
}

int GraphL::buildGraph(ifstream &file)
{
    int from_node;
    int to_node;

    if (!(file >> size) || size > MAXNODES) // read in size && check for errors
    {
        return -1;
    }

    string name;
    getline(file, name);

    // since theres N (size) nodes, theres N names, similar to buildgraph in djikstras & since we have a struct, modify the data members for each node in the array
    for (int i = 1; i <= size; i++)
    {
        getline(file, name);
        nodeArray[i] = new GraphNode();
        nodeArray[i]->data = name;
        nodeArray[i]->edgeHead = nullptr;
        nodeArray[i]->visited = false;
    }

    while (file >> from_node >> to_node)
    {
        if (from_node == 0) // if first int is 0 then signals end of graph
        {
            break;
        }
        else
        {
            // add the edge to the adjacency list of the from_node
            EdgeNode *newEdge = new EdgeNode();
            newEdge->adjGraphNode = to_node;
            newEdge->nextEdge = nodeArray[from_node]->edgeHead;
            nodeArray[from_node]->edgeHead = newEdge;
        }
    }
    return 1; // succesa
}

void GraphL::displayGraph()
{
    cout << "Graph:" << endl;

    for (int i = 1; i <= size; i++)
    {
        cout << "Node " << i << setw(25) << nodeArray[i]->data << endl;

        EdgeNode *curr = nodeArray[i]->edgeHead;
        while (curr)
        {
            cout << "  edge \t" << i << " " << curr->adjGraphNode << endl;
            curr = curr->nextEdge;
        }
        cout << endl;
    }
}

void GraphL::depthFirstSearch()
{
    cout << "Depth-first Ordering : ";

    // initalize the array visited to false for each node
    for (int i = 1; i <= size; i++)
    {
        nodeArray[i]->visited = false;
    }

    stack<int> nodeStack; // create a stack like the iterative dfs (in-class)

    // iterate thorugh the node array, if not visited, push, repeat, till all nodes are visited & stack is empty
    for (int i = 1; i <= size; i++)
    {
        if (!nodeArray[i]->visited) // not visited, push
        {
            nodeStack.push(i);

            while (!nodeStack.empty()) // while we have stuff in the stack
            {
                int current_node = nodeStack.top();
                nodeStack.pop();

                if (!nodeArray[current_node]->visited) // add to the DFS display
                {
                    cout << current_node << " ";
                    nodeArray[current_node]->visited = true; // mark it as visited

                    // push adj nodes in reverse order
                    EdgeNode *curr = nodeArray[current_node]->edgeHead;
                    stack<int> tempStack; // temporary stack to hold the adj nodes
                    while (curr != nullptr)
                    {
                        if (!nodeArray[curr->adjGraphNode]->visited)
                        {
                            tempStack.push(curr->adjGraphNode);
                        }
                        curr = curr->nextEdge;
                    }
                    // push from tempStack to nodeStack to reverse the order
                    while (!tempStack.empty())
                    {
                        nodeStack.push(tempStack.top());
                        tempStack.pop();
                    }
                }
            }
        }
    }
    cout << endl;
}