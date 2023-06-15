#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x) {return x*x*x - x*x - 1.0;} // f(x)の定義

int main(){
  /* --- 入力パラメータ ------------ */
  double xL = 1.0; // xの範囲の下端
  double xR = 2.0; // xの範囲の上端
  double eps = 1.e-6; // 小さいほど精度が良い
  int imax = 100; // 計算回数の上限(大きく取る)
  /* ------------------------------- */
  
  int i;
  double xM;

  if (f(xL)*f(xR)>=0.) exit(1); // 解がそもそも最初のxLとxRの間に挟まれていなければ終了
  
  for (i=1; i<=imax; i++){
    
    /*--- (1) ---*/
    xM = (xL + xR) / 2.0; // 中点の計算
    printf("i = %2d xM = %.10e\n", i, xM);    
    
    /*--- (2) ---*/
    if (f(xL)*f(xM)<0.){
      xR=xM; // f(xL)f(xM)<0 なら xR=xM で継続
    }else{
      xL=xM; // f(xL)f(xM)>=0 なら xL=xM で継続
    }
    
    /*--- (3) ---*/    
    if (fabs((xR-xL)/xM)<eps) break; // |(xR-xL)/xM|<eps なら x=xM で終了
    
  }
  
  return 0;
  
}
