//
// Created by nickn on 30/4/2022.
//

#include "Pair.h"
#include <string.h>

/* constructor. there's no default constructor */
Pair::Pair(int count, char *token)
{
    this->count = count;
    strcpy(this->token, token);
}

/* increase the appearance count of a given token string */
void Pair::increase() {count++;}

/* decrease the appearance count of a given token string. ONLY USED
 * FOR THE LAST PAIR INPUT IN THE TABLE */
bool Pair::decrease()
{
    count--;
    return count != 0;
}

/* GETTERS */
int Pair::getCount() {return count;}
char* Pair::getToken() {return token;}