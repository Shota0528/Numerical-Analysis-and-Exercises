#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

#define N 7 //N個のデータをN-1次近似する

//f(x) = ln(x)を7点で6次補間して得られる近似式
//今回は(x1, f1) = (0, 0), (x2, f2) = (π/6, 1/2), (x3, f3) = (π/3, √3/2), (x4, f4) = (π/2, 1), (x5, f5) = (2π/3, √3/2), (x6, f6) = (5π/6, 1/2), (x7, f7) = (π, 0)の7点
double f(double _x){
    double x[N] = {0, M_PI/6, M_PI/3, M_PI/2, 2*M_PI/3, 5*M_PI/6, M_PI}, f[N] = {0, (double)1/2, sqrt(3)/2, 1, sqrt(3)/2, (double)1/2, 0};
    double fx = 0.0;
    for(int i=0; i<N; i++){
        double tmp = 1.0;
        for(int j=0; j<N; j++){
            if(i != j){
                tmp *= (_x - x[j])/(x[i] - x[j]);
            }
        }
        tmp *= f[i];
        fx += tmp;
    }
    return fx;
}

int main(){
    for(double x=0.0; x<=M_PI; x+=0.01){
        printf("%5.3f %8.5f\n", x, f(x)); //x, N-1次補間の順で表示
    }
    return 0;
}