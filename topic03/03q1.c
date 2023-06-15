#include <stdio.h>
#include <math.h>
#define EPSILON 1.0e-9

double f(double x){
    return cos(x) - x;
}

double fd(double x){
    return -1*sin(x) - 1;
}

double newton(double(*f)(double), double(*fd)(double), double x0){
    int count = 1;
    double x1 = x0, x2 = x0;
    do{
        x2 = x2-((*f)(x2))/(*fd)(x2);
        if(count++ != 1){
            x1 = x1-((*f)(x1))/(*fd)(x1);
        }
        printf("x_{%d}=%.9f\n", count-1, x2);
    }while(fabs(1 - x2/x1) > EPSILON);

    return x2;
}

int main(){
    double (*pf)(double);
    double (*pfd)(double);
    double x;

    pf = f;
    pfd = fd;
    printf("xの初期値を入力してください : "); scanf("%lf", &x);
    printf("解は%.9fです\n", newton(f, fd, x));
    return 0;
}