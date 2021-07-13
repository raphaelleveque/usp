#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrixSize;
    scanf("%d", &matrixSize);

    double **existingTypes = malloc(matrixSize * sizeof(double *));
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            if (i == 0)
            {
                existingTypes[j] = malloc(matrixSize * sizeof(double));
            }
            scanf("%lf", &existingTypes[i][j]);
        }
    }

    int **powerAndType = malloc(matrixSize * sizeof(int *));
    for (int i = 0; i < matrixSize; i++)
    {
        powerAndType[i] = malloc(2 * sizeof(int));
    }

    int nAttacks = 0;
    do
    {
        int power;
        scanf("%d", &power);
        if (power == -1)
        {
            break;
        }
        nAttacks++;

        powerAndType[nAttacks - 1][0] = power;
        scanf("%d", &powerAndType[nAttacks - 1][1]);

    } while (1);

    int enemyType;
    scanf("%d", &enemyType);

    double power = 0.0;
    int powerIndex;
    for (int i = 0; i < nAttacks; i++)
    {
        if (powerAndType[i][0] * existingTypes[i][enemyType] > power)
        {
            power = powerAndType[i][0] * existingTypes[i][enemyType];
            powerIndex = i;
        }
    }

    printf("O melhor ataque possui indice %d e dano %.2lf", powerIndex, power);

    for (int i = 0; i < matrixSize; i++)
    {
        free(existingTypes[i]);
        free(powerAndType[i]);
    }
    free(existingTypes);
    free(powerAndType);

    return 0;
}