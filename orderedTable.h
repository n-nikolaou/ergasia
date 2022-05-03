#ifndef PROJECTDOMWN_ORDEREDTABLE_H
#define PROJECTDOMWN_ORDEREDTABLE_H


#include "Pair.h"
#include "unorderedTable.h"

class orderedTable {
protected:
    Pair **table;
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
