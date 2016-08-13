#ifndef DIRECTLS_H
#define DIRECTLS_H

#include <dirent.h>


/* directory entries structure */
typedef struct Directory_ {

    char               name[MAXNAMLEN + 1];

} Directory;


/***************************************
*             Public API               *
***************************************/
int directls(const char *path, Directory **dir);

#endif
