#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* file;
    char c;
    int checkABC[26]={0};
    int check123[10]={0};
    file=fopen("character counting.txt", "r");
    while(!feof(file)){
        fscanf(file, "%c", &c);
        if(c>=65&&c<=90){
            checkABC[c-65]++;
        }else if(c>=97&&c<=122){
            checkABC[c-97]++;
        }else if(c>=48&&c<=57){
            check123[c-48]++;
        }
    }
    int k = 0;
    for(int i = 0 ; i<36 ; i++){
        if(i<26){
            k = i+65;
            printf("%c : %d\n",k,checkABC[i]);
        }else{
            k = i+22;
            printf("%c : %d\n",k,check123[i-26]);
        }
    }
}