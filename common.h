#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Field{
    unsigned index;
    char * name;
    char * type;
    unsigned addr;
    unsigned lineno;
    char * elementType;
    unsigned level;
}field;

typedef struct Table{
    const unsigned addrMax;
    const unsigned indexMax;
    unsigned levelNum;
    unsigned addrNum;
    unsigned indexNum[16];

    field tf[16][256];
}table;
#endif /* COMMON_H */
