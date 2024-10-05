//MTFList Class, if list contains item, moves target node to front

#ifndef MTFLIST_H_
#define MTFLIST_H_
#include "CDLinkedList.h"

class MTFList : public CDLinkedList
{
public:
    virtual bool contains(int anEntry) override;

};
#endif