#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
int g(int a, int b)
{
/*
	a 评价
	b 出的号 
*/
    char sa[]="00000000";
    char sb[]="00000000";
    int n = 0;
    int i,j;

    sprintf(sa,"%8d",a);
    sprintf(sb,"%8d",b);
    for(i=0; i<8; i++)
    {
        for(j=1; j<=8-i; j++)
        {
            char t = sa[i+j];
            //printf("第 %d次 %c \n",i,t);
            sa[i+j] = 0;
            
            if(strstr(sb, sa+i))
            {
                if(j>n) n = j;
            }
            sa[i+j] = t;
        }
    }

    return n;
}
int main(int argc, char* argv[])
{
    printf("%d\n", g(12345678,42234566));    
    printf("%d\n", g(12345678,12345678));
    return 0;
}
