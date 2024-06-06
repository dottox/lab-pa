#ifndef LISTITERATOR_H
#define	LISTITERATOR_H

#include "ListNode.h"


class ListIterator: public IIterator {
public:
    ListIterator(ListNode *head, bool disposeHeadOnDelete = false);
    ICollectible *getCurrent();
    bool hasCurrent();
    void next();
    
    virtual ~ListIterator();
private:
    ListNode *head;
    ListNode *current;
    bool disposeHeadOnDelete;
};

#endif	/* LISTITERATOR_H */

