#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

#define eps 0.001

unsigned int metod(void);

double f(double x);
double fshtrih(double x);

double metod_hord(double x1, double x2, unsigned int N, unsigned int debug);
double metod_pol(double x1, double x2, unsigned int N, unsigned int debug);
double metod_nut(double x1, double x2, unsigned int N, unsigned int debug);

int main()
{
    setlocale(LC_ALL, "Rus");
    unsigned int num_of_method;
    double x1, x2, kor;
    unsigned int N=100, debug=1; // debug = 0 - no debug  1 - print results at every iteration
    num_of_method  =  metod();

    do{
       system("cls");
       printf("x1=");
       scanf("%lf", &x1);
       printf("x2=");
       scanf("%lf", &x2);
    }while( f(x1) * f(x2) > 0   );

    if (num_of_method == 1 )
        {
    kor = metod_hord(x1, x2, N, debug);
    }
   else if (num_of_method == 2 )
        {
    kor = metod_pol(x1, x2, N, debug);
    }
    else if (num_of_method == 3 )
        {
    kor = metod_nut(x1, x2, N, debug);
    }

    printf("\n\nx=%lf   f(x)=%lf", kor, f(kor) );

    return 0;
}
//-------------------------------------------------------------------------
 double f(double x)
 {
     return 3*pow(x-2,3)+4*x;
 }

  double fshtrih(double x)
 {
     return 9*pow(x,2)-36*x+40;
 }

 //-------------------------------------------------------------------------

 double metod_hord(double x1, double x2, unsigned int N, unsigned int debug)
 {
     int Nplus;
    double xi;
    int n=1;
    do{
       xi = (f(x2)*x1-f(x1)*x2) / ( f(x2)-f(x1) );

       if ( f(xi)*f(x1) > 0 )
            x1 = xi;
       else
            x2 = xi;

       if(debug == 1)
        {
       printf("\n%d  %lf    %lf", n, xi, f(xi));
       n++;
        }
       if(n==N)
       {
           debug = 0;
           printf("\n\n\n\nN=100 \n\n??????i?? 1 ??? ??????? ?? 100 i?????ii\n??????i?? 2 ??? ??????? ??i i?????ii\n\n");
           scanf("%d", &Nplus);

    if(Nplus == 1)
    {
           debug = 1;
           N=N+100;
        if(n==N)
      {
           debug = 0;
           printf("\n\n\n\nN=100 \n\n??????i?? 1 ??? ??????? ?? 100 i?????ii\n??????i?? 2 ??? ??????? ??i i?????ii\n\n");
           scanf("%d", &Nplus);
           if(Nplus == 1)
            {
           debug = 1;
            }
      }
    }
   if(Nplus == 2)
        {
            debug=1 ;
        }

       }
    }
       while( fabs(f(xi)) > eps );

    return xi;
 }
    double metod_pol(double x1, double x2, unsigned int N, unsigned int debug)
 {

    double xi;
    int n=1;

    do{
       xi = (x1+x2)/2;

       if ( f(xi)*f(x1) > 0 )
            x1 = xi;
       else
            x2 = xi;


       if(debug == 1)
        printf("\n%d  %lf    %lf", n, xi, f(xi));
       n++;

    }while( fabs(f(xi)) > eps );

    return xi;
 }
  double metod_nut(double x1, double x2, unsigned int N, unsigned int debug)
 {

    double xi;
    int n=1;

    do{
       xi = x1-(f(x1)/fshtrih(x1));

       if ( f(xi)*f(x1) > 0 )
            x1 = xi;
       else
            x2 = xi;


       if(debug == 1)
               printf("\n%d  %lf    %lf", n, xi, f(xi));
       n++;

    }while( fabs(f(xi)) > eps );

    return xi;
 }

unsigned int metod(void)
{
    unsigned int m;
    printf("\n\n ????i?? ?????:\n1 - ???? \n2 - ?i?????\n3 - ???????\n");
    scanf("%u", &m);

    while(  m < 1  ||   m >3 )
    {
        printf("\n!!!?????? ?? ?i??? ?????!!!(1,2,3?) ");
        scanf("%u", &m);
    }
    switch(m){
      case 1:
             printf("\????--");
             break;
      case 2:
             printf("\n?i?--");
             break;
      case 3:
             printf("\???????--");
             break;
    }


    return m;
}
