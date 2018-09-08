#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int a,b,c;
    float x1,x2,d;
    char status = 'y';
    printf("================Boundary Value Analysis===========\n");
    while(status == 'y')
    {
        printf("For Equation ax^2+bx+c = 0\n\n");
        printf("\nEnter a:");scanf("%d",&a);
        printf("\nEnter b:");scanf("%d",&b);
        printf("\nEnter c:");scanf("%d",&c);
        d = ((b*b)-(4*a*c));
        x1 = ((-b)+pow(d,0.5))/(2*a);
        x2 = ((-b)-pow(d,0.5))/(2*a);

        printf("\nRoots are: %f and %f\n\n",x1,x2);
        if(d > 0)
            printf("Real and unequal roots\n");
        if(d == 0)
            printf("Real and same roots\n");
        else
            printf("imaginary roots\n");

        printf("\nDo you want to continue...?[y/n]\n");
        scanf("%c",&status);
    }
    return 0;
}
