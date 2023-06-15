#include <stdio.h>
#include <math.h>
#include <complex.h> // 複素数を扱う時に必要なパッケージ
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ

int main(){
  
  complex z; // 倍精度複素数の定義
  complex e_z, e_minusz, e_iz, e_minusiz, cosz, sinz, logz, coshz, sinhz;

  z = 1 + I;
  e_z = cexp(z);
  e_minusz = cexp(-1*z);
  e_iz = cexp(I*z);
  e_minusiz = cexp(-1*I*z);
  cosz = ccos(z);
  sinz = csin(z);
  logz = clog(z);
  coshz = cosh(z);
  sinhz = sinh(z);
  
  //printf("e^z = %.5f%+.5fi\n", e_z); 
  printf("e^z = %.5f%+.5fi\n", creal(e_z), cimag(e_z));
  printf("e^-z = %.5f%+.5fi\n", creal(e_minusz), cimag(e_minusz));
  printf("e^iz = %.5f%+.5fi\n", creal(e_iz), cimag(e_iz));
  printf("e^-iz = %.5f%+.5fi\n", creal(e_minusiz), cimag(e_minusiz));
  printf("cosz = %.5f%+.5fi\n", creal(cosz), cimag(cosz));
  printf("sinz = %.5f%+.5fi\n", creal(sinz), cimag(sinz));
  printf("log_e[z] = %.5f%+.5fi\n", creal(logz), cimag(logz));
  printf("coshz = %.5f%+.5fi\n", creal(coshz), cimag(coshz));
  printf("sinhz = %.5f%+.5fi\n", creal(sinhz), cimag(sinhz));

  return 0;
  
}
