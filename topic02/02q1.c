#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ


// f(x) = tan(x)
double func(double x){ 
  double y;
  y = tan(x);
  return(y);
}

// f'(x) from (11) [4次精度]
double dfunc4(double x, double dx){ 
  double y;
  y = (func(x-2.0*dx) - 8.0*func(x-dx) + 8.0*func(x+dx) - func(x+2.0*dx)) / (12.0*dx) ;
  return(y);
}

// f''(x) from (13) [4次精度]
double dfunc5(double x, double dx){ 
  double y;
  y = (16.0*func(x+dx) + 16.0*func(x-dx) - func(x+2.0*dx) - func(x-2.0*dx) - 30.0*func(x)) / (12.0*dx*dx) ;
  return(y);
}


int main(void){
  double x,dx;

  dx = 0.05; // [rad]
  
  for(x=-M_PI/4;x<=M_PI/4;x=x + 2.0*M_PI / 100.0){ // 0 <= x <= 2piで100分割
     
    /* printf("%5.3f %8.5f %8.5f %8.5f %8.5f \n", x, func(x), dfunc1(x,dx), dfunc2(x,dx), dfunc4(x,dx)); */ // csvファイルに出力するときは、コンマで列を区切る
    
    printf("%5.3f %8.5f %8.5f %8.5f\n", x, func(x), dfunc4(x,dx), dfunc5(x,dx)); // x, f(x), 1次のf'(x), 2次のf'(x), 4次のf'(x)を出力

    // exit(0); // 強制終了する命令(バグ取りするとき便利)
    
  }

  return 0;
  
}
