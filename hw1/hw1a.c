#include <stdio.h>

int main(){
    char filen[30];
    FILE* file;
    int small= 0;
    int k;

    printf("Input filename:  ");
    scanf("%s",filen);
    file=fopen(filen, "r");

    fscanf(file, "%d", &k);
    small=k;
    while(!feof(file)){
        fscanf(file, "%d", &k);
        if(small>k){
            small= k;
        }
    }
    printf("%d",small);
}