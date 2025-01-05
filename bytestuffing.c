#include<stdio.h>
#include<string.h>
int main(){
   int k=0,n;
   char frame[50][50],str[50][50];
   char esc[] = "esc";
   char flag[] = "flag";
   strcpy(frame[k++],flag);
   printf("Enter Number of Strings :");
   scanf("%d",&n);
   printf("Enter the Strings: ");
   for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
    }
    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
    for(int i=0;i<n;i++){
        if(strcmp(str[i],esc)!=0&&strcmp(str[i],flag)!=0){
            strcpy(frame[k++],str[i]);
        }else{
            strcpy(frame[k++],esc);
            strcpy(frame[k++],str[i]);
        }
    }
    strcpy(frame[k++],flag);
    printf("\n----------------------------\n");
    printf("\n Byte stuffing at sender side\n");
    for(int i=0;i<k;i++){
        printf("%s\t",frame[i]);
    }
    printf("\n");

}