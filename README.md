# Decimal and Binary Converter

This C program provides functionality to convert decimal numbers to binary representation and vice versa.

## How to Use

1. Compile the program using a C compiler. For example, with `gcc`:

    
    gcc test.c -lm
    ```

2. Run the compiled executable:

   ./a.out

3. Follow the on-screen instructions to choose an option:
    - Option 1: Convert decimal to binary.
    - Option 2: Convert binary to decimal.

## Function Details

### `char* decimalToBinary(float num)`

- This function takes a decimal number as input and returns its binary representation as a string.

### `float binaryToDecimal(char *binaryStr)`

- This function takes a binary string as input and returns its decimal representation as a floating-point number.

## Note

- The program assumes that the user inputs valid decimal or binary numbers as per the chosen option.
- For binary input, the program expects a string of 32 characters. However, the user can input any binary string; only the first 32 characters will be considered.
- Ensure proper input validation for robustness in a production environment.

Created by Andrew Paolella 
