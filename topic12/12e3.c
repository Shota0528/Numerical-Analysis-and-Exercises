#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//本来なら領域D内の一様乱数ベクトルの個数をNとしてNを十分に多く取る必要がある.
//しかしPCのスペック上領域D内にN(100000)を取ろうとすると全体の個数がものすごく大きくなりメモリ不足となるので, 今回はN 100000として妥協.
//乱数を配列ではなく毎回生成すればこの問題は解決する. その場合はNを大きくする(大きくしないと配列にしない意味が無くなる)
#define N 100000

//xの積分範囲
#define A 0.0
#define B 1.0
//yの積分範囲
#define C 0.0

double f(double x, double y){
    return 8 * sqrt(1 - pow(x, 2) - pow(y, 2));
}

//xとyについてN個の[0, 1)内一様乱数を生成
void montecarlo(double randx[N], double randy[N]){
    srand((unsigned)time(NULL));
    for(int i=0; i<N; i++){
        randx[i] = (double)rand() / RAND_MAX;
        randy[i] = (double)rand() / RAND_MAX;
    }
}

int main(){
    int count = 0;
    /*乱数を配列ではなく毎回生成するなら配列をコメントアウトして変数のコメントアウトを消す*/
    double randx[N], randy[N];
    //double randx, randy;
    double sum = 0.0, I;


    /*乱数を配列ではなく毎回生成するならここからコメントアウト*/
    montecarlo(randx, randy);
    for(int i=0; i<N; i++){
        //領域D内の[0,1)内一様乱数を使用する.
        //この処理が原因で領域D内の一様乱数がN個用意できない.
        if(randx[i] >= A && randx[i] <= B && randy[i] >= C && randy[i] <= sqrt(1 - pow(randx[i], 2))){
            sum += f(randx[i], randy[i]);
            count++; //領域D内の点がどれくらいあったかカウント
        }
    }
    /*ここまで*/
    

    /*乱数を配列ではなく毎回生成するならここからのコメントアウトを外す*/
    // for(int i=0; i<N; i++){
    //     srand((unsigned)time(NULL));
    //     //領域D内の[0,1)内一様乱数を使用する.
    //     //この処理が原因で領域D内の一様乱数がN個用意できない.
    //     randx = (double)rand() / RAND_MAX;
    //     randy = (double)rand() / RAND_MAX;
    //     if(randx >= A && randx <= B && randy >= C && randy <= sqrt(1 - pow(randx, 2))){
    //         sum += sqrt(1-pow(randx, 2)) * f(randx, randy);
    //         count++; //領域D内の点がどれくらいあったかカウント
    //     }
    // }
    /*ここまで*/

    I = (M_PI/4) / count * sum;
    //printf("真値 : %f\n", (double)4*M_PI/3); //真値

    printf("結果 : %f\n", I);
    return 0;
}