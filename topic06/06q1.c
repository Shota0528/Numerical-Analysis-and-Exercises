#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 11 //データ数

double yfit1(double p, double q, double x){
    return p*x*(x-4.0)*(x-q);
}

double yfit2(double A, double k, double x){
    return A*sin(k*x);
}

double g1(double x[], double y[], double s[], double p, double q){
    double sum = 0.0;
    for(int i=0; i<N; i++){
        sum += pow(y[i] - yfit1(p, q, x[i]), 2)/pow(s[i], 2);
    }

    return sum;
}

double g2(double x[], double y[], double s[], double A, double k){
    double sum = 0.0;
    for(int i=0; i<N; i++){
        sum += pow(y[i] - yfit2(A, k, x[i]), 2)/pow(s[i], 2);
    }

    return sum;
}

int main(){
    double p, q, A, k;
    double x[N] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}, y[N] = {-0.3, 1.0, 3.0, 2.0, 0.0, -1.0, -3.0, -2.0, -1.5, 0.1, 1.3}, s[N] = {1.2, 1.4, 1.5, 1.2, 1.5, 0.7, 1.3, 1.4, 1.5, 1.0, 1.8}; //データを格納する配列
    double gmin1, gmin2;
    double p_MLE, q_MLE, A_MLE, k_MLE;
    int flag = 0;
    

    for(p=-5.0; p<5.0; p+=10.0/1000){
        for(q=0.0; q<10.0; q+=10.0/1000){
            if(flag==0){
                gmin1 = g1(x, y, s, p, q);
                gmin2 = g2(x, y, s, p, q);
                p_MLE = p;
                q_MLE = q;
                A_MLE = A;
                k_MLE = k;
                flag++;
            }
            if(gmin1 > g1(x, y, s, p, q)){
                gmin1 = g1(x, y, s, p, q);
                p_MLE = p;
                q_MLE = q;
            }
            if(gmin2 > g2(x, y, s, p, q)){
                gmin2 = g2(x, y, s, p, q);
                A_MLE = p;
                k_MLE = q;
            }
        }
    }

    printf("(p, q) = (%f, %f)\n", p_MLE, q_MLE);
    printf("gmin1 : %f\n", gmin1);
    printf("(A, k) = (%f, %f)\n", A_MLE, k_MLE);
    printf("gmin2 : %f\n", gmin2);

    if(gmin1 < gmin2){
        printf("gmin1\n");
    }else{
        printf("gmin2");
    }

    return 0;
}