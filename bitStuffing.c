#include<stdio.h>
int main(){
    int n;
    printf("Enter the Number of bits 0s and 1s: ");
    scanf("%d",&n);
    int data[10];
    printf("Enter the data bits : ");
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    int count=0;
    int output[10];
    int j=0;
    for(int i=0;i<n;i++){
        if(data[i]==1){
            count++;
            output[j++]=data[i];
            if(count==5){
                output[j++]=0;
                count=0;
            }
        }else{
            output[j++]=data[i];
            count=0;
        }
    }
    printf("The data Frame is :\n");
    for(int i=0;i<j;i++){
        printf("%d ",output[i]);
    }
}