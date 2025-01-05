#include<stdio.h>
#include<string.h>
int main(){
    int k=0,n;
    char sd,ed;
    char input[50], stuffed[50]="";
    printf("Enter the characters to be Stuffed: ");
    scanf("%s",input);
    printf("Enter the starting Delimeter: \n");
    scanf(" %c",&sd);
    printf("Enter the ending Delimeter: ");
    scanf(" %c",&ed);
    strncat(stuffed,&sd,1);
    for(int i=0;i<strlen(input);i++){
        if(input[i]==sd||input[i]==ed){
           strncat(stuffed,&input[i],1);
        }
         strncat(stuffed,&input[i],1);
    }
    strncat(stuffed,&ed,1);
    printf("\nAfter stuffing: %s\n", stuffed);
    return 0;
}