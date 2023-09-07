#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stdint.h"
#include <immintrin.h>

#define LOAD128(X)         _mm_load_si128((__m128i*) X)
#define LENGTH 64

typedef struct
{

     __m128i complete;
    int left_id;
    int right_id;
} bintree_element_t;

typedef struct
{
    bintree_element_t* nodes;
    uint32_t size;
    uint32_t alloc;
} bintree_t;




void nodexpand(bintree_t* tree ) {
    uint32_t nodeid = 0;
    bintree_element_t* node = &tree->nodes[nodeid];


    if (tree->size == tree->alloc){
       tree->alloc *=2;
       node = (bintree_element_t *)realloc(node, tree->alloc);

    }

}


void nodeput(bintree_t * tree, __m128i val, uint32_t nodeid){
 bintree_element_t* node = &tree->nodes[nodeid];

 node = (bintree_element_t*) malloc(sizeof(val) * 3);
 memcpy(&node->complete, &val, sizeof(val) );

 tree -> size += sizeof(val * 3);
 node -> left_id++;
 node -> right_id++;


}

void arth0x(bintree_t * tree, uint32_t nodeid){


 bintree_element_t* node = &tree->nodes[nodeid];


 for(int i = 0; i < LENGTH; i++  ){
  i++;
  LOAD128(&node[i].complete);
  printf("%llu", &node[i].complete[0]);
 }




}
