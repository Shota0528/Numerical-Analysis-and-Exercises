#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

//xの積分範囲
#define A 0.0
#define B 1.0
//yの積分範囲
#define C 0.0
#define D 1.0

double f(double x, double y){
    return (4 * x * y) / (pow(x, 2) + pow(y, 2) + 1);
}

//xとyについてN個の[0, 1)内一様乱数を生成
void montecarlo(double randx[N], double randy[N]){
    srand((unsigned)time(NULL));
    for(int i=0; i<N; i++){
        randx[i] = (double)rand() / RAND_MAX;
        randy[i] = (double)rand() / RAND_MAX;
    //printf("%f %f\n", randx[i], randy[i]);
    }
}

int main(){
    double randx[N], randy[N];
    double sum = 0.0, I;

    montecarlo(randx, randy);

    for(int i=0; i<N; i++){
        sum += f(randx[i], randy[i]);
    }

    I = sum / N; //今回はVk = (1 - 0) * (1 - 0) = 1
    printf("真値 : %f\n", 3*log(3) - 4*log(2)); //真値

    printf("結果 : %f\n", I);
    return 0;
}