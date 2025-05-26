#include <stdio.h>
#include <string.h>

typedef struct {
    int key;
    float info;//info为其他信息
}JD;

void straisort(JD r[],int n){
    int i,j;
    for(i=2;i<=n;i++){
        r[0] = r[i];
        j = i-1;
        while(r[0].key<r[j].key){
            r[j+1] = r[j];
            j--;
        }
        r[j+1] = r[0];
    }
}