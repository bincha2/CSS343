#include "BinTree.h"

BinTree::BinTree()
{
    root = nullptr; // def construct, empty tree
}

BinTree::BinTree(const BinTree &tree)
{
    root = nullptr;
    recursiveCopy(tree.root, root);
}

BinTree::~BinTree()
{
    recursiveDestroy(root); // call recursive destroy to properly deallocate memory
}

bool BinTree::isEmpty() const
{
    return (root == nullptr); // check if tree root is nullptr
}

bool BinTree::insert(const string &string)
{
    return (recursiveInsert(root, string)); // recursively insert the string into the proper location
}

bool BinTree::retrieve(const string &string, Node *&node)
{
    bool found = recursiveRetrieve(root, string, node);
    if (!found)
    {
        node = nullptr; // set node to null if not found
    }
    return found;
}

int BinTree::getHeight(const string &string) const
{
    return (recursiveGetHeight(root, string)); // get height of a node starting from leaf (=1)
}

BinTree &BinTree::operator=(const BinTree &tree)
{
    if (this != &tree) // check to see if tree is same
    {
        recursiveDestroy(root); // delete existing nodes
        root = nullptr;
        recursiveCopy(tree.root, root);
    }
    return *this;
}

bool BinTree::operator==(const BinTree &tree) const
{
    return (recursiveCompare(root, tree.root)); // recursive compare checks to see if both the Data AND Structure is the same
}

bool BinTree::operator!=(const BinTree &tree) const
{
    return (!(*this == tree));
}

bool BinTree::recursiveInsert(Node *&curr, const string &string)
{
    // if tree is empty or is new node, make root and left right child is null
    if (curr == nullptr)
    {
        curr = new Node;
        curr->data = string;
        curr->left = nullptr;
        curr->right = nullptr;
        return true;
    }

    // see if the string is num first
    stringstream ss(string); // store string data in stringstream obj
    double num;
    if (ss >> num) // extract stringstream obj into double num
    {
        double curr_num = stod(curr->data);
        if (num < curr_num) // insert left
        {
            return (recursiveInsert(curr->left, string));
        }
        else if (num > curr_num) // insert right
        {
            return (recursiveInsert(curr->right, string));
        }
        else // discard the data if it already exists in the tree
        {
            return false;
        }
    }
    else // compare normally as strings and insert
    {
        if (string < curr->data) // insert left
        {
            return (recursiveInsert(curr->left, string));
        }
        else if (string > curr->data) // insert right
        {
            return (recursiveInsert(curr->right, string));
        }
        else // discard the data if it already exists in the tree
        {
            return false;
        }
    }
}

bool BinTree::recursiveRetrieve(Node *curr, const string &string, Node *&node)
{
    if (curr == nullptr) // tree is empty or object is not found
    {
        return false;
    }

    if (curr->data == string) // if object is found
    {
        node = curr; // points to the actual node the string is in
        return true;
    }

    if (string < curr->data) // search left
    {
        return recursiveRetrieve(curr->left, string, node);
    }
    else // search right
    {
        return recursiveRetrieve(curr->right, string, node);
    }
}

int BinTree::recursiveGetHeight(Node *curr, const string &string) const
{
    if (curr == nullptr)
    {
        return 0;
    }

    if (curr->data == string) // found
    {
        return getHeightHelper(curr);
    }

    int leftHeight = recursiveGetHeight(curr->left, string);
    if (leftHeight > 0)
    {
        return leftHeight;
    }

    int rightHeight = recursiveGetHeight(curr->right, string);
    if (rightHeight > 0)
    {
        return rightHeight;
    }

    return 0;
}

int BinTree::getHeightHelper(Node *curr) const
{
    if (curr == nullptr)
    {
        return 0;
    }

    int leftHeight = getHeightHelper(curr->left);
    int rightHeight = getHeightHelper(curr->right);

    if (curr->left == nullptr && curr->right == nullptr)
    {
        return 1;
    }

    return 1 + max(leftHeight, rightHeight);
}

// display functions

ostream &operator<<(ostream &out, const BinTree &tree)
{
    tree.recursiveInorder(tree.root, out); // call recursive inorder , store in out obj
    return out;
}

void BinTree::displayTree() const
{
    recursiveDisplayTree(root, "");
}

void BinTree::displaySideways() const
{
    recursiveDisplaySideways(root, 0);
}

void BinTree::recursiveInorder(Node *curr, ostream &out) const
{
    if (curr != nullptr) // while not null
    {
        recursiveInorder(curr->left, out);  // left
        out << curr->data << " ";           // root
        recursiveInorder(curr->right, out); // right
    }
}

void BinTree::recursiveDisplayTree(Node *curr, string indent) const
{
    if (indent == "")
    {
        cout << "Root: " << curr->data << endl;
        recursiveDisplayTree(curr, "    ");
    }
    else
    {
        if (curr->left != nullptr)
        {
            cout << indent << "L---" << curr->left->data << endl;
            recursiveDisplayTree(curr->left, indent + "    "); // left
        }
        if (curr->right != nullptr)
        {
            cout << indent << "R---" << curr->right->data << endl;
            recursiveDisplayTree(curr->right, indent + "    "); // right
        }
    }
}

void BinTree::recursiveDisplaySideways(Node *curr, int space) const
{
    // Base case
    if (curr == nullptr)
        return;

    // Increase distance between levels
    const int COUNT = 5; // You can adjust this value as needed
    space += COUNT;

    // Process right child first
    recursiveDisplaySideways(curr->right, space);

    // Print current node after space count
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << curr->data << "\n";

    // Process left child
    recursiveDisplaySideways(curr->left, space);
}

// array bstree functions
void BinTree::bstreeToArray(string arr[ARRAYSIZE])
{
    int index = 1;
    recursiveBSTreeToArray(root, arr, index);
    recursiveDestroy(root); // leave the tree empty after
}

void BinTree::arrayToBSTree(string arr[ARRAYSIZE])
{
    recursiveArrayToBSTree(arr, 1, num_of_elements, root);
}

void BinTree::recursiveBSTreeToArray(Node *curr, string arr[], int &index)
{
    if (index >= ARRAYSIZE)
    {
        cerr << "Array cannot exceed Maximum ARRAYSIZE = 100" << endl;
    }
    if (curr != nullptr) // while not null
    {
        // inorder L root R
        recursiveBSTreeToArray(curr->left, arr, index);
        arr[index] = curr->data;
        index++;
        num_of_elements++; // keep track of the num of elemtns in array to use later in arr to bstree
        recursiveBSTreeToArray(curr->right, arr, index);
    }
}

void BinTree::recursiveArrayToBSTree(string arr[], int low, int high, Node *&new_node) // the high is num of elements
{
    if (high < low)
    {
        new_node = nullptr;
        return;
    }

    if (high == low) // single element, create a leaf node
    {
        new_node = new Node();
        new_node->data = arr[low];
        new_node->left = nullptr;
        new_node->right = nullptr;
        return;
    }

    int middle = (low + high) / 2; // recursive root

    new_node = new Node();
    new_node->data = arr[middle];
    arr[middle] = ""; // fill with empty string instead of null since its of type string

    recursiveArrayToBSTree(arr, low, middle - 1, new_node->left);   // left subtree
    recursiveArrayToBSTree(arr, middle + 1, high, new_node->right); // right subtree
}

void BinTree::recursiveCopy(const Node *curr, Node *&new_node)
{
    if (curr == nullptr)
    {
        new_node = nullptr;
    }
    else
    {
        new_node = new Node();
        new_node->data = std::string(curr->data); // create a new copy of the data
        recursiveCopy(curr->left, new_node->left);
        recursiveCopy(curr->right, new_node->right);
    }
}

bool BinTree::recursiveCompare(const Node *curr, const Node *rhs) const
{
    if (curr == nullptr && rhs == nullptr) // tree is empty
    {
        return true;
    }
    else if (curr == nullptr || rhs == nullptr) // the trees arnt the same structure so false
    {
        return false;
    }
    else // continue searching entire tree until true or false is reached
    {
        return (curr->data == rhs->data) && recursiveCompare(curr->left, rhs->left) && recursiveCompare(curr->right, rhs->right);
    }
}

void BinTree::recursiveDestroy(Node *curr)
{
    if (curr != nullptr)
    {
        recursiveDestroy(curr->left);  // destroy left subtree
        recursiveDestroy(curr->right); // destroy right subtree
        delete curr;                   // always delete the node
    }
}