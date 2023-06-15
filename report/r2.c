#include <stdio.h>
#include <math.h>
#define EPSILON 1.0e-9

double f(double omega_m, double a){
    double H0 = 7*pow(10, -3)*pow(10, -8); //H_0
    return sqrt(a/(omega_m + (1-omega_m) * pow(a, 3)))/H0;
}

double simpson(double (*f)(double, double), double a, double b, unsigned int n, double omega_m){
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


int main(){
    double (*fp)(double, double);
    unsigned int n = 2; //刻み幅
    double a = 0.0, b = 1.0; //積分区間
    double omega_m[3] = {0.3, 0.8, 1.1};
    fp = f;

    for(int i=0; i<3; i++){
        n = 2;
        printf("omega_m : %f  宇宙年齢 : %f\n", omega_m[i], simpson(fp, a, b, n, omega_m[i]));
    }

    return 0;
}