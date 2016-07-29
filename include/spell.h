#ifndef SPELL_H
#define SPELL_H


/* maximum size for words in the dictionary */
#define            SPELL_SIZE           31


/***************************************
*             Public API               *
***************************************/
int spell(char (*dictionary)[SPELL_SIZE], int size, const char *word);

#endif
