#include <stdio.h>
#include <math.h>

#define N 100000
#define A 1.0
#define B 10.0

double f(double x){
    return sin(x)/x;
}

void montecarlo(int a, int b, int mu, int x1, int Nx[N], double randx[N]){
    Nx[0] = x1;
    randx[0] = x1 / mu * (B - A) + A;

    for(int i=0; i<N; i++){
        Nx[i+1] = (a*Nx[i]+b) % mu;
        randx[i+1] = (double)Nx[i+1] / mu * (B - A) + A;
    }
}

int main(){
    int Nx[N], Ny[N];
    double randx[N], randy[N];
    int a = 12869, b = 6925, x1 = 26335;
    int mu = (int)pow(2, 15);
    double sum = 0.0, ave, I;

    montecarlo(a, b, mu, x1, Nx, randx);

    for(int i=0; i<N; i++){
        sum += f(randx[i]);
    }

    I = (B - A)/N * sum;

    printf("結果 : %f\n", I);
    return 0;
}