//
// Created by nickn on 30/4/2022.
//

#ifndef PROJECTDOMWN_UNORDEREDTABLE_H
#define PROJECTDOMWN_UNORDEREDTABLE_H

#include "Pair.h"

/* EXPLANATION FOR EACH FUNCTION CAN BE FOUND
 * AT THE IMPLEMENTATION (unorderedTable.cpp) */

class unorderedTable {
protected:
    /* table of pointers, pointing to Pairs
     * size of the table changes dynamically every time
     * a new token string gets allocated */
    Pair **table;
    /* pointing at the very next empty cell of the table */
    long int pos;

public:
    unorderedTable();

    bool findPair(char*, long int &);
    void add(char*);
    void increase(long int);
    void decrease(long int);

    int getPos();
    Pair* get(long int);
};


#endif //PROJECTDOMWN_UNORDEREDTABLE_H
