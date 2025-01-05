#include<stdio.h>
int main(){
    int data[20],rec[20];
    printf("Enter 4 bit data one by one : \n");
    scanf("%d %d %d %d",&data[0],&data[1],&data[2],&data[4]);
    data[6]=data[0]^data[2]^data[4];
    data[5]=data[4]^data[1]^data[0];
    data[3]=data[0]^data[1]^data[2];
    printf("The sending encoded bits are : ");
    for(int i=0;i<7;i++){
        printf("%d ",data[i]);
    }
    printf("\nEnter the received bits : \n");
    for(int i=0;i<7;i++){
        scanf("%d",&rec[i]);
    }
    int c1=rec[6]^rec[0]^rec[2]^rec[4];
    int c2=rec[4]^rec[1]^rec[0]^rec[5];
    int c3=rec[3]^rec[0]^rec[1]^rec[2];
    int del=(c3*4)+(c2*2)+(c1);
    if(del==0){
        printf("no error in data recived");
    }else{
        printf("error at position %d , %d",del,rec[7-del]);
        rec[7-del]=rec[7-del]^1;
          printf("%d",rec[7-del]);
        printf("\nthe correct data is \n");
        for(int i=0;i<7;i++){
            printf("%d ",rec[i]);
        }
    }
}