#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int a,b,c;
    float x1,x2,d;
    int status = 1;
    printf("================Boundary Value Analysis===========\n");
    while(status == 1)
    {
        printf("For Equation ax^2+bx+c = 0\n\n");
        printf("\nEnter a:");scanf("%d",&a);
        printf("\nEnter b:");scanf("%d",&b);
        printf("\nEnter c:");scanf("%d",&c);
        d = ((b*b)-(4*a*c));
        x1 = ((-b)+pow(d,0.5))/(2*a);
        x2 = ((-b)-pow(d,0.5))/(2*a);

        if(a<1 || a>100 || b<0 || b>100 || c<0 || c>100)
	    {
	    printf("\nEntered values should be within 1 to 100\n");
	    }
        else
        {
        cout<<"\nRoots are: "<<x1<<" and "<<x2<<"\n\n";
        if(d > 0)
            printf("Real and unequal roots\n");
        if(d == 0)
            printf("Real and same roots\n");
        else
            printf("imaginary roots\n");
        }
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("took %f seconds to execute \n", time_taken);
        printf("\nDo you want to continue...?[1/0]\n");
        scanf("%d",&status);
    }
    return 0;
}
