#include<stdio.h>
void main(){
    int inc,outg,bs,n,store=0;
    printf("Enter bucket size and outgoing rate and no of inputs: ");
    scanf("%d %d %d",&bs,&outg,&n);
    while(n!=0){
        printf("\nEnter incomming packet size : ");
        scanf("%d",&inc);
        if(inc<=(bs-store)){
            store+=inc;
            printf("Bucket buffer size: %d out of %d ",store,bs);
        }else{
            printf("Dropped %d packets\n", store+inc-bs);
            printf("Bucket buffer size: %d out of %d\n", store, bs);
            store = bs; // Buffer is full
        }
        store-=outg;
        if (store < 0) store = 0; 
        printf("After outgoing: %d packets left out of %d in buffer\n", store, bs);
        n--;
    }
}