#include <stdio.h>

int main()
{
    char m;
    scanf("%c",&m);
    if( m >= 48 && m<=57 )
    {
        printf("figure");
    }
    if( (m >= 0 && m<=31) || (m == 127) )
    {
        printf("control character");
    }
    if( m >= 65 && m <= 90)
    {
        printf("upper case");
    }
    if( m >= 97 && m <= 122 )
    {
        printf("lower case");
    }
    if((m >= 32 && m <= 47) || (m >= 58 && m <= 64) || (m >= 91 && m <= 96) || (m >= 123 && m <= 126))
    {
        printf("others");
    }
    return 0;
}
