#include <stdio.h>
#include <math.h>
#define COLUMN_SIZE 3
#define EPSILON 1.0e-6

//Max|1 - x_i^(m+1) / x_i^(m)| を求める.
//降順でソートしたら0番目が最大値になることを利用.
double max(double a[]){
    double tmp;
    double a_DESC[COLUMN_SIZE];

    for(int i=0; i<COLUMN_SIZE; i++){
        a_DESC[i] = fabs(a[i]);
    }

    for(int i=0; i<COLUMN_SIZE; i++){
        for(int j=i+1; j<COLUMN_SIZE; j++){
            if(a_DESC[i] < a_DESC[j]){
                tmp = a_DESC[i];
                a_DESC[i] = a_DESC[j];
                a_DESC[j] = tmp;
            }
        }
    }

    return a_DESC[0];
}

void gauss_seidel(double component[][COLUMN_SIZE], double x[], double b[]){
    int i = 0, j;
    int count = 0;
    double x_[COLUMN_SIZE] = {1.0, 2.0, 3.0}; //初期値
    double flag[COLUMN_SIZE] = {0.0, 0.0, 0.0};

    do{
        printf("繰り返し回数 %d\n", ++count);
        for(i=0; i<COLUMN_SIZE; i++){
            x[i] = b[i]/component[i][i];
            for(j=0; j<COLUMN_SIZE; j++){
                if(j != i){
                    x[i] -= (component[i][j]*x_[j])/component[i][i];
                }
            }
            flag[i] = (1 - x[i]/x_[i]);
            x_[i] = x[i];
            printf("x[%d]=%f\n", i, x[i]);
        }
    }while(max(flag) > EPSILON);
}

int main(){
    double component[COLUMN_SIZE][COLUMN_SIZE] = { //A
        {9.0, 0.0, -5.0}, 
        {5.0, -8.0, 6.0}, 
        {3.0, -6.0, 7.0},
    };
    double x[COLUMN_SIZE];//x
    double b[COLUMN_SIZE] = {3.0, -4.0, 3.0}; //b
    int i;
    gauss_seidel(component, x, b);
    return 0;
}