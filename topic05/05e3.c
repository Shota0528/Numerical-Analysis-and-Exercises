#include <stdio.h>
#include <math.h>

//f(x) = ln(x)
double f_tr(double x){
    return log(x);
}

//f(x) = ln(x)を3点で2次補間して得られる近似式
//今回は(x1, f1) = (2, ln2), (x2, f2) = (3, ln3), (x3, f3) = (5, ln5)の3点
double f(double x){
    double x1 = 2, x2 = 3, x3 = 5;
    double f1 = f_tr(x1), f2 = f_tr(x2), f3 = f_tr(x3);
    return f1*(x - x2)*(x - x3)/((x1 - x2)*(x1 -x3)) + f2*(x - x1)*(x - x3)/((x2 - x1)*(x2 -x3)) + f3*(x - x1)*(x - x2)/((x3 - x1)*(x3 -x2));
}


int main(){
    for(double x=2.0; x<=5.0; x+=0.1){
        printf("%5.3f %8.5f %8.5f %8.5f\n", x, f(x), f_tr(x)); //x, ln(x)の2次補間, ln(x)
    }
    return 0;
}