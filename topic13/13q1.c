#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define a 1
#define Nx 5
#define Nt 10
#define EPS 0.5

//数値解
double f_u(double x, double t){
    double u;
    if((x == 0.0) || ((x == 1.0 ))){
        u = 0.0;
    }else if(t == 0.0){
        u = sin(M_PI*x);
    }else{
        printf("Satisfy boundary and initial condition");
        exit(1);
    }
    return u;
}

//厳密解
double f_u_tr(double x, double t){ 
    int n_max = 10; 
    double u = 0.0;
    int n;

    for(n=1; n<=n_max; n++){
        u += exp(-4.0*(pow(n, 2))*pow(M_PI, 2)*t) / (pow(n, 3)) * sin(2.0*n*M_PI*x); 
    }
    
    u *= 3/pow(M_PI, 3);
    return u;
    }

int main(){
    int i, j;
    double x_min = 0.0, x_max = 1.0, t_min = 0.0, u_tr;
    double dx = (double)(x_max - x_min)/Nx, dt = pow(dx, 2)/6;
    double x[Nx+1], t[Nt+1];
    double u[Nx+1][Nt+1];

    FILE *fp;

    //x, tの初期化
    for(i=0; i<Nx+1; i++){
        x[i] = x_min + i*dx;
    }
    for(i=0; i<Nt+1; i++){
        t[i] = t_min + i*dt;
    }

    //1 初期条件からu_{00}, ..., u_{Nx0}を計算
    for(i=0; i<Nx+1; i++){
        u[i][0] = f_u(x[i], t[0]);
    }

    //2 境界条件からu_{01}, ..., u_{0Nt}とu_{Nx1}, ..., u_{NxNt}を計算
    for(i=1; i<Nx+1; i++){
        u[0][i] = f_u(x[0], t[i]);
        u[Nx][i] = f_u(x[Nx], t[i]);
    }

    //3, 4, 5, ... (1.4)を使ってu_{11}, ..., u_{Nx-11}, u_{12}, ..., u_{Nx-12}, ...を漸化式で解く
    for(i=0; i<Nt; i++){
        for(j=1; j<Nx; j++){
            u[j][i+1] = (double)(u[j+1][i] + u[j-1][i] + 4*u[j][i]) / 6;
        }
    }

    // //厳密解と数値解を比べてみる
    // printf("厳密解 : 数値解\n");
    // for(i=0; i<Nx+1; i++){
    //     for(j=0; j<Nt+1; j++){
    //         printf("%f %f\n", f_u_tr(x[i], t[j]), u[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    //テーブルの出力
    printf("u_{ij}のテーブル\n");
    for(i=0; i<Nt+1; i++){
        for(j=0; j<Nx+1; j++){
            printf("%.5f ", u[j][i]);
        }
        printf("\n");
    }

    //gnuplot用にtxtファイルにデータを出力
    if((fp = fopen("13q1.txt", "w")) == NULL){
        printf("Could not open 13q1.txt\n");
        exit(1);
    }

    for(i=0; i<Nt+1; i++){
        for(j=0; j<Nx+1; j++){
            fprintf(fp, "%f %f\n", x[j], u[j][i]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}