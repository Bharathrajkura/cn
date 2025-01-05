#include <stdio.h>
#include <string.h>
#define N 10 // Length of the generating polynomial

int main() {
    char data[28], gen_poly[N], check_value[28];
    int data_length, i, j;
    
    // Input data to be transmitted and generating polynomial
    printf("Enter data to be transmitted: ");
    scanf("%s", data);
    printf("Enter the generating polynomial: ");
    scanf("%s", gen_poly);
    
    data_length = strlen(data);
    
    // Padding data with N-1 zeros
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = '0';
    }
    data[data_length + N - 1] = '\0'; 
    printf("Data padded with n-1 zeros: %s\n", data);
    
    // Initialize check_value with the padded data
    for (i = 0; i < N; i++) {
        check_value[i] = data[i];
    }

    // Perform CRC division (XOR operation)
    for (i = N; i < data_length + N - 1; i++) {
        if (check_value[0] == '1') {
            for (j = 1; j < N; j++) {
                // XOR operation: If bits are same, result is '0', otherwise '1'
                check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
            }
        }
        // Shift check_value left by 1 and add the next bit from data
        for (j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }
        check_value[N - 1] = data[i];
    }
    
    // Output CRC or check value
    printf("CRC or Check value: %s\n", check_value);

    // Append the check value (CRC) to the data
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = check_value[i - data_length];
    }
    data[data_length + N - 1] = '\0'; 
    printf("Final data to be sent: %s\n", data);

    // Simulate receiver by entering received data
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("Data received: %s\n", data);
    
    // Initialize check_value with the received data
    for (i = 0; i < N; i++) {
        check_value[i] = data[i];
    }

    // Perform CRC check
    for (i = N; i < data_length + N - 1; i++) {
        if (check_value[0] == '1') {
            for (j = 1; j < N; j++) {
                // XOR operation
                check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
            }
        }
        // Shift check_value left by 1 and add the next bit from data
        for (j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }
        check_value[N - 1] = data[i];
    }

    // Check for errors: If check_value is not all '0's, error is detected
    for (i = 0; i < N - 1; i++) {
        if (check_value[i] != '0') {
            printf("Error detected in received data\n");
            return 0;
        }
    }
    printf("No error detected in received data\n");

    return 0;
}
