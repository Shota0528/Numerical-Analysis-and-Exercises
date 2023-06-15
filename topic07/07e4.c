#include <stdio.h>
#include <math.h>
#define EPSILON 1.0e-9

double f(double a, double x){
    return exp(a*x);
}

double ftr(double a){
    return (exp(a) - 1)/a;
}

double simpson(double (*f)(double, double), double a, double b, unsigned int n, double hata){
    double x_2i, x_2i_1, x_2i_2, sum = 0.0, ans = 0.0, ansold;
    int i;

    do{
        ansold = ans;
        sum = 0.0;
        for(i=0; i<n; i++){
            x_2i = a + (b-a)*2*i/(2*n);
            x_2i_1 = a + (b-a)*(2*i+1)/(2*n);
            x_2i_2 = a + (b-a)*(2*i+2)/(2*n);

            sum += (*f)(hata, x_2i_2) + 4*(*f)(hata, x_2i_1) + (*f)(hata, x_2i);
        }
        ans = (b-a)/(6*n)*sum;
        //printf("%5.3f %8.5f %8.5f %f\n", hata, ans, ftr(hata, x_2i), fabs(ans-ftr(hata, x_2i))/ftr(hata, x_2i));
        n *= 2;
    }while(fabs(ans-ansold)>EPSILON);
    return ans;
}


int main(){
    double (*fp)(double, double);
    unsigned int n = 2; //刻み幅
    double a = 0, b = 1; //a:下限 b:上限
    double hata;
    fp = f;

    for(int i=100; i<300; i++){
        hata = (double)i/100;
        printf("%f %f\n", hata, simpson(fp, a, b, n, hata));
    }

    return 0;
}