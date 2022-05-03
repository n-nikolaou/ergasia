#ifndef PROJECTDOMWN_ORDEREDTABLE_H
#define PROJECTDOMWN_ORDEREDTABLE_H

#include "Pair.h"
#include "unorderedTable.h"

/* EXPLANATION FOR EACH FUNCTION CAN BE FOUND
 * AT THE IMPLEMENTATION (unorderedTable.cpp) */

class orderedTable {
protected:
    /* table of pointers, pointing to Pairs */
    Pair **table;
    /* pointing at the very next empty cell of the table */
    long int pos;

public:
    orderedTable(unorderedTable);

    Pair** copyTable(unorderedTable);
    Pair** Sort();
    bool findPair(char*, long int &);

    long int getPos();
    Pair* get(long int);
};


#endif //PROJECTDOMWN_ORDEREDTABLE_H
