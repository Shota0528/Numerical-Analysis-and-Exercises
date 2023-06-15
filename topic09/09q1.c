#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

#define g 9.8 //重力加速度 (m/s^2)
#define L 9.8 //振り子の長さ (m)

double d2thetadt2(double theta){
    return -1.0 * g/L * sin(theta);
}

//4次の陽的ルンゲクッタ法
void RungeKutta(double(*f)(double), double *theta, double *dtheta, double t){
    double dt = 0.0001;
    double k1, k2, k3, k4, j1, j2,  j3, j4;

    k1 = dt * (*f)(*theta);
    j1 = dt * *dtheta;
    k2 = dt * (*f)(*theta + j1/2);
    j2 = dt * (*dtheta + j1/2);
    k3 = dt * (*f)(*theta + j2/2);
    j3 = dt * (*dtheta + j2/2);
    k4 = dt * (*f)(*theta + j3);
    j4 = dt * (*dtheta + j3);

    *theta += (j1 + 2*j2 + 2*j3 + j4)/6;
    *dtheta += (k1 + 2*k2 + 2*k3 + k4)/6;
}


int main(){
    double t;
    double theta = 0.0, dtheta = M_PI/4; //θ(0), θ'(0)で初期化
    double (*pf)(double);
    pf = d2thetadt2;

    for(t=0.0; t<=10.0; t+=0.0001){
        printf("%f %f %f\n", t, theta, dtheta);
        RungeKutta(pf, &theta, &dtheta, t);
    }
    return 0;
}