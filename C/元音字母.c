#include <stdio.h>

int main()
{
    char m;
    scanf("%c",&m);
    switch(m)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("yes");
            break;
        default:
            printf("no");
    }
    return 0;
}
