#include <stdio.h>
#include <string.h>
#define N 10 // Assuming the length of the generating polynomial is 10

int main() {
    char data[28], gen_poly[N], check_value[28];
    int data_length, i, j;
    
    printf("\nEnter data to be transmitted: ");
    scanf("%s", data);
    printf("\nEnter the generating polynomial: ");
    scanf("%s", gen_poly);
    
    data_length = strlen(data);
    
    // Padding data with N-1 zeros
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = '0';
    }
    data[data_length + N - 1] = '\0'; 
    
    printf("\nData padded with n-1 zeros: %s", data);
    
    // Initialize check_value with the padded data
    for (i = 0; i < N; i++) {
        check_value[i] = data[i];
    }

    // Perform CRC division
    for (i = N; i < data_length + N - 1; i++) {
        if (check_value[0] == '1') {
            for (j = 1; j < N; j++) {
                check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
            }
        }
        for (j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }
        check_value[N - 1] = data[i];
    }
    
    // Output the CRC (Check value)
    printf("\nCRC or Check value: %s", check_value);

    // Append the check value (CRC) to the data
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = check_value[i - data_length];
    }
    data[data_length + N - 1] = '\0'; 
    
    printf("\nFinal data to be sent: %s\n", data);

    // Simulate receiver
    printf("\nEnter the received data: ");
    scanf("%s", data);
    printf("\nData received: %s\n", data);
    
    // Initialize check_value with the received data
    for (i = 0; i < N; i++) {
        check_value[i] = data[i];
    }

    // Perform CRC check
    for (i = N; i < data_length + N - 1; i++) {
        if (check_value[0] == '1') {
            for (j = 1; j < N; j++) {
                check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
            }
        }
        for (j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }
        check_value[N - 1] = data[i];
    }

    // Check if any errors are detected
    for (i = 0; i < N - 1; i++) {
        if (check_value[i] != '0') {
            printf("\nError detected in received data\n");
            return 0;
        }
    }
    printf("\nNo error detected in received data\n");

    return 0;
}
