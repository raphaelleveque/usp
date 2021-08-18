#include <stdio.h>
#include <stdbool.h>

int main()
{
    int array[100] = {}, arrayPosition = 0;

    while (scanf("%d", &array[arrayPosition]) != EOF)
    {
        arrayPosition++;
    }

    bool duplicateValues = false;
    int amountSameValue = 1;
    for (int i = 0; i < arrayPosition; i++)
    {
        for (int j = i + 1; j < arrayPosition; j++)
        {
            if (array[i] == array[j])
            {
                amountSameValue++;
            }
        }
        
        if (i > 0)
        {
            for (int j = i - 1; j > -1; j--)
            {
                duplicateValues = (array[i] == array[j]);
                if (duplicateValues)
                {
                    break;
                }
            }  
        }
        if (!duplicateValues)
        {   
            printf("%d (%d)\n", array[i], amountSameValue);
        }
        amountSameValue = 1;
    }
    

    return 0;
}