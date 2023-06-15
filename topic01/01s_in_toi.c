#include <stdio.h>
int main(void){
  
  FILE *fn1, *fn2;

  /* int k, m, n; */
  /* float a, b, c, d, m, n; */ // 単精度実数の定義 
  double a, b, c, d, m, n; // 倍精度実数の定義

  fn1 = fopen("01s_in_toi_out.txt","w");
  fn2 = fopen("01s_in_toi_inp.txt","r");

  /* fscanf(fn2,"%f%f",&m,&n); */ // ファイルから入力 %fは単精度実数
  fscanf(fn2,"%lf %lf",&m,&n); // ファイルから入力 %lfは倍精度実数
  
  a=m+n; // 和
  b=m-n; // 差
  c=m*n; // 積
  d=m/n; // 商
  
  // 出力 \nは改行 ""内でのスペースも出力画面に反映する
  printf("input = %lf %lf \n", m,n);  
  printf("output = %lf %lf %lf %lf \n", a,b,c,d);
  
  fprintf(fn1,"%lf %lf %lf %lf \n", a,b,c,d);

  /* printf("%f %f %f %f %f %f \n", m,n,a,b,c,d);  */
  /* fprintf(fn1,"%f %f %f %f %f %f \n", m,n,a,b,c,d); */

  
  
}
