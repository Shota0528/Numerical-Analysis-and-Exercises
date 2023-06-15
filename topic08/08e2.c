#include <stdio.h>
#include <math.h>

#define g 9.8 //重力加速度 [m/s]
#define c 1.0 //空気抵抗 [1/s]

double ftr(double t){
    return g/c * (1 - exp(-c*t));
}

double f(double v){
    return g - c * v;
}

//4次の陽的ルンゲクッタ法
double RungeKutta(double(*f)(double), double v, double t){
    double dt = 0.0001;
    double k1, k2, k3, k4;

    k1 = dt * (*f)(v);
    k2 = dt * (*f)(v + k1/2);
    k3 = dt * (*f)(v + k2/2);
    k4 = dt * (*f)(v + k3);

    return v + (k1 + 2*k2 + 2*k3 + k4)/6;
}


int main(){
    double t;
    double v = 0.0; //v(0)で初期化
    double (*pf)(double);
    pf = f;

    for(t=0.0; t<=7.0; t+=0.0001){
        printf("%f %f %f\n", t, v, ftr(t));
        v = RungeKutta(pf, v, t);
    }
    return 0;
}