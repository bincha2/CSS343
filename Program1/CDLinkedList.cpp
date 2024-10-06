#include "CDLinkedList.h"

//default constructor
CDLinkedList::CDLinkedList() 
{
    //both next and prev point to the dummy header in a default CD Linked list
    dummy_header = new DListNode();
    dummy_header->next = dummy_header;
    dummy_header->prev = dummy_header;
}

//copy constructor
CDLinkedList::CDLinkedList(const CDLinkedList &rhs)
{
    //list #2
    dummy_header = new DListNode();
    dummy_header->next = dummy_header;
    dummy_header->prev = dummy_header;

    //curr points to last real node in rhs, since Add inserts new to front, we want to reverse in copy cc to have same list
    DListNode *curr = rhs.dummy_header->prev; 

    while (curr != rhs.dummy_header) 
    {
        add(curr->item);
        curr = curr->prev;
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
    if (contains(newEntry))
    {
        return false;
    }
    else
    {
        DListNode *insert_node = new DListNode();
        insert_node->item = newEntry;

        insert_node->next = dummy_header->next;
        insert_node->prev = dummy_header;
        dummy_header->next->prev = insert_node;
        dummy_header->next = insert_node;

        return true;
    }
}

bool CDLinkedList::remove(int anEntry)
{
    DListNode *curr = dummy_header->next; 

    while (curr != dummy_header)
    {
        traverseCount++;
        if (curr->item == anEntry)
        {
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
    return false;
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

bool CDLinkedList::contains(int anEntry)
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
    if (index < 0 || index >= getCurrentSize())
    {
        cerr << "Invalid Index" << endl;
        return -1;
    }
    else
    {
        DListNode *curr = dummy_header->next;
        int curr_index = 0;

        while (curr_index < index)
        {
            traverseCount++;
            curr_index++;
            curr = curr->next;
        }
        traverseCount++;
        return curr->item;
    }
}
void CDLinkedList::resetTraverseCount()
{
    traverseCount = 0;
}

