#include <stdio.h>
#include <math.h>

/*--- F(x) ---*/
double func(double x){
  double y;  

  /* (a) --- */
  y = x*x*x - 1.0 ; 
  
  /* (b) --- */
  // y = 1.0/x + 1.0/(x*x) ;
  
  /* (c) --- */
  // y = sqrt(1.0 + 1.0/x) ; 
  
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
    
    x2 = func(x1);
    printf("x_{%2d} = %.10e\n", i, x1);      
    if (fabs(1.0-x2/x1)<eps) break; // |1-x_{n+1}/x_{n}|<eps なら終了
    x1 = x2;
    
  }
  
  printf("x_{%2d} = %.10e\n",i+1, x2);

  return 0;
  
}


