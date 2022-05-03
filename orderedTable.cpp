#include "orderedTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
orderedTable::orderedTable(unorderedTable UnTable) {
    pos = UnTable.getPos();
    table = copyTable(UnTable);
    table = Sort();
}

Pair** orderedTable::copyTable(unorderedTable unTable) {
    table = (Pair**) malloc(getPos() * sizeof (Pair*));
    for (long int i = 0; i < unTable.getPos(); i++)
        table[i] = unTable.get(i);
    return table;
}

Pair** orderedTable::Sort() {
    long int i, j, min_idx, n = getPos();
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(table[j]->getToken(), table[min_idx]->getToken()) < 0)
                min_idx = j;

        // Swap the found minimum element with the first element
        Pair *temp = table[min_idx];
        table[min_idx] = table[i];
        table[i] = temp;
    }

    return table;
}

bool orderedTable::findPair(char *token, long int &pos) {
    long int l = 0, r = getPos() - 1;
    while (l <= r) {
        long int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (!strcmp(table[m]->getToken(), token)) {
            pos = m;
            return true;
        }

        // If x greater, ignore left half
        if (strcmp(table[m]->getToken(), token) < 0)
            l = m + 1;

            // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    pos = -1;
    return false;
}

long int orderedTable::getPos() {return pos;}
Pair* orderedTable::get(long int i) {return table[i];}