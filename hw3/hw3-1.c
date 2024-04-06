#include <stdio.h>


float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float **mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw);
float **transpose_matrix(float** a, int ah, int aw);

int main(){
    char op;
    FILE* file1;
    FILE* file2;
    int kk[2][2];
    int x,k;
    printf("What operation do you want? (‘a’, ‘m’, ‘t’)");
    scanf("%c",&op);
    char ar[2][10];
    if(op == 'a'||op =='m'){
        printf("Input files names:");
        scanf("%s",ar[0]);
        scanf("%s",ar[1]);

        file1=fopen(ar[0], "r");
        file2=fopen(ar[1], "r");

        fscanf(file1, "%d %d", &kk[0][0], &kk[0][1]);
        fscanf(file2, "%d %d", &kk[1][0] ,&kk[1][1]);

        float mat1[kk[0][0]][kk[0][1]];
        float mat2[kk[1][0]][kk[1][1]];
        x = 0;
        k = 0;
        while(!feof(file1)){
            if(x!=0&&x%kk[0][1]==0){
                k++;
            }
            fscanf(file1, "%f", &mat1[k][x%kk[0][1]]);
        }

        x = 0;
        k = 0;
        while(!feof(file1)){
            if(x!=0&&x%kk[1][1]==0){
                k++;
            }
            fscanf(file1, "%f", &mat2[k][x%kk[1][1]]);
        }

        if(op == 'a'){
            if(kk[0][0]!=kk[1][0]||kk[0][1]!=kk[1][1]){
                printf("Matrix dimensions mismatch");
            }
            float anw[kk[0][0]][kk[0][1]];
            anw = add_matrix(mat1,kk[0][0],kk[0][1],mat2,kk[1][0],kk[1][1]);

            for(int i = 0 ; i < kk[0][0] ;i++){
                for(int l = 0; l<kk[0][1] ; l++){
                    printf("%f ",anw[i][l]);
                }
                printf("\n");
            }
            return 0;

        }else if(op == 'm'){
            if(kk[0][1]!=kk[1][0]){
                printf("Matrix dimensions mismatch");
            }
            
            float anw1[kk[0][0]][kk[1][1]];
            anw1 = mul_matrix(mat1,kk[0][0],kk[0][1],mat2,kk[1][0],kk[1][1]);
            for(int i = 0 ; i < kk[0][0] ;i++){
                for(int l = 0; l<kk[1][1] ; l++){
                    printf("%f ",anw1[i][l]);
                }
                printf("\n");
            }
            return 0;

        }

    }else{
        file1=fopen(ar[0], "r");
        fscanf(file1, "%d %d", &kk[0][0], &kk[0][1]);
        float mat1[kk[0][0]][kk[0][1]];

        x = 0;
        k = 0;
        while(!feof(file1)){
            if(x!=0&&x%kk[0][1]==0){
                k++;
            }
            fscanf(file1, "%f", &mat1[k][x%kk[0][1]]);
        }

        if(op=='t'){
            float anw2[kk[0][1]][kk[1][0]];
            
            anw2 = transpose_matrix(mat1,kk[0][0],kk[0][1]);
            for(int i = 0 ; i < kk[0][1] ;i++){
                for(int l = 0; l<kk[0][0] ; l++){
                    printf("%f ",anw2[i][l]);
                }
                printf("\n");
            }
            } 

    }
}


float **add_matrix(float** a, int ah, int aw, float** b, int bh, int bw){
    float arr[ah][aw];

    for(int i = 0 ; i<ah ; i++){
        for(int k = 0; k<aw ; k++){
            arr[i][k] = a[i][k] + b[i][k];
        }
    }

    return arr;
}
float **mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw){
    float arr[ah][bw];
    for(int i = 0 ; i<ah ; i++){
        for(int k = 0; k<bw ; k++){
            for(int j = 0 ; j<aw ; j++){
                for(int h = 0; h<bh ; h++){
                    arr[i][k] =arr[i][k] + a[j][h] * b[j][h];
                }
            }
        }
    }
    return arr;
}
float **transpose_matrix(float** a, int ah, int aw){
    float arr1[ah][aw];
    float arr2[aw][ah];
    arr1 = a;

    for(int i = 0 ; i<ah ; i++){
        for(int k=0; k<aw ; k++){
            arr2[k][i] = arr1[i][k];
        }
    }

    return arr2;

}