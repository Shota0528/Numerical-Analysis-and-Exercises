#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW_SIZE 3
#define COLUMN_SIZE 3
#define EPSILON 1.0e-6

//fを返す関数. 第3引数とで指定 -> 1ならf1, 2ならf2
double f(double x, double y, double z, int i){
    if(i==1){
        return pow(x, 3) + pow(y, 3) + pow(z,  3) - 1;
    }

    if(i==2){
        return pow(x, 2)*pow(y, 2) + y*z + z*x - 1;
    }

    if(i==3){
        return pow(x, 2)*pow(y, 2)*pow(z, 2) + x + y + z - 1;
    }
}

//偏導関数を求める関数. 第4引数と第5引数で指定 -> 1, 1なら∂f1/∂x  1, 2なら∂f1/∂y
double dfdx(double x, double y, double z, int i, int j){
    if(i==1 && j==1){
        return 3*pow(x, 2);
    }
    if(i==1 && j==2){
        return 3*pow(y, 2);
    }
    if(i==1 && j==3){
        return 3*pow(z, 2);
    }
    if(i==2 && j==1){
        return 2*x*pow(y, 2) + z;
    }
    if(i==2 && j==2){
        return 2*pow(x, 2)*y + z;
    }
    if(i==2 && j==3){
        return y + x;
    }
    if(i==3 && j==1){
        return 2*x*pow(y, 2)*pow(z, 2) + 1;
    }
    if(i==3 && j==2){
        return 2*pow(x, 2)*y*pow(z, 2) + 1;
    }
    if(i==3 && j==3){
        return 2*pow(x, 2)*pow(y, 2)*z + 1;
    }

}
//3次の正方行列の逆行列を求めるために使う関数たち. 今回は余因子を用いて逆行列を求める.
void CalcDeterminant(double base[ROW_SIZE][ROW_SIZE], double *det){//行列式を求める関数
    *det += base[0][0] * base[1][1] * base[2][2];
    *det += base[0][1] * base[1][2] * base[2][0];
    *det += base[0][2] * base[1][0] * base[2][1];
    *det -= base[0][2] * base[1][1] * base[2][0];
    *det -= base[1][2] * base[2][1] * base[0][0];
    *det -= base[2][2] * base[0][1] * base[1][0];
}

void CalcAdjugateMatrix(double base[ROW_SIZE][ROW_SIZE], double adjugate[ROW_SIZE][ROW_SIZE]){//余因子行列を求める関数
    adjugate[0][0] = base[1][1] * base[2][2] - base[1][2] * base[2][1];
    adjugate[0][1] = -1 * (base[0][1] * base[2][2] - base[0][2] * base[2][1]);
    adjugate[0][2] = base[0][1] * base[1][2] - base[0][2] * base[1][1];
    adjugate[1][0] = -1 * (base[1][0] * base[2][2] - base[1][2] * base[2][0]);
    adjugate[1][1] = base[0][0] * base[2][2] - base[0][2] * base[2][0];
    adjugate[1][2] = -1 * (base[0][0] * base[1][2] - base[0][2] * base[1][0]);
    adjugate[2][0] = base[1][0] * base[2][1] - base[1][1] * base[2][0];
    adjugate[2][1] = -1 * (base[0][0] * base[2][1] - base[0][1] * base[2][0]);
    adjugate[2][2] = base[0][0] * base[1][1] - base[0][1] * base[1][0];
}

void CalcInverseMatrix(double adjugate[ROW_SIZE][ROW_SIZE], double *det, double inverse[ROW_SIZE][ROW_SIZE]){//逆行列を求める関数
    int i, j;
    for(i=0; i<ROW_SIZE; i++){
        for(j=0; j<ROW_SIZE; j++){
            inverse[i][j] = adjugate[i][j] / *det;
        }
    }
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
    double det = 0.0; //行列式
    //double x_[ROW_SIZE] = {1.0, 2.0, 3.0}; //初期値
    double x[ROW_SIZE];
    double coef[ROW_SIZE][ROW_SIZE];
    double adjugate[ROW_SIZE][ROW_SIZE]; //余因子行列
    double inverse[ROW_SIZE][ROW_SIZE]; //逆行列
    double flag[ROW_SIZE] = {0.0, 0.0, 0.0};

    printf("初期値 : %f, %f, %f\n", x_[0], x_[1], x_[2]);
    do{
        det = 0.0;
        //printf("繰り返し回数 %d\n", ++count);
        //導関数を係数行列として代入する
        for(i=0; i<ROW_SIZE; i++){
            for(j=0; j<ROW_SIZE; j++){
                coef[i][j] = dfdx(x_[0], x_[1], x_[2], i+1, j+1);
            }
        }
        //行列式 -> 余因子行列 -> 逆行列の順で求める
        CalcDeterminant(coef, &det);
        if(det == 0){
            printf("逆行列が定義できません");
            exit(1);
        }
        CalcAdjugateMatrix(coef, adjugate);
        CalcInverseMatrix(adjugate, &det, inverse);

        //漸化式の計算
        for(i=0; i<ROW_SIZE; i++){
            x[i] = x_[i];
            for(j=0; j<ROW_SIZE; j++){
                x[i] -= inverse[i][j]*f(x_[0], x_[1], x_[2], j+1);
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
    double x_[4][ROW_SIZE] = {{-0.5, 1.5, 0.0}, {1.5, -0.5, 0.0}, {0.5, 1.5, 0.0}, {-0.5, 0.5, 0.0}}; //初期値
    for(int i=0; i<4; i++){
        newton(x_[i]);
        printf("\n");
    }
    return 0;
}