#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ


// 境界・初期条件
double func_u0(double x, double t){ 
  double u;

  if (x == 0.){
    u = 0.;
  }else if (x == 1.){
    u = 0.;
  }else if (t == 0.){
    
    u = x*(x - 1.)*(2.*x - 1.);
    
  }else{

    // 境界・初期条件外のところを呼び出すと停止
    printf("outside from boundary and initial condition");
    exit(0);
    
  }
  
  return(u);
  
}

// 厳密解
double func_u_ex(double x, double t){ 
  int nmax = 10; /* 足し合わせるモードnの上限(理想的にはn -> 無限) */ 
  double u;
  int n;

  double pi2 = M_PI*M_PI ;
  double pi3 = M_PI*pi2 ;
  
  u = 0. ;
  for (n=1; n<nmax+1; n++){
    u = u + exp(-4.*((double)n*n)*pi2*t) / ((double)n*n*n)
      * sin(2.*(double)n*M_PI*x); 
  }
  
  u = u * 3. / pi3 ;
    
  return(u);
  
}



/* ------------------------------------------------------------------ */


int main(){

  /* --- 入力パラメータ ------------ */
#define Nx 5 // xのbinの数(格子点の数 = Nx + 1)
#define Nt 10 // tのbinの数(格子点の数 = Nt + 1)
  double x_min = 0. ; /* x_0    (xの範囲の下端) */
  double x_max = 1. ; /* x_{Nx} (xの範囲の上端) */  
  double t_min = 0. ; // t_0    (tの範囲の下端)
  /* ------------------------------- */

  double dx = (x_max - x_min) / (double)Nx ; // xのbin幅
  double dt = dx*dx/6. ; // tのbin幅(dt = dx^2/6と設定)
  // t_max = t_{Nt} = t_min + Nt*dt
  
  int i, j, k ;
  double ar_x[Nx+1] ; // x_i (i = 0, ..., Nx)
  double ar_t[Nt+1] ; // t_j (j = 0, ..., Nt)
  double ar_u[Nx+1][Nt+1] ; // u_{ij} (i = 0, ..., Nx)(j = 0, ..., Nt)
  double u_ex ; // u_{ij}の厳密解
  
  /*--- (0) x, tをbin化 --- */
  for(i=0; i<Nx+1; i++) {
    ar_x[i] = x_min + (double)i * dx;
    // printf("%.5f\n", ar_x[i]);
  }  
  for(j=0; j<Nt+1; j++) {
    ar_t[j] = t_min + (double)j * dt;
    // printf("%.5f\n", ar_t[j]);
  }
  
  /*--- (1) 初期条件からu_{00}, ..., u_{Nx,0}を計算 ---*/
  for (i=0; i<Nx+1; i++){
    ar_u[i][0] = func_u0(ar_x[i], ar_t[0]);
    // printf("%.5f\n", ar_u[i][0]);
  }
     
  /*--- (2) 境界条件からu_{01}, ..., u_{0,Nt}, u_{Nx,1}, ..., u_{Nx,Nt}を計算---*/
  for (j=1; j<Nt+1; j++){
    ar_u[0][j] = func_u0(ar_x[0], ar_t[j]);
    ar_u[Nx][j] = func_u0(ar_x[Nx], ar_t[j]);
  }
  
  /*--- (3) 漸化式からu_{11}, ..., u_{Nx-1,1}を計算 ---*/
  /*--- (4) 漸化式からu_{12}, ..., u_{Nx-1,2}を計算 ---*/
  /*--- ... 漸化式からu_{1,Nt}, ..., u{Nx-1,Nt}を計算 ---*/
  for (j=0; j<Nt; j++){
    for (i=1; i<Nx; i++){
      ar_u[i][j+1] = (ar_u[i+1][j] + ar_u[i-1][j] + 4.*ar_u[i][j]) / 6. ;
    }
  }
  
  /*--- 出力 ---*/

  // u_{ij} = u(x_i, t_i)のテーブル[列:i = 0, ..., Nx, 行:j = 0, ..., Nt]

  printf("\n");
  for (j=0; j<Nt+1; j++){
    for (i=0; i<Nx+1; i++){
      printf("%.5f ", ar_u[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  // それぞれのtごとに、u, 厳密解u_ex, 誤差をxの関数として出力[時間発展を追うグラフ用]

  /* for (j=0; j<Nt+1; j++){ */
  /*   for (i=0; i<Nx+1; i++){ */
      
  /*     u_ex = func_u_ex(ar_x[i], ar_t[j]); */
      
  /*     printf("%.4e %.4e %.4e %.4e %.4e\n", ar_x[i], ar_t[j], ar_u[i][j], u_ex, fabs(ar_u[i][j]/u_ex - 1.)); */
  /*   } */
  /*   printf("\n"); */
  /* } */

  return 0;
  
}
