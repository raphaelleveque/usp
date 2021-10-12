#include "audio.h"


// Reads data from the .WAV audio file and creates an array of unsigned char to represent that data
data_t read_wav_data(char *fname) {
    FILE *fp = fopen(fname, "rb");
    unsigned char buf4[4];

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    data_t wavData;
    wavData.dataSize = buf4[0] | buf4[1] << 8 | buf4[2] << 16 | buf4[3] << 24;
    wavData.data = malloc(sizeof(wavData.data) * (wavData.dataSize));

    int i = 0;
    while (i < wavData.dataSize) {
        fread(&wavData.data[i++], sizeof(unsigned char), 1, fp);
    }
    fclose(fp);
    return wavData;
}


// Transforms audio data into complex numbers
// Returns an array of complex numbers, each number's magnitude and its index (will be helpful for later)
sample_t *DFT(data_t wavData) {
    sample_t *coef = (sample_t *)calloc(wavData.dataSize, sizeof(sample_t));
    int negativesAndZeros = 0;

    for (int k = 0; k < wavData.dataSize; k++) {
        for (int n = 0; n < wavData.dataSize; n++) {
            coef[k].complexNum += wavData.data[n] * cexp((-2.0 * M_PI * (((k + 1) * n * 1.0) / (wavData.dataSize * 1.0))) * _Complex_I);
        }
        coef[k].index = k;
        coef[k].magnitude = sqrt(pow(creal(coef[k].complexNum), 2) + pow(cimag(coef[k].complexNum), 2));
        if(creal(coef[k].complexNum) <= 0 && cimag(coef[k].complexNum) <= 0) negativesAndZeros++;
    }
    printf("%d\n", negativesAndZeros);
    return coef;
}


// Transforms complex numbers back to audio data
void reverseDFT(sample_t *coef, data_t wavData) {
    for (int k = 0; k < wavData.dataSize; k++) {
        for (int n = 0; n < wavData.dataSize; n++) {
            wavData.data[n] += (1 / wavData.dataSize) * (coef[k].complexNum * cexp((2.0 * M_PI * (((k + 1) * n * 1.0) / (wavData.dataSize * 1.0))) * _Complex_I));
        }
    }
}


// First: insertionSort() sorts by coef's magnitude, calculated in DFT()
// Second: Prints the T(coefficient) biggest numbers and reset the other values
// Third: sorts by each sample_t index, returning to its original index
void insertionSort(sample_t *coef, int length, int coefficient) {
    for (int i = 1; i < length; i++) {
        int key = coef[i].magnitude;
        int j = i;
        while (j > 0 && coef[j - 1].magnitude < key) {
            coef[j].magnitude = coef[j - 1].magnitude;
            j--;
        }
        coef[j].magnitude = key;
    }

    for (int i = 0; i < length; i++) {
        if (i < coefficient)
            printf("%d\n", (int)coef[i].magnitude);
        else {
            coef[i].complexNum = 0;
            coef[i].magnitude = 0;
        }
    }

    for (int i = 1; i < length; i++) {
        int key = coef[i].index;
        int j = i;
        while (j > 0 && coef[j - 1].index > key) {
            coef[j].index = coef[j - 1].index;
            j--;
        }
        coef[j].index = key;
    }
}


// Creates a new audio file, with the compressed audio
void newWav(sample_t *coef, data_t wavData, char* fname){
    FILE *oldFile = fopen(fname, "rb");
    FILE *fp = fopen("newAudio.wav", "wb");
    unsigned char buff[44];
    fread(&buff, sizeof(unsigned char), 44, oldFile);
    fwrite(&buff, sizeof(unsigned char), 44, fp);
    
    int i = 0;
    while (i < wavData.dataSize) {
        fwrite(&wavData.data[i++], sizeof(unsigned char), 1, fp);
    }
    fclose(fp);
    fclose(oldFile);
}