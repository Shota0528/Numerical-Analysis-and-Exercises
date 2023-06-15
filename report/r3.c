#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1.0E-6 //epsilon

double y(double omega_m, double a){
    double H0 = 7*pow(10, -3)*pow(10, -8); //H_0
    return sqrt(a/(omega_m + (1-omega_m) * pow(a, 3)))/H0;
}

double to(double (*f)(double, double), double a, double b, unsigned int n, double omega_m){
    double x_2i, x_2i_1, x_2i_2, sum = 0.0, ans = 0.0, ansold;
    int i;

    do{
        ansold = ans;
        sum = 0.0;
        for(i=0; i<n; i++){
            x_2i = a + (b-a)*2*i/(2*n);
            x_2i_1 = a + (b-a)*(2*i+1)/(2*n);
            x_2i_2 = a + (b-a)*(2*i+2)/(2*n);

            sum += (*f)(omega_m, x_2i_2) + 4*(*f)(omega_m, x_2i_1) + (*f)(omega_m, x_2i);
        }
        ans = (b-a)/(6*n)*sum;
        //printf("%5.3f %8.5f\n", b, ans);
        n *= 2;
    }while(fabs((ans-ansold)/ansold)>EPSILON);
    return ans;
}

double f(double (*f)(double, double), double a, double b, unsigned int n, double omega_m){
    double t0dat = 140*pow(10, 8);//(t_o)^dat
    return pow(t0dat - to(f, a, b, n, omega_m), 2);
}

int main(){
    double (*fp)(double, double);
    unsigned int n = 2; //刻み幅
    double a = 0.0, b = 1.0; //積分区間
    fp = y;
    double omega_m;
    double omega_m_MLE, omega_A_MLE;
    double min;
    int flag = 0;

    for(omega_m=0.10; omega_m<0.90; omega_m+=0.001){
        if(flag == 0){
            min = f(fp, a, b, n, omega_m);
            omega_m_MLE = omega_m;
            omega_A_MLE = 1 - omega_m;
            flag++;
        }
        if(min > f(fp, a, b, n, omega_m)){
            min = f(fp, a, b, n, omega_m);
            omega_m_MLE = omega_m;
            omega_A_MLE = 1 - omega_m;
        }
    }

    printf("(Ω_m, Ω_A) = (%f, %f)\n", omega_m_MLE, omega_A_MLE);

    return 0;
}