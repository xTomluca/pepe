#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int i,t;
int numero[4]={1,4,6,2};
int flag=1;

while(flag==1){
    flag=0;
    for(i=1;i<4;i++)
    {
        if(numero[i]<numero[i-1])
        {

            flag=1;
            printf("I = %d  ---  I-1   %d\n", numero[i], numero[i-1]);
            t=numero[i-1];
            numero[i]=numero[i-1];
            numero[i-1]=t;
        }
    }
}

for(i=0;i<4;i++)
{
    printf("%d",numero[i]);
}

return 0;
}
