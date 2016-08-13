#ifndef COVER_H
#define COVER_H

#include "set.h"


/* subsets identified by a key struct */
typedef struct KSet_ {

    void  *key;
    Set   set;

} KSet;

/***************************************
*             Public API               *
***************************************/
int cover(Set *members, Set *subsets, Set *covering);

#endif
