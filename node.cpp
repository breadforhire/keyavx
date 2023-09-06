#include "stdint.h"
#include <stdlib.h>

typedef struct
{
    uint32_t prod;
    uint32_t low;
    uint32_t high;
    uint32_t complete;
    int left_id;
    int right_id;
} bintree_element_t;

typedef struct
{
    bintree_element_t* nodes;
    uint32_t size;
    uint32_t alloc;
    ssize_t signal;
} bintree_t;



uint32_t nodexpand(bintree_t* tree) {
    uint32_t nodeid = 0;
    bintree_element_t* node = &tree->nodes[nodeid];

    if (tree -> size == tree -> alloc){
       tree->alloc *=2;
       node = (bintree_element_t *)realloc(node, tree-> alloc);

    }

    if (tree -> size <= tree ->alloc){
       tree->alloc *=1;

 

 }

}
