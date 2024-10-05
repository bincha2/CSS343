#include "TransposeList.h"

bool TransposeList::contains(int anEntry)
{
    DListNode *curr = dummy_header->next;

    while (curr != dummy_header) 
    {
        traverseCount++; // Increment traverse count
        
        if (curr->item == anEntry) 
        {
            if (curr != dummy_header->next) 
            {
                // Swap curr with its previous node
                DListNode* prev_node = curr->prev;

                // Re-link the nodes to swap curr with prev_node
                prev_node->next = curr->next;
                if (curr->next != dummy_header) 
                { // Check if not the dummy header
                    curr->next->prev = prev_node;
                }

                curr->next = prev_node;
                curr->prev = prev_node->prev;

                if (prev_node->prev != dummy_header) 
                {
                    prev_node->prev->next = curr; 
                }
                prev_node->prev = curr;
                prev_node->next = curr->next;

                if (curr == dummy_header->next) 
                {
                    dummy_header->next = prev_node; 
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
}