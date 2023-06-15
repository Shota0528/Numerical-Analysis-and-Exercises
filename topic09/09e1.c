#include <stdio.h>
#include <math.h>

double xtr(double t){
    return cosh(sqrt(2)*t) + 1/sqrt(2) * sinh(sqrt(2)*t);
}

double ytr(double t){
    return 1/sqrt(2) * sinh(sqrt(2)*t);
}

double dxdt(double x, double y){
    return x + y;
}

double dydt(double x, double y){
    return x - y;
}

//4次の陽的ルンゲクッタ法
void RungeKutta(double(*f)(double, double), double(*g)(double , double), double *x, double *y, double t){
    double dt = 0.01;
    double k1, k2, k3, k4, j1, j2, j3, j4;

    k1 = dt * (*f)(*x, *y);
    j1 = dt * (*g)(*x, *y);
    k2 = dt * (*f)(*x + k1/2, *y + j1/2);
    j2 = dt * (*g)(*x + k1/2, *y + j1/2);
    k3 = dt * (*f)(*x + k2/2, *y + j2/2);
    j3 = dt * (*g)(*x + k2/2, *y + j2/2);
    k4 = dt * (*f)(*x + k3, *y + j3);
    j4 = dt * (*g)(*x + k3, *y + j3);

    *x += (k1 + 2*k2 + 2*k3 + k4)/6;
    *y += (j1 + 2*j2 + 2*j3 + j4)/6;
}


int main(){
    double t;
    double x = 1.0, y = 0.0; //x(0), y(0)で初期化
    double (*pdx)(double, double), (*pdy)(double, double);
    pdx = dxdt;
    pdy = dydt;

    for(t=0.0; t<=7.0; t+=0.01){
        printf("%f %f %f %f %f\n", t, x, xtr(t), y, ytr(t));
        RungeKutta(pdx, pdy, &x, &y, t);
    }
    return 0;
}