#include <stdio.h>
#include <math.h>
#include <complex.h> // 複素数を扱う時に必要なパッケージ
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ

#define EPSILON 1.0e-9

complex f(complex z){
    return z*z*z - 1;
}

complex fd(complex z){
    return 3*z*z;
}

complex newton(complex(*f)(complex), complex(*fd)(complex), complex z0){
    int count = 1;
    complex z1 = z0, z2 = z0;
    do{
        z2 = z2-((*f)(z2))/(*fd)(z2);
        if(count++ != 1){
            z1 = z1-((*f)(z1))/(*fd)(z1);
        }
        //printf("z_{%d}=%.5f%+.5fi\n", count-1, creal(z2), cimag(z2));
    }while(cabs(1 - z2/z1) > EPSILON);

    return z2;
}


int main(){
    complex (*pf)(complex);
    complex (*pfd)(complex);
    complex z0[3] = {2, I, -I};

    pf = f;
    pfd = fd;

    for(int i=0; i<3; i++){
        printf("z%d = %.5f%+.5fi\n", i+1, creal(newton(f, fd, z0[i])), cimag(newton(f, fd, z0[i])));
    }

    return 0;
}
