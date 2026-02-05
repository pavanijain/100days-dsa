#include <stdio.h>
int main(){
    int p,q;
    int i=0,j=0;
    scanf("%d ",&p);
    int  log1[p];
    for(i=0;i<p;i++){
    scanf("%d ",&log1[i]);
}
scanf("%d ",&q);
int log2[q];
for(i=0;i<q;i++){
    scanf("%d ",&log2[i]);
}

i=0;
j=0;

while(i<p && j<q){
    if(log1[i] <= log2[j]){
        printf("%d ",log1[i]);
        i++;
    }
    else {
        printf("%d ",log2[j]);
        j++;
    }

}    

}