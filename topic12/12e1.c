#include <stdio.h>
#include <math.h>

#define N 10000

void uniform_random_number_generator(int a, int b, int mu, int x1, int Nx[N], double randx[N]){
    Nx[0] = x1;
    randx[0] = x1 / mu;

    for(int i=0; i<N; i++){
        Nx[i+1] = (a*Nx[i]+b) % mu;
        randx[i+1] = (double)Nx[i+1] / mu;
    }
}

int main(){
    int Nx[N];
    double randx[N];
    int a = 12869, b = 6925, x1 = 26335;
    int mu = (int)pow(2, 15);
    double sum = 0.0, ave, var, sum2 = 0.0, ave2, sum3 = 0.0, ave3;

    uniform_random_number_generator(a, b, mu, x1, Nx, randx);

    for(int i=0; i<N; i++){
        sum += randx[i];
        sum2 += pow(randx[i], 2);
        sum3 += pow(randx[i], 3);
    }

    ave = sum/N;
    ave2 = sum2/N;
    ave3 = sum3/N;

    var = ave2 - pow(ave, 2);

    printf("平均 : %f\n", ave);
    printf("分散 : %f\n", var);
    printf("3乗平均 : %f\n", ave3);
    return 0;
}