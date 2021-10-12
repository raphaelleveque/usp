#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <math.h>

typedef struct sample{
    double complex complexNum;
    int magnitude;
    int index;
} sample_t;

typedef struct data{
    unsigned char* data;
    int dataSize;
} data_t;


data_t read_wav_data(char* fname);
sample_t *DFT(data_t wavData);
void insertionSort(sample_t *coef, int tam, int coefficient);
void reverseDFT(sample_t *coef, data_t wavData);
void newWav(sample_t *coef, data_t wavData, char* fname);