#include <stdio.h>
#include <math.h>
//f=e^(x^2)
float midpoint_f(float x, float y, float n)
{
    int i;
    float total=0, length_n, sum=0;
    length_n=(y-x)/n;
    x+=length_n/2;
    for(i=1 ; i<=n ; i++)
    {
        sum=pow(M_E,pow(x,2))*length_n;
        total+=sum;
        x+=length_n;
    }
    return total;
}

float trapezoid_f(float x, float y, float n)
{
    int i;
    float total=0, length_n, sum=0;
    length_n=(y-x)/n;
    for(i=1 ; i<=n ; i++)
    {
        sum=((pow(M_E,pow(x,2))+pow(M_E,pow((x+length_n),2)))*length_n)/2;
        total+=sum;
        x+=length_n;
    }
    return total;
}

float simpson_f(float x, float y, float n)
{
    int i;
    float total=0, length_n, sum=0;
    length_n=(y-x)/n;
    for(i=1 ; i<=n/2 ; i++)
    {
        sum=(pow(M_E,pow(x,2))+4*pow(M_E,pow((x+length_n),2))+pow(M_E,pow((x+2*length_n),2)))*length_n/3;
        total+=sum;
        x+=2*length_n;
    }
    return total;
}
//g=2e^x-2x
float midpoint_g(float x, float y, float n)
{
    int i;
    float total=0, length_n, sum=0;
    length_n=(y-x)/n;
    x+=length_n/2;
    for(i=1 ; i<=n ; i++)
    {
        sum=(2*(pow(M_E,x)-x))*length_n;
        total+=sum;
        x+=length_n;
    }
    return total;
}

float trapezoid_g(float x, float y, float n)
{
    int i;
    float total=0, length_n, sum=0;
    length_n=(y-x)/n;
    for(i=1 ; i<=n ; i++)
    {
        sum=(2*(pow(M_E,x)-x)+2*(pow(M_E,(x+length_n))-(x+length_n)))*length_n/2;
        total+=sum;
        x+=length_n;
    }
    return total;
}

float simpson_g(float x, float y, float n)
{
    int i;
    float total=0, length_n, sum=0;
    length_n=(y-x)/n;
    for(i=1 ; i<=n/2 ; i++)
    {
        sum=((2*(pow(M_E,x)-x))+4*2*(pow(M_E,x+(length_n))-(x+length_n))+2*(pow(M_E,x+(2*length_n))-(x+2*length_n)))*length_n/3;
        total+=sum;
        x+=2*length_n;
    }
    return total;
}

int main()
{
    char character;
    int continuity=1;
    float x, y, n;

    printf("Enter upper limit:");
    scanf("%f", &y);
    printf("Enter lower limit:");
    scanf("%f", &x);
    printf("Enter interval count:");
    scanf("%f", &n);
    if((int)n%2==0){
        printf("\nFor e^(x^2)\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson Result:%f\n", midpoint_f(x,y,n), trapezoid_f(x,y,n), simpson_f(x,y,n));
        printf("\nFor 2*(e^x)-2*x\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson Result:%f\n\n", midpoint_g(x,y,n), trapezoid_g(x,y,n), simpson_g(x,y,n));
    }
    else{
        printf("\nFor e^(x^2)\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson's Rule can't be calculated for odd values of interval count.\n", midpoint_f(x,y,n), trapezoid_f(x,y,n));
        printf("\nFor 2*(e^x)-2*x\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson's Rule can't be calculated for odd values of interval count.\n\n", midpoint_g(x,y,n), trapezoid_g(x,y,n));
    }
    while(continuity){
        printf("Press '0' to exit, another character to continue.\n");
        scanf(" %c", &character);
        printf("\n");
        switch(character)
        {
            case '0':
                continuity=0;
            break;

           default:
                printf("Enter upper limit:");
                scanf("%f", &y);
                printf("Enter lower limit:");
                scanf("%f", &x);
                printf("Enter interval count:");
                scanf("%f", &n);
                if((int)n%2==0){
                    printf("\nFor e^(x^2)\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson Result:%f\n", midpoint_f(x,y,n), trapezoid_f(x,y,n), simpson_f(x,y,n));
                    printf("\nFor 2*(e^x)-2*x\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson Result:%f\n\n", midpoint_g(x,y,n), trapezoid_g(x,y,n), simpson_g(x,y,n));
                }

                else{
                printf("\nFor e^(x^2)\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson's Rule can't be calculated for odd values of interval count.\n", midpoint_f(x,y,n), trapezoid_f(x,y,n));
                printf("\nFor 2*(e^x)-2*x\nMidpoint Result:%f\nTrapezoid Result:%f\nSimpson's Rule can't be calculated for odd values of interval count.\n\n", midpoint_g(x,y,n), trapezoid_g(x,y,n));
                }
            break;
        }
    }
    return 0;
}
