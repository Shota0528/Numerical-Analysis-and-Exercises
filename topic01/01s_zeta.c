#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // exit(0)とか使?��?時に?��?要なパッケージ

int main(void)
{ double wa1,wa2,s; int i,k,n,max=9999;
  wa1=0.0; wa2=0.0;
  
  printf(" Input n (n=0,1,2,...,10) : "); scanf("%d",&n);
  
  for(k=1;k<=max;k++){

    /* -------------------------- */
    
    /* ?��?の?��?つ */ 
    s=1.0;
    for(i=1;i<=n;i++){
      s=s/k;
    }
    
    /* (5) 冪乗�??��?��?み込み関数 */ 
    /* s = pow(k,-n); */
    
    /* -------------------------- */

    
    wa1=wa1+s;
    if(fabs(1.0-wa2/wa1)<1.e-8){ goto a90; }
    printf("k=%3d wa1=%10.8f wa2=%10.8f \n",k,wa1,wa2);
    wa2=wa1;
  }
  
  printf("** No. of count > max=%4d ** \n",max);
  
  return 0; /* returnは書かなくても終われる */
 a90: return 0;
  
}
