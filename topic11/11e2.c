#include <stdio.h>
#include <math.h>
#define COLUMN_SIZE 4
#define N 3

void gauss_jordan(double component[N][COLUMN_SIZE]){
    int i = 0, j, k;
    double coef; //係数
    for(i=0; i<N; i++){
        coef = component[i][i];
        for(j=0; j<COLUMN_SIZE; j++){
            component[i][j] /= coef;
        }
        for(j=0; j<N; j++){
            coef = component[j][i];
            if(j != i){
                for(k=0; k<COLUMN_SIZE; k++){
                    component[j][k] -= coef * component[i][k];
                }
            }
        }
    }

    printf("連立方程式の解(行列)\n");
    for(i=0; i<N; i++){
        for(j=0; j<COLUMN_SIZE; j++){
            printf("%f  ", component[i][j]);
        }
        printf("\n");
    }
}

int main(){
    double equation[3][COLUMN_SIZE] = { //元の連立方程式
        {1.0, 2.0, 3.0, 1.0},
        {3.0, 1.0, 2.0, 1.0},
        {2.0, 3.0, 1.0, 2.0}
    };
    gauss_jordan(equation);
    return 0;
}