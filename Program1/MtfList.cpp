#include "MtfList.h"

bool MtfList::contains(int anEntry)
{
    DListNode *curr = dummy_header->next;

    while (curr != dummy_header) 
    {
        traverseCount++; 
        
        if (curr->item == anEntry) 
        {
            if (curr != dummy_header->next) 
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->next = dummy_header->next;
                curr->prev = dummy_header;
                dummy_header->next->prev = curr;
                dummy_header->next = curr;
            }
            return true; 
        } 
        else 
        {
            curr = curr->next;
        }
    }
    return false;
}