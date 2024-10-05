#include "CDLinkedList.h"

//default constructor
CDLinkedList::CDLinkedList() 
{
    //both next and prev point to the dummy header in a default CD Linked list
    dummy_header = new DListNode();
    dummy_header->next = dummy_header;
    dummy_header->prev = dummy_header;
    traverseCount = 0;
}

//copy constructor
CDLinkedList::CDLinkedList(const CDLinkedList &rhs)
{
    //list #2
    dummy_header = new DListNode();
    dummy_header->next = dummy_header;
    dummy_header->prev = dummy_header;

    //curr points to first real node in rhs
    DListNode *curr = rhs.dummy_header->next; 

    while (curr != rhs.dummy_header) 
    {
        add(curr->item);
        curr = curr->next;
    }
}

//destructor
CDLinkedList::~CDLinkedList()
{
    clear();
    delete dummy_header;
}

int CDLinkedList::getCurrentSize() const
{
    int size = 0;
    DListNode *curr = dummy_header->next;
    while (curr != dummy_header)
    {
        size++;
        curr = curr->next;
    }
    return size;
}

bool CDLinkedList::isEmpty() const
{
    return (dummy_header == dummy_header->next);
}

bool CDLinkedList::add(int newEntry)
{
    //use contains method to check if item already exists in the list
    if (contains(newEntry))
    {
        return false;
    }
    else
    {
        DListNode *insert_node = new DListNode();
        insert_node->item = newEntry;

        DListNode *first_node = dummy_header->next; //first node in list

        //set insert node at front
        insert_node->next = first_node; 
        insert_node->prev = dummy_header;
        first_node->prev = insert_node;
        dummy_header->next = insert_node;

        return true;
    }
}

bool CDLinkedList::remove(int anEntry)
{
    //use contains method to check if item exists in list
    if (!contains(anEntry))
    {
        return false;
    }
    else
    {
        DListNode *curr = dummy_header->next; 
        resetTraverseCount();

        //traverse list to find anEntry, while updating traverse count
        while (curr != dummy_header)
        {
            traverseCount++;
            if (curr->item == anEntry)
            {
                //properly relink pointers, a<->b<->c ==> a<->c and deallocate memory
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                return true;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
}

void CDLinkedList::clear()
{
    DListNode *curr = dummy_header->next;

    //empty list
    while (curr != dummy_header)
    {
        DListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    dummy_header->next = dummy_header;
    dummy_header->prev = dummy_header;
}

virtual bool CDLinkedList::contains(int anEntry)
{
    DListNode *curr = dummy_header->next;

    while (curr != dummy_header)
    {
        traverseCount++;
        if (curr->item == anEntry)
        {
            return true;
        }
        else
        {
            curr = curr->next;
        }
    }
    //does not contain anEntry
    return false;
}

int CDLinkedList::getTraverseCount() const
{
    return traverseCount;
}

int CDLinkedList::retrieve(const int index)
{
    //check if valid index
    if (index < 0 || index >= getCurrentSize())
    {
        cerr << "Invalid Index" << endl;
    }
    else
    {
        resetTraverseCount();
        DListNode *curr = dummy_header->next;
        curr_index = 0;

        while (curr_index < index)
        {
            traverseCount++;
            curr_index++;
            curr = curr->next;
        }
        
        return curr->item;
    }
}

void CDLinkedList::resetTraverseCount()
{
    traverseCount = 0;
}
