#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert decimal to binary string representation
char* decimalToBinary(float num) {
                                        //Get the binary representation of the float number
    uint32_t *ptr = (uint32_t *)&num;   //create a pointer ptr of type uint32_t pointing to the memory location of the input num
    uint32_t binary = *ptr;             //references ptr to get the value stored at that memory location, which is treated as an integer
    
    // Allocate memory for the binary string
    char *binaryStr = malloc(33 * sizeof(char)); // 32 bits + null terminator
    
    // Iterate through each bit and convert it to '0' or '1' using a for loop
    for (int i = 31; i >= 0; i--) {
        binaryStr[31 - i] = ((binary >> i) & 1) ? '1' : '0';
    }
    binaryStr[32] = '\0'; // Null-terminate the string
    return binaryStr;
}

// Function to convert binary to decimal
float binaryToDecimal(char *binaryStr) {    // takes a binary string (char *binaryStr) as input and returns its decimal representation as a floating-point number
    float result = 0.0;                     //initializes result to 0.0 to accumulate the decimal value
    int exponent = 0;

    // Iterate through each bit of the binary string in reverse order using a for loop 
    for (int i = strlen(binaryStr) - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            result += pow(2, exponent);
        }
        exponent++; //increments exponent for each iteration.
    }

    return result;
}

int main() {    //main function will present a menu to the user to choose between converting options
    int choice;

    printf("Choose an option:\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");
    scanf("%d", &choice);

    if (choice == 1) {
        float decimalNum;
        printf("Enter a decimal number: ");
        scanf("%f", &decimalNum);

        char* binaryStr = decimalToBinary(decimalNum);
        printf("Binary representation: %s\n", binaryStr);
        free(binaryStr); // Free the allocated memory for the binary string
    } else if (choice == 2) {
        char binaryStr[33]; // Assuming the user will input 32 bits binary but user can input any binary string
        printf("Enter a binary representation: ");
        scanf("%32s", binaryStr);
        
        float decimalNum = binaryToDecimal(binaryStr);
        printf("Decimal representation: %f\n", decimalNum);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
