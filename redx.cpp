#include <iostream>
#include <immintrin.h>
#include "node.h"

#define ROTATE16 16


#define XOR128(a, b) _mm_xor_si128(a, b)
#define AND128(a, b) _mm_and_si128(a, b)
#define ROT32(x) _mm256_shuffle_epi32((x), _mm_shuffle(2, 3, 0, 1))

#define STORE128(p,r) _mm_store_si128((__m128i *)(p), r)

#define ADD128(x,y)        _mm_add_epi64(x,y)
#define SUB128(x,y)        _mm_sub_epi64(x,y)
#define MUL128(x,y)        _mm_mul_epi32(x,y)
#define MOD128(x, y)       _mm_mullo_epi32(x, y )
#define ROT16(x)          _mm_alignr_epi8(x, x, 16)


#define LENGTH 64

bintree_t tree;

__m128i T;

void write(int len) {
 nodexpand(&tree);

 for(int i = 0; i < len ; i++) {

     /*Put T as r + p words (aligned)*/
     nodeput(&tree, ROT16(LOAD128(&T) * 0xff), i);
     arth0x(&tree, i );

 }
}

void red0x(){

    __m128i B, N, NX, R, T;
    __m128i ones = _mm_set1_epi64x((uint64_t)1 >> 63);
    uint8_t r, p = 1;

    /*B & N  = B % N */
    N = MOD128(B, N);

    /*-1 mod b =  b - 1*/
    NX = SUB128(B, ones);

    R = MUL128(B, ones);
    T = SUB128(MUL128(R , N), ones);
    LOAD128(&T);
    /* T in the range 0 ≤ T < RN, stored as an array of r + p words. */
    write(r + p);




}


int main(){
 red0x();

}
