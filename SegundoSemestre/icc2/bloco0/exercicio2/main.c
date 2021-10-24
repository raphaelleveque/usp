// Raphael Leveque 12542522
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int row;
    int column;
} Coord_t;

// This struct saves the current coordinates, because they are lost in my tree function
typedef struct {
    Coord_t realFirst;
    Coord_t realLast;
} RealCoord_t;

typedef struct Image{
    int rows;
    int columns;
    int **matrix;
} Image_t;

// This recursive function divides the matrix into 4 equal parts
// It locates the current quadrant index, with its beginning and its end
// Then, if there are different numbers in the quadrant, the function is recursively called
void tree(Coord_t first, Coord_t last, Image_t image, RealCoord_t realCoord){
    RealCoord_t temp = realCoord;
    int quadrantLength = (last.row - first.row + 1) / 2.0;
    for (int i = 0; i < 4; ++i) {
        if (i == 0){
            first.row = realCoord.realFirst.row;
            first.column = realCoord.realFirst.column;
        }
        else if (i == 1){
            first.row = realCoord.realFirst.row;
            first.column = realCoord.realFirst.column + quadrantLength;
        }
        else if (i == 2){
            first.row = realCoord.realFirst.row + quadrantLength;
            first.column = realCoord.realFirst.column;
        }
        else{
            first.row = realCoord.realFirst.row + quadrantLength;
            first.column = realCoord.realFirst.column + quadrantLength;
        }
        last.row = first.row + quadrantLength - 1;
        last.column = first.column + quadrantLength - 1;


        bool equalNum = true;
        int tmp = image.matrix[first.row][first.column];

        for (int j = first.row; j <= last.row; ++j) {
            for (int k = first.column; k <= last.column; ++k) {
                if (image.matrix[j][k] != tmp) {
                    equalNum = false;
                    break;
                }
            }
            if (!equalNum) break;
        }

        if (!equalNum){
            printf("-1 ");
            realCoord.realFirst = first;
            realCoord.realLast = last;
            tree(first, last, image, realCoord);
            realCoord = temp;
        }
        else
            printf("%d ", image.matrix[first.row][first.column]);
    }
}

int main(){
    Image_t image;
    scanf("%d%d", &image.rows, &image.columns);

    image.matrix = malloc(image.rows * sizeof(int *));
    for (int i = 0; i < image.rows; ++i)
        image.matrix[i] = malloc(image.columns * sizeof(int));


    for (int i = 0; i < image.rows; ++i)
        for (int j = 0; j < image.columns; ++j)
            scanf("%d", &image.matrix[i][j]);


    Coord_t first;
    first.row = 0;
    first.column = 0;

    Coord_t last;
    last.row = image.rows - 1;
    last.column = image.columns - 1;

    RealCoord_t realCoord;
    realCoord.realFirst = first;
    realCoord.realLast = last;

    printf("-1 ");
    tree(first, last, image, realCoord);

    for (int i = 0; i < image.rows; ++i)
        free(image.matrix[i]);
    free(image.matrix);

    return 0;
}