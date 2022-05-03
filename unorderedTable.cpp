#include "unorderedTable.h"
#include <stdlib.h>
#include <string.h>

/* default constructor. there's no overloaded constructors */
unorderedTable::unorderedTable() {
    pos = 0;
    table = nullptr;
}

/* linear search in given unordered table to find a pair using
 * as a key the token string.
 * return true or false if the pair exists in table, and the position
 * of itself in the pos parameter (if not found pos = -1) */
bool unorderedTable::findPair(char* key, long int &pos) {
    int i = 0;
    while (i < this->pos)
    {
        if (strcmp(key, table[i]->getToken()) == 0)
        {
            pos = i;
            return true;
        }
        i++;
    }
    pos = -1;
    return false;
}

/* adds a pointer to a pair in the table when the token string doesnt exist
 * in the table */
void unorderedTable::add(char *token) {
    table = (Pair**) realloc(table, (pos + 1) * sizeof (Pair*));
    table[pos] = new Pair(1, token);
    pos++;
}

/* increases the count appearance of string token of a pair placed
 * at table[pos] */
void unorderedTable::increase(long int pos) {table[pos]->increase();}
/* decreases the count appearance of string token of a pair placed
 * at table[pos]. if the count appearance of given token string becomes
 * zero we wipe it off the table. USED ONLY FOR THE LAST PAIR PLACED IN
 * THE TABLE SO THERES NO NEED FOR PLACING THE OTHER ENTRIES A BIT LEFT */
void unorderedTable::decrease(long int pos)
{
    if (!table[pos]->decrease())
    {
        table[pos] = nullptr;
        this->pos--;
    }
}

/* SETTER */
void unorderedTable::setPair(Pair *newPair, long int pos) {
    table[pos] = newPair;
}

/* GETTERS */
long int unorderedTable::getPos() {return pos;}
Pair* unorderedTable::get(long int i) {return table[i];}