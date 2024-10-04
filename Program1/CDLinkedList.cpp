#include "CDLinkedList.h"

CDLinkedList::CDLinkedList() //default
{
    dummy_header = new DListNode();
    dummy_header->next = dummy_header;
    dummy_header->prev = dummy_header;
}

CDLinkedList::CDLinkedList(const CDLinkedList &rhs) //copy
{
    DListNode *current = rhs.dummy_header->next;
    while (current)
}

CDLinkedList::~CDLinkedList() //destructor
{

}

int CDLinkedList::getCurrentSize() const
{

}

bool CDLinkedList::isEmpty() const
{

}

bool CDLinkedList::add(int newEntry)
{

}

bool CDLinkedList::remove(int anEntry)
{

}

void CDLinkedList::clear()
{

}

virtual bool CDLinkedList::contains(int anEntry)
{

}

int CDLinkedList::getTraverseCount() const
{

}

int CDLinkedList::retrieve(const int index)
{

}

void CDLinkedList::resetTraverseCount()
{

}