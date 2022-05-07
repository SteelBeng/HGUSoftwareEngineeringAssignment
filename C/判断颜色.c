#include <stdio.h>
int main()
{
    int i;
    for(i=1;i<6;i++)
    {
        char a;
        scanf("%c",&a);
        getchar();
        if(a=='r')
        {
            printf("red\n");
        }
        else
        {
            if(a=='b')
            {
                printf("blue\n");
            }
            else
            {
                if(a=='y')
                {
                    printf("yellow\n");
                }
                else
                {
                    printf("again\n");
                }
            }
        }
    }
    return 0;
}
