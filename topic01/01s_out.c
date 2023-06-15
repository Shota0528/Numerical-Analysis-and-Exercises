#include <stdio.h> 
int main(void){
  FILE *fn1;
  int k=100;
  fn1 = fopen("kimout.txt","w");
  
  if(fn1==NULL)
    { printf("\n file name kimout.txt was not opened"); }
  
  fprintf(fn1,"%s\n","This is a test file"); // ファイルに出力 %sは文字列のとき
  
  printf("k= %d\n",k); // ターミナルに出力 %dは整数のとき
  
  fprintf(fn1,"k= %d\n",k); // ファイルに出力

  /* 問 */
  fprintf(fn1,"%s\n","数値解析第1回目"); // ファイルに出力  
  
}
