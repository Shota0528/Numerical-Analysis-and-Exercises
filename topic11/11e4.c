#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW_SIZE 2
#define COLUMN_SIZE 3
#define EPSILON 1.0e-6

//fを返す関数. 第3引数とで指定 -> 1ならf1, 2ならf2
double f(double x1, double x2, int i){
    if(i==1){
        return pow(x1, 3) + 2*pow(x2, 2) - 1;
    }

    if(i==2){
        return 2*pow(x1, 2) - x1*pow(x2, 3) - 1;
    }
}

//偏導関数を求める関数. 第3引数と第4引数で指定 -> 1, 1なら∂f1/∂x1  1, 2なら∂f1/∂x2
double dfdx(double x1, double x2, int i, int j){
    if(i==1 && j==1){
        return 3*pow(x1, 2);
    }
    if(i==1 && j==2){
        return 4*x2;
    }
    if(i==2 && j==1){
        return 4*x1 - pow(x2, 3);
    }
    if(i==2 && j==2){
        return -3*x1*pow(x2, 2);
    }

}

//2次の正方行列の逆行列逆行列を求める関数
void CalcInverseMatrix(double base[ROW_SIZE][ROW_SIZE], double inverse[ROW_SIZE][ROW_SIZE]){
    double coef = base[0][0]*base[1][1] - base[0][1]*base[1][0];

    if(coef == 0){
        printf("逆行列が定義できません");
        exit(1);
    }

    inverse[0][0] = 1/coef * base[1][1];
    inverse[0][1] = -1/coef * base[0][1];
    inverse[1][0] = -1/coef * base[1][0];
    inverse[1][1] = 1/coef * base[0][0];
}

//Max|1 - x_i^(m+1) / x_i^(m)| を求める.
//降順でソートしたら0番目が最大値になることを利用.
double max(double a[]){
    double tmp;
    double a_DESC[ROW_SIZE];

    for(int i=0; i<ROW_SIZE; i++){
        a_DESC[i] = fabs(a[i]);
    }

    for(int i=0; i<ROW_SIZE; i++){
        for(int j=i+1; j<ROW_SIZE; j++){
            if(a_DESC[i] < a_DESC[j]){
                tmp = a_DESC[i];
                a_DESC[i] = a_DESC[j];
                a_DESC[j] = tmp;
            }
        }
    }

    return a_DESC[0];
}

void newton(double x_[ROW_SIZE]){
    int i, j, k, count = 0;
    //double x_[ROW_SIZE] = {-1.5, -1.5}; //初期値
    double x[ROW_SIZE];
    double coef[ROW_SIZE][ROW_SIZE];
    double inverse[ROW_SIZE][ROW_SIZE];
    double flag[ROW_SIZE] = {0.0, 0.0};

    printf("初期値 : %f, %f\n", x_[0], x_[1]);
    do{
        //printf("繰り返し回数 %d\n", ++count);
        //導関数を係数行列として代入し, その後逆行列にする
        for(i=0; i<ROW_SIZE; i++){
            for(j=0; j<ROW_SIZE; j++){
                coef[i][j] = dfdx(x_[0], x_[1], i+1, j+1);
            }
        }
        CalcInverseMatrix(coef, inverse);

        //漸化式の計算
        for(i=0; i<ROW_SIZE; i++){
            x[i] = x_[i];
            for(j=0; j<ROW_SIZE; j++){
                x[i] -= inverse[i][j]*f(x_[0], x_[1], j+1);
            }
            flag[i] = (1 - x[i]/x_[i]);
            x_[i] = x[i];
            //printf("x[%d]=%f\n", i+1, x[i]);
        }
    }while(max(flag) > EPSILON);

    for(i=0; i<ROW_SIZE; i++){
        printf("x[%d]=%f\n", i+1, x[i]);
    }
}

int main(){
    double x_[5][ROW_SIZE] = {{-1.5, -1.5}, {-0.5, -0.5}, {-0.5, 0.5}, {0.5, -0.5}, {1.5, 1.5}}; //初期値
    for(int i=0; i<5; i++){
        newton(x_[i]);
        printf("\n");
    }
    return 0;
}