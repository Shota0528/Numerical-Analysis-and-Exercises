#include <stdio.h>
#include <math.h>

#define alpha 1.0 //増殖スピードを決める定数
#define N 10 //頭打ちになる数


double f(double y){
    return alpha*y*(N-y);
}

//4次の陽的ルンゲクッタ法
double RungeKutta(double(*f)(double), double y, double t){
    double dt = 0.0001;
    double k1, k2, k3, k4;

    k1 = dt * (*f)(y);
    k2 = dt * (*f)(y + k1/2);
    k3 = dt * (*f)(y + k2/2);
    k4 = dt * (*f)(y + k3);

    return y + (k1 + 2*k2 + 2*k3 + k4)/6;
}


int main(){
    double t;
    double y = 1.0; //y(0)で初期化
    double (*pf)(double);
    pf = f;

    for(t=0.0; t<=1.0; t+=0.0001){
        printf("%f %f\n", t, y);
        y = RungeKutta(pf, y, t);
    }
    return 0;
}