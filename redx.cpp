#include <iostream>
#include <immintrin.h>


#define xor128(a, b) _mm_xor_si128(a, b)
#define and128(a, b) _mm_and_si128(a, b)
#define rot32(x) _mm256_shuffle_epi32((x), _mm_shuffle(2, 3, 0, 1))

#define load128(p)  _mm_load_si128( (__m128i *)(p) )
#define store128(p,r) _mm_store_si128((__m128i *)(p), r)

#define add128(x,y)        _mm_add_epi64(x,y)
#define sub128(x,y)        _mm_sub_epi64(x,y)
#define mul128(x,y)        _mm_mul_epi32(x,y)

#define length 64

void red0x(){
    __m128i b, n, nx, r, t;
    __m128i ones = _mm_set1_epi64x((uint64_t)1 >> 63);

    n = and128(b, n);
    store128(&b, n);
    nx = sub128(b, ones);

    /*b^r writing one word to heap*/
    r = mul128(b, ones  );



}
