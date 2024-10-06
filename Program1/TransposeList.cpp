#include "TransposeList.h"

bool TransposeList::contains(int anEntry)
{
    DListNode *curr = dummy_header->next;

    while (curr != dummy_header) 
    {
        traverseCount++;
        
        if (curr->item == anEntry) 
        {
            if (curr != dummy_header->next) 
            {
                DListNode *prev_node = curr->prev;

                prev_node->next = curr->next;
                curr->next->prev = prev_node;

                curr->next = prev_node;
                curr->prev = prev_node->prev;
                prev_node->prev->next = curr;
                prev_node->prev = curr;

                if (prev_node == dummy_header->next) 
                {
                    dummy_header->next = curr; 
                }
            }
            return true; 
        }
        curr = curr->next;
    }
    return false; 
}