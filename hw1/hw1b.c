#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* file;
    float k=0;
    float sum = 0;
    int count;
    char line[20];
    int num[10]={'0'};
    int countd=0;

    
    file=fopen("example1.txt", "r");
    while(!feof(file)){
        for(int s = 0 ; s<20 ; s++){
            line[s]='\0';
        }
        fscanf(file, "%s", line);
        
        count = 0;
        countd = 0;
        for(int i = 0 ; i <sizeof(line);i++){
            if(line[i]>=48&&line[i]<=57){
                num[count]=line[i]-48;
                count++;
            }else if(line[i]=='.'){
                if(countd==0){
                countd=count;
                }
            }

        }
        float t;
        k=0;
        if(count>0&&countd==0){
            for(int u = count ; u>0 ; u--){
                t=1;
                for(int y = 0 ; y<u-1 ; y++){
                    t=t*10;
                }
                k = k+ num[count-u]*t;
            }
        }else if(countd>0&&countd!=count){
            int e = count - countd;    
                for(int u = countd; u>0 ; u--){
                    t=1;
                    for(int y = 0 ; y<u-1 ; y++){
                        t=t*10;
                    }
                    k = k+ num[countd-u]*t;
                }

            for(int w = 1 ; w <= e ; w++){
                t=1;
                for(int y = 0 ; y<w ; y++){
                        t=t*1.0/10;
                }
                k = k + num[countd+w-1]*t;

            }

        }
        sum = sum + k;
    }
    sum= sum -k;
    printf("%.2f",sum);
}