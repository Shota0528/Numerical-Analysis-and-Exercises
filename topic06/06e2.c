#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ

// 回帰曲線 fitting function f(p,q,x)の定義
double func_yfit(double p, double q, double x){ 
  double y;
  
  y = p*sin(q*x);
  
  return(y);
}


int main(){
  
  /*--- 入力パラメータ ---*/
  int Nin = 11; // もとのデータの行数

  // g_minの見つけ方
  // (p_min <= p <= pmax), (q_min <= q <= qmax)の空間上にM×M個のグリッドを入れ、グリッド上の点(p_i, q_i)ごとにg(p,q)を計算して、その最小値を見つける

  double p_min = 0.0 , p_max = 5.0 ; // pの範囲
  double q_min = 0.0 , q_max = 1.0 ; // qの範囲
  
  int M = 100; // 各パラメータのグリッド数
  
  /* ----------------------- */

  int i,ip,iq;
  
  float ar_x[Nin]; // もとのデータのxの値
  float ar_y[Nin]; // もとのデータのyの値
  float ar_err[Nin]; // もとのデータのyの誤差の値
  double ar_p[M]; // グリッド上のpの値
  double ar_q[M]; // グリッド上のqの値
  double ar_g[M][M]; // グリッド上のg(p,q)の値
  
  double e; // 残差
  double p_bf; // pの最尤値(bestfit value)
  double q_bf; // qの最尤値(bestfit value)
  double g_min; // g(p,q)の最小値
  
  FILE *data;

  /* --- ファイルからデータ読み込み--- */
  data = fopen("06e2.txt","r");
  if(data==NULL)
    { printf("\n file name 06e2.txt was not opened"); }  
  for(i=0; i<Nin; i++){
    fscanf(data,"%f%f%f",&(ar_x[i]),&(ar_y[i]),&(ar_err[i])); 
  }
  fclose(data);
  
  /* for(i=0; i<Nin; i++) { */
  /*   printf("%f %f %f\n", ar_x[i], ar_y[i], ar_err[i]); */
  /* } */
  /* exit(0); // 強制終了する命令(バグ取りするとき便利) */

  /* --- ar_p, ar_qの設定 --- */
  for(i=0; i<M; i++) {
    
    ar_p[i] = p_min + (double)i * (p_max - p_min)/(double)(M-1);
    ar_q[i] = q_min + (double)i * (q_max - q_min)/(double)(M-1);
    
    /* printf("%e %e\n", ar_p[i], ar_q[i]); */
    
  }


  /* --- ar_gの計算 --- */
  for(ip=0; ip<M; ip++) {
    for(iq=0; iq<M; iq++) {

      ar_g[ip][iq] = 0.0;      
      for(i=0; i<Nin; i++) {
       
	e = ar_y[i] - func_yfit(ar_p[ip], ar_q[iq], ar_x[i]); // 残差
	
	ar_g[ip][iq] = ar_g[ip][iq]
	  + pow(e/ar_err[i],2) ;
	  
      } // end i

      // printf("%e %e %e\n", ar_p[ip], ar_q[iq], ar_g[ip][iq]);
      
    } // end iq
  } // end ip

  // exit(0); // 強制終了する命令(バグ取りするとき便利) 
  
  /* --- ar_gが最小となるp,qの値を探す --- */

  g_min = ar_g[0][0];
  p_bf = ar_p[0];
  q_bf = ar_q[0];
    
  for(ip=0; ip<M; ip++) {
    for(iq=0; iq<M; iq++) {

      if(ar_g[ip][iq] < g_min){
	g_min = ar_g[ip][iq];
	p_bf = ar_p[ip];
	q_bf = ar_q[iq];
      }
      
    } // end iq
  } // end ip

  
  
  printf("g_min = %.2e when p = %.2e q = %.2e\n", g_min, p_bf, q_bf);

  return 0;
  
}

