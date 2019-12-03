
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <smmintrin.h>
#include <immintrin.h>



void add_no_AVX(long size, unsigned short *first_array, const unsigned short *second_array);
void add_AVX(long size, unsigned short *first_array, const unsigned short *second_array);
void add_SSE(long size, unsigned short * a, const unsigned short *b);
void add_AVX2(long size, unsigned short * a, const unsigned short *b);


#define elements 1000

int main() {
  short test[elements];
  short test1[elements];
  for (int i=0;i<elements;i++){
    test[i]=rand();
    test1[i]=rand();
  }
  

  uint64_t adiff;
  
  printf("No AVX - \n");
  uint64_t astsc = __builtin_ia32_rdtsc();
  add_no_AVX(elements,test,test1);
  uint64_t aetsc = __builtin_ia32_rdtsc();
  adiff=aetsc-astsc;
  printf("noAVX : %" PRIu64 "\n",adiff);  
  

  astsc = __builtin_ia32_rdtsc();
  add_AVX(elements,test,test1);
  aetsc = __builtin_ia32_rdtsc();
  adiff=aetsc-astsc;
  printf("AVX : %" PRIu64 "\n",adiff);



  astsc = __builtin_ia32_rdtsc();
  add_SSE(elements,test,test1);
  aetsc = __builtin_ia32_rdtsc();
  adiff=aetsc-astsc;
  printf("SSE : %" PRIu64 "\n",adiff);  


 
  

  
  
  
  return 0;
}

void add_no_AVX(long size, unsigned short *first_array, const unsigned short *second_array) {
  for (int i = 0; i < size; ++i) {
    first_array[i] += second_array[i];
  }
  return;
}


/* reference implementation in C */
void add(long size, unsigned short * a, const unsigned short *b) {
    for (int i = 0; i < size; ++i) {
        a[i] += b[i];
    }
    return;
}

/* vectorized version */
void add_AVX(long size, unsigned short * a, const unsigned short *b) {
    for (int i = 0; i < size; i += 16) {
        /* load 128 bits from a */
        /* a_part = {a[i], a[i+1], a[i+2], ..., a[i+15]} */
        __m256i a_part = _mm256_loadu_si256((__m256i*) &a[i]);
        /* load 128 bits from b */
        /* b_part = {b[i], b[i+1], b[i+2], ..., b[i+15]} */
        __m256i b_part = _mm256_loadu_si256((__m256i*) &b[i]);
        /* a_part = {a[i] + b[i], a[i+1] + b[i+1], ...,
                     a[i+15] + b[i+15]}
         */
        a_part = _mm256_add_epi16(a_part, b_part);
        _mm256_storeu_si256((__m256i*) &a[i], a_part);
    }
    return;
}

/* vectorized version --- 128-bit regiters */
void add_SSE(long size, unsigned short * a, const unsigned short *b) {
    for (int i = 0; i < size; i += 8) {
        /* load 128 bits from a */
        /* a_part = {a[i], a[i+1], a[i+2], ..., a[i+7]} */
        __m128i a_part = _mm_loadu_si128((__m128i*) &a[i]);
        /* load 128 bits from b */
        /* b_part = {b[i], b[i+1], b[i+2], ..., b[i+7]} */
        __m128i b_part = _mm_loadu_si128((__m128i*) &b[i]);
        /* a_part = {a[i] + b[i], a[i+1] + b[i+1], ...,
                     a[i+7] + b[i+7]}
         */
        a_part = _mm_add_epi16(a_part, b_part);
        _mm_storeu_si128((__m128i*) &a[i], a_part);
    }
    return;
}


void add_AVX2(long size, unsigned short * a, const unsigned short *b) {
    for (int i = 0; i < size; i += 32) {
        /* load 512 bits from a */
        /* a_part = {a[i], a[i+1], a[i+2], ..., a[i+7]} */
        __m512i a_part = _mm512_loadu_si512((__m512*) &a[i]);
        /* load 128 bits from b */
        /* b_part = {b[i], b[i+1], b[i+2], ..., b[i+7]} */
        __m512i b_part = _mm512_loadu_si512((__m512i*) &b[i]);
        /* a_part = {a[i] + b[i], a[i+1] + b[i+1], ...,
                     a[i+7] + b[i+7]}
         */
        a_part = _mm512_add_epi16(a_part, b_part);
        _mm512_storeu_si512((__m512i*) &a[i], a_part);
    }
    return;
}
