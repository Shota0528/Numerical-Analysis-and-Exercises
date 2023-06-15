#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ

/*--- f(x) ---*/
double func(double x){
  double y;  
  y = x*x*x - x*x - 1.0 ;
  return y;
}

/*--- df(x)/dx ---*/
double dfdx(double x){
  double y;  
  y = 3.0*x*x - 2.0*x ;
  return y;
}



int main(){
  /* --- 入力パラメータ ------------ */
  double x1 = 1.0; // xの初期値
  double eps = 1.e-6; // 小さいほど精度が良い
  int imax = 100; // 計算回数の上限(大きく取る)
  /* ------------------------------- */
  
  double x2;
  int i;

  for(i=1; i<=imax; i++){
        
    x2 = x1 - func(x1)/dfdx(x1);
    printf("x_{%2d} = %.10e\n", i, x1);      
    if (fabs(1.0-x2/x1)<eps) break; // |1-x_{n+1}/x_n|<eps なら終了
    x1 = x2;

    // exit(0); // 強制終了する命令(バグ取りするとき便利)

    
  }
  
  printf("x_{%2d} = %.10e\n",i+1, x2);

  return 0;
  
}


