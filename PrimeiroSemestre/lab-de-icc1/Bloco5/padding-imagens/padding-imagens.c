#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    scanf("%d %d", &width, &height);

    int **image = calloc(height, sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        image[i] = calloc(width, sizeof(int));
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    int paddingSize;
    scanf("%d", &paddingSize);

    int newHeight = 2 * paddingSize + height;
    int newWidth = 2 * paddingSize + width;


    for (int i = 0; i < newHeight; i++)
    {
        for (int j = 0; j < newWidth; j++)
        {
            if (i < paddingSize || i >= (height + paddingSize))
            {
                printf("0 ");
            }
            else if (j < paddingSize || j >= paddingSize + width)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", image[i - paddingSize][j - paddingSize]);
            }
            
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    
    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);
    

    return 0;
}