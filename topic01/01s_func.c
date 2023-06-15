#include <stdio.h>
#include <stdlib.h>  // exit(0)とか使�?時に�?要なパッケージ


double func(double x){
  double y;
  y=x*x*x-3.0*x+1.0;
  return(y);
}

// 単純な関数はもっとダイレクトに表現できる
/* double func(double x){ */
/*   return(x*x*x-3.0*x+1.0);  */
/* } */


int main(void){
  double x,y;
  for(x=-1.0;x<=2.0;x=x+0.01)
    { y=func(x);
      // printf("x=%5.2f y=%8.5f \n",x,y); // %A.BfのBは少数点以下�?�桁数

      // printf("%5.2f, %8.5f \n",x,y); // csvファイルに出力するとき�?�、コンマで列を区�?�?

      printf("%5.2f %8.5f \n",x,y); // txtファイルに出力するとき�?�コンマ�?��?らな�?  
      // exit(0); // 強制終�?する命令(バグ取りするとき便利)
      
    }
}
