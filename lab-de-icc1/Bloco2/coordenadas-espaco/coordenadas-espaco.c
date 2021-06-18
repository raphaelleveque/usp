#include <stdio.h>
#include <ctype.h>

int main()
{
    int x = 0, y = 0;
    char tecla;

    for (int i = 0; i < 6; i++)
    {
        scanf(" %c", &tecla);
        tecla = toupper(tecla);
        switch (tecla)
        {
        case 'W':
            y += 1;
            break;
        
        case 'S':
            y -= 1;
            break;
        
        case 'A':
            x -= 1;
            break;
        
        case 'D':
            x += 1;
            break;
        }
    }
    printf("%d %d", x, y);

    return 0;
}