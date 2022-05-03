//
// Created by nickn on 30/4/2022.
//

#ifndef PROJECTDOMWN_PAIR_H
#define PROJECTDOMWN_PAIR_H

/* EXPLANATION FOR EACH FUNCTION CAN BE FOUND
 * AT THE IMPLEMENTATION (Pair.cpp) */

class Pair {
protected:
    /* counts the total appearances of the token strings */
    int count;
    /* token string with max chars set to 50.
     * SUBJECT TO CHANGE IN THE FUTURE */
    char token[50];

public:
    Pair(int, char*);

    void increase();
    bool decrease();

    int getCount();
    char* getToken();

};

#endif //PROJECTDOMWN_PAIR_H
