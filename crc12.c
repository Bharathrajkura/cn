#include <stdio.h>
#define N strlen(gen_poly)
char data[28], check_value[28], gen_poly[10];
int data_length;
void XOR() {
    for (int j = 1; j < N; j++) {
        check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
    }
}
void crc() {
    for (int i = 0; i < N; i++) {
        check_value[i] = data[i];
    }
    int i = N;
    do {
        if (check_value[0] == '1') {
            XOR();
        }
        for (int j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }
        check_value[N - 1] = data[i++];
    } while (i <= data_length + N - 1); 
}
void receiver() {
    printf("\nEnter the received data: ");
    scanf("%s", data);
    printf("\n-----------------------------\n");
    printf("Data received: %s\n", data);
    crc();
    for (int i = 0; i < N - 1; i++) {
        if (check_value[i] != '0') {
            printf("\nError detected in received data\n");
            return;
        }
    }
    printf("\nNo error detected in received data\n");
}
int main() {
    printf("\nEnter data to be transmitted: ");
    scanf("%s", data);
    printf("\nEnter the generating polynomial: ");
    scanf("%s", gen_poly);
    data_length = strlen(data);
    for (int i = data_length; i < data_length + N - 1; i++) {
        data[i] = '0';
    }
    data[data_length + N - 1] = '\0'; 
    printf("\n----------------------------------------");
    printf("\nData padded with n-1 zeros: %s", data);
    printf("\n----------------------------------------");
    crc();
    printf("\nCRC or Check value: %s", check_value);
    for (int i = data_length; i < data_length + N - 1; i++) {
        data[i] = check_value[i - data_length];
    }
    data[data_length + N - 1] = '\0'; 
    printf("\n----------------------------------------");
    printf("\nFinal data to be sent: %s", data);
    printf("\n----------------------------------------\n");
    receiver();
    return 0;
}