#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ


/* n×n正方行列AをLU分解するsubroutine */
void sub_LU(Amat,L,U,n)
     int n;             // 行列A,L,Uの要素数 (in)
     double Amat[n][n]; // 行列A (in)
     double L[n][n];    // 下三角行列L (out)
     double U[n][n];    // 上三角行列U (out)
{
  
  double A[n][n];  
  double sum_lu;
  int i, j, k;
  
  /* --- AmatをAにコピー --- */
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = Amat[i][j];
    }
  }
  
  for(i = 0; i < n; ++i){
    
    /* --- i >= jの計算 --- */ 
    for(j = 0; j <= i; ++j){
      
      /* l_ij */ 
      sum_lu = 0.;
      for(k = 0; k < j; ++k){
	      sum_lu = sum_lu + L[i][k]*U[k][j];
      }       
      L[i][j] = A[i][j] - sum_lu;

      /* u_ij */       
      if(i > j) { U[i][j] = 0.; }      
      if(i == j){ U[i][j] = 1.; }
      
    } // end j
    
    /* --- i < jの計算 --- */   
    for(j = i+1; j < n; ++j){
      
      /* l_ij */ 
      L[i][j] = 0.;  
      
      /* u_ij */ 
      sum_lu = 0.;
      for(k = 0; k < i; ++k){
	      sum_lu = sum_lu + L[i][k]*U[k][j];
      }       
      U[i][j] = (A[i][j] - sum_lu) / L[i][i];
      
    } // end j
    
  } // end i
  
}


/* L,Uから連立1次方程式Ax=Bの解を求めるsubroutine */
void sub_solve(L,U,B,x,n)
     int n;          // ベクトルx, Bの次元 = 行列L, Uの要素数 (input)
     double L[n][n]; // 下三角行列L (input)
     double U[n][n]; // 上三角行列U (input)
     double B[n];    // ベクトルB (input)
     double x[n];    // ベクトルx (output)
{
  double Bd[n];      // ベクトルB'
  double s;
  int i, j;

  /* --- ベクトルB'の計算 */
  Bd[0]=B[0]/L[0][0];
  for (i=1; i<n; i++){
    if (fabs(L[i][i])<1.e-10) { printf("L[i][i] < 10^{-10} at step #%d", i); }

    s=0.0;
    for (j=0; j<=i-1; j++){
      s = s + L[i][j]*Bd[j];
    }
    
    Bd[i] = (B[i]-s) / L[i][i];
  } // end i

  printf("\n");
  printf("B' =\n");
  for (i=0; i<n; i++){
    printf("%f\n", Bd[i]); }
  
  /* --- ベクトルxの計算 */
  x[n-1] = Bd[n-1];
  for (i=n-2; i>=0; i--){
    
    s=0.0;
    for (j=i+1; j<n; j++){
      s = s + U[i][j]*x[j];
    }
    
    x[i] = Bd[i] - s;
  } // end i
  
}


int main(){

  /* --- 入力パラメータ ------------ */
#define N 3 // ベクトルx, Bの次元 = 正方行列Aの要素数
  
  double A[N][N]={{2., 1., -1.},  // Aの1行目の各要素 ※cの配列は0行目
		  {1., 2., 1.},   // Aの2行目の各要素 ※cの配列は1行目
		  {-2., 1., 2.}}; // Aの3行目の各要素 ※cの配列は2行目

  /* double A[N][N]={{8., 16., 24., 32.},   // Aの1行目の各要素 ※cの配列は0行目 */
  /* 		  {2., 7., 12., 17.},  // Aの2行目の各要素 ※cの配列は1行目 */
  /* 		  {6., 17., 32., 59.},   // Aの3行目の各要素 ※cの配列は2行目 */
  /* 		  {7., 22., 46., 105.}}; // Aの4行目の各要素 ※cの配列は3行目 */
  
  double B[N]={0., 3., 1.};       // Bの各要素
  /* double B[N]={160., 70., 198., 291.};       // Bの各要素 */

  /* ------------------------------- */

  double x[N];    // ベクトルx
  double L[N][N]; // ベクトルL
  double U[N][N]; // ベクトルU
  int i, j;

  sub_LU(A,L,U,N); // AをLU分解
  
  printf("\n");  
  printf("A =\n");
  for (i=0; i<N; i++){
    for (j=0; j<N; j++){
      printf("%f ", A[i][j]); }
    printf("\n");
  }

  printf("\n");
  printf("B =\n");
  for (i=0; i<N; i++){
    printf("%f\n", B[i]); }
  
  printf("\n");  
  printf("L =\n");
  for (i=0; i<N; i++){
    for (j=0; j<N; j++){
      printf("%f ", L[i][j]); }
    printf("\n");
  }

  printf("\n");  
  printf("U =\n");
  for (i=0; i<N; i++){
    for (j=0; j<N; j++){
      printf("%f ", U[i][j]); }
    printf("\n");
  }  
    
  sub_solve(L,U,B,x,N); // L,Uを使ってAx = Bの解xを求める

  printf("\n");
  printf("x =\n");
  for (i=0; i<N; i++){
    printf("%f\n", x[i]); }

  return 0;
  
}
