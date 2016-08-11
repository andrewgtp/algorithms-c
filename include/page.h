#ifndef PAGE_H
#define PAGE_H

#include "clist.h"

/* information about pages structure */
typedef struct Page_ {

    int                number;
    int                reference;

} Page;

/***************************************
*             Public API               *
***************************************/
int replace_page(CListElmt **current);

#endif
