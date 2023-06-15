#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // exit(0)とか使う時に必要なパッケージ

int main(){
  
  int Nin = 5; // もとのデータの行数

  int i;
  
  float ar_x[Nin]; // もとのデータのxの値
  float ar_y[Nin]; // もとのデータのyの値

  double E_x; // xの平均 average
  double E_y; // yの平均
  
  double V_xx;  // xの分散 variance
  double V_xy;  // xとyの共分散 covariance
  double V_yy;  // yの分散
  
  double sig_x; // xの標準偏差 = sqrt{V_xx}
  double sig_y; // yの標準偏差 = sqrt{V_yy}

  double gam;   // xとyの相関係数

  double a, b;        // 回帰係数 in y_fit = a + bx
  double er_a, er_b;  // 回帰係数の誤差
  
  double V_ee; // 残差の分散

  
  
  
  FILE *data;

  /* --- ファイルからデータ読み込み--- */
  data = fopen("06e1.txt","r");
  if(data==NULL)
    { printf("\n file name 06e1.txt was not opened"); }  
  for(i=0; i<Nin; i++){
    fscanf(data,"%f%f",&(ar_x[i]),&(ar_y[i])); 
  }
  fclose(data);
  
  /* for(i=0; i<Nin; i++) { */
  /*   printf("%f %f %f\n", ar_x[i], ar_y[i]); */
  /* } */
  /* exit(0); // 強制終了する命令(バグ取りするとき便利) */

  E_x = 0.;
  E_y = 0.;
  for(i=0; i<Nin; i++) {    
    E_x = E_x + 1./(double)Nin * ar_x[i];
    E_y = E_y + 1./(double)Nin * ar_y[i];
  }
  
  V_xx = 0.;
  V_xy = 0.;  
  V_yy = 0.;
  for(i=0; i<Nin; i++) {
    V_xx = V_xx + 1./(double)Nin * (ar_x[i] - E_x) * (ar_x[i] - E_x) ;
    V_xy = V_xy + 1./(double)Nin * (ar_x[i] - E_x) * (ar_y[i] - E_y) ;  
    V_yy = V_yy + 1./(double)Nin * (ar_y[i] - E_y) * (ar_y[i] - E_y) ;       
  }  
  
  sig_x = sqrt(V_xx);
  sig_y = sqrt(V_yy); 

  gam = V_xy / (sig_x*sig_y);

  /* --- 回帰係数 --- */

  b = V_xy / V_xx;
  a = E_y - b*E_x;
  
  V_ee = V_yy * (1. - gam*gam);  

  er_a = sqrt( V_ee/(double)Nin*(1. + E_x*E_x/V_xx) );
  er_b = sqrt( V_ee/(double)Nin/V_xx );

  /* --- 出力 --- */
  
  printf("average E(x) = %f, E(y) = %f\n", E_x, E_y);
  printf("variance V(x) = %f, V(y) = %f\n", V_xx, V_yy);
  printf("covariance COV(x,y) = %f\n", V_xy);
  printf("std. dev. sigma_x = %f, sigma_y = %f\n", sig_x, sig_y);
  printf("corr. coeff. gamma = %f\n", gam);

  printf("fit coeff. a = %f +/- %f\n", a, er_a);
  printf("fit coeff. b = %f +/- %f\n", b, er_b);

  return 0;
  
}

