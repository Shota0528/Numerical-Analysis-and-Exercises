#include <stdio.h>
#include <math.h>
#include <complex.h> // 複素数を扱う時に必要なパッケージ
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ


int main(){
  
  complex alpha, beta, gamma, delta; // 倍精度複素数の定義
  complex alpha_star, gamma2, betabydelta5 ;

  
  double R, theta; // alpha = R e^{i theta}のRとtheta
  
  alpha = 2.0 + I; // 虚数単位sqrt{-1}は大文字のIで
  beta  = -1.0 + 2.0*I; 
  gamma = -1.5*(1.0 + I);
  delta = 1.0 - I;

  R = cabs(alpha);     // = |alpha|
  theta = carg(alpha); // 偏角を求める関数
  
  printf("R = %.5f theta = %.5f\n",R, theta);
  // exit(0); // 強制終了する命令(バグ取りするとき便利)
  

  alpha_star = conj(alpha);             // = alpha^* 
  gamma2 = cpow(gamma, 2.0);            // = gamma^2
  betabydelta5 = cpow(beta/delta, 5.0); // = (beta/delta)^5
  
  //printf("alpha^* = %.5f%+.5fi\n", alpha_star);
  printf("alpha^* = %.5f%+.5fi\n", creal(alpha_star), cimag(alpha_star));
  //printf("gamma^2 = %.5f%+.5fi\n", gamma2);
  printf("gamma^* = %.5f%+.5fi\n", creal(gamma2), cimag(gamma2));
  //printf("(beta/delta)^5 = %.5f%+.5fi\n", betabydelta5);  
  printf("(beta/delta)^5 = %.5f%+.5fi\n", creal(betabydelta5), cimag(betabydelta5));
  return 0;
  
}
