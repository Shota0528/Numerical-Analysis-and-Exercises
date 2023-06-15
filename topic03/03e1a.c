#include <stdio.h>
#include <math.h>

#define EPSILON 10e-6

double F(double x){
    return pow(x, 3) - 1;
}

double successive_iteration(double(*f)(double), double x0){
    int count = 0;
    double x1 = x0, x2 = x0;
    do{
        x2 = (*f)(x1);
        if(count++ != 1){
            x1 = (*f)(x1);
        }
        printf("x_%d=%.9f\n", count, x2);
    }while(fabs(1 - x2/x1) > EPSILON);

    return x2;
}


int main(){
    double (*pf)(double);
    double x;

    pf = F;
    printf("xの初期値を入力してください : "); scanf("%lf", &x);
    printf("解は%.9fです\n", successive_iteration(pf, x));
    return 0;
}