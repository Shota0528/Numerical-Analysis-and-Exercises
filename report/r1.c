#include <stdio.h>
#include <math.h>

double f(double a, double omega_m){
    double H0 = 7*pow(10, -3); //H_0
    return H0 * sqrt(omega_m * pow(a, -1) + (1 - omega_m)*pow(a, 2));
}

//4次の陽的ルンゲクッタ法
double RungeKutta(double(*f)(double, double), double y, double t, double omega_m){
    double dt = 0.01;
    double k1, k2, k3, k4;

    k1 = dt * (*f)(y, omega_m);
    k2 = dt * (*f)(y + k1/2, omega_m);
    k3 = dt * (*f)(y + k2/2, omega_m);
    k4 = dt * (*f)(y + k3, omega_m);

    return y + (k1 + 2*k2 + 2*k3 + k4)/6;
}


int main(){
    double t;
    double a[3] = {1.0, 1.0, 1.0}; //a(t0)で初期化. それぞれΩmの配列と対応するように数値を格納する.
    double omega_m[3] = {0.3, 0.8, 1.1};
    double (*pf)(double, double);
    pf = f;


    for(t=0.0; t<=300.0; t+=0.01){
        printf("%f %f %f %f\n", t, a[0], a[1], a[2]);
        a[0] = RungeKutta(pf, a[0], t, omega_m[0]);
        a[1] = RungeKutta(pf, a[1], t, omega_m[1]);
        a[2] = RungeKutta(pf, a[2], t, omega_m[2]);
    }
    
    return 0;
}