#include "orderedTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* constructor which sets pos equal to the pos of the
 * unordered table. copies the unordered table and
 * sorts it, so it becomes ordered */
orderedTable::orderedTable(unorderedTable UnTable) {
    pos = UnTable.getPos();
    table = copyTable(UnTable);
    table = Sort();
}

/* dynamically sets the size of the table based on the
 * size of the unordered table and copies each element
 * of the unordered to the ordered table */
Pair** orderedTable::copyTable(unorderedTable unTable) {
    table = (Pair**) malloc(getPos() * sizeof (Pair*));
    for (long int i = 0; i < unTable.getPos(); i++)
        table[i] = unTable.get(i);

    return table;
}

/* implementation of selection sort based on the token of
 * every pair included in the table
 * TO BE CHANGED TO QUICK SORT */
Pair** orderedTable::Sort() {
    long int i, j, min_idx, n = getPos();
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(table[j]->getToken(), table[min_idx]->getToken()) < 0) min_idx = j;

        Pair *temp = table[min_idx];
        table[min_idx] = table[i];
        table[i] = temp;
    }

    return table;
}

/* binary search based on the token string using
 * as a key the token is gotten via the parameters*/
bool orderedTable::findPair(char *token, long int &pos) {
    long int l = 0, r = getPos() - 1;
    while (l <= r) {
        long int m = l + (r - l) / 2;

        if (!strcmp(table[m]->getToken(), token)) {
            pos = m;
            return true;
        }
        if (strcmp(table[m]->getToken(), token) < 0) l = m + 1;
        else r = m - 1;
    }

    pos = -1;
    return false;
}

/* GETTERS */
long int orderedTable::getPos() {return pos;}
Pair* orderedTable::get(long int i) {return table[i];}