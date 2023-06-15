#include <stdio.h>
#include <math.h>

double f(double x){
    return sin(x)/x;
}

double simpson(double (*f)(double), double a, double b, unsigned int n){
    double x_2i, x_2i_1, x_2i_2, sum = 0.0, ans = 0.0, ansold;
    int i;

    do{
        ansold = ans;
        sum = 0.0;
        for(i=0; i<n; i++){
            x_2i = a + (b-a)*2*i/(2*n);
            x_2i_1 = a + (b-a)*(2*i+1)/(2*n);
            x_2i_2 = a + (b-a)*(2*i+2)/(2*n);

            sum += (*f)(x_2i_2) + 4*(*f)(x_2i_1) + (*f)(x_2i);
        }
        ans = (b-a)/(6*n)*sum;
        printf("%fから%fまで \t %d分割した値は%f\n", a, b, n, ans);
        n *= 2;
    }while(n <= 1024);
    return ans;
}


int main(){
    double (*fp)(double);
    unsigned int n = 2; //刻み幅
    double a = 1, b = 10; //a:下限 b:上限
    fp = f;

    printf("y=sin(x)/xを%.3fから%.3fまで積分すると%.9fです\n",a, b, simpson(fp, a, b, n));

    return 0;
}