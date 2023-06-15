#include <stdio.h>
int main(void){
  
  FILE *fn1, *fn2;
  int k, m, n; // 整数の定義
  
  fn1 = fopen("kimout.txt","w");
  fn2 = fopen("kiminp.txt","r");
  
  fscanf(fn2,"%d%d",&m,&n); // ファイルから入力 %dは整数
  
  k=m+n;
  /* printf("\n%5d%5d%5d", m,n,k); */
  printf("%5d%5d%5d\n", m,n,k);
  fprintf(fn1,"%5d%5d%5d\n", m,n,k); // ファイルへ出力 %dは整数
  
}
