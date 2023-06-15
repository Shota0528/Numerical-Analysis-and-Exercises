#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#define EPSILON 1.0e-9

double f(double x){
    return 1.0/sqrt(2*M_PI) * exp(-x*x/2);
}


double simpson(double (*f)(double), double a, double b, unsigned int n){
    double x_2i, x_2i_1, x_2i_2, sum = 0.0, ans = 0.0, ansold;
    int i;

    do{
        ansold = ans;
        sum = 0.0;
        for(i=0; i<n; i++){
            x_2i = a + (b-a)*2*i/(2*n);
            x_2i_1 = a + (b-a)*(2*i+1)/(2*n);
            x_2i_2 = a + (b-a)*(2*i+2)/(2*n);

            sum += (*f)(x_2i_2) + 4*(*f)(x_2i_1) + (*f)(x_2i);
        }
        ans = (b-a)/(6*n)*sum;
        //printf("%5.3f %8.5f\n", b, ans);
        n *= 2;
    }while(fabs(ans-ansold)>EPSILON);
    return ans;
}


int main(){
    double (*fp)(double);
    unsigned int n = 2; //刻み幅
    double a; //積分区間
    fp = f;

    for(int i=0; i<=300; i++){
        a = (double)i/100;
        printf("%f %f\n", a, simpson(fp, -a, a, n));
    }

    return 0;
}