// Raphael Leveque
// NUsp: 12542522
// SCC0201

#include "audio.h"

int main(){
    char name[20] = {};
    scanf("%s", name);

    int coefficient;
    scanf("%d ", &coefficient);

    data_t wavData = read_wav_data(name);
    printf("%d\n", wavData.dataSize);

    sample_t *coef = DFT(wavData);
    insertionSort(coef, wavData.dataSize, coefficient);
    reverseDFT(coef, wavData);

    newWav(coef, wavData, name);

    free(coef);
    free(wavData.data);
    return 0;
}
