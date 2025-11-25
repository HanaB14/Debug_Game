#include <stdio.h>
// Converts a decimal number to binary and hexadecimal format. Assumes a "non-malicious user" (no negative/non integer inputs).
// Errors fixed:
// 1. Logic error: Incorrect condition in hexadecimal conversion (remainder <= 10 should be remainder < 10)
// 2. Logic error: temp variable was not reset between hexadecimal and binary conversions
// 3. Logic error: Missing j++ in binary conversion loop
// 4. Logic error: Incorrect index in hexadecimal output loop (starting from i instead of i-1)

int main () {
    int decimalNumber;
    printf("Please input a POSITIVE decimal number to be converted to hexadecimal and binary:");
    scanf("%d", &decimalNumber);
    char binary[500], hexadecimal[100];
    int i = 0, j = 0;
    int temp = decimalNumber;
    // simple check for the special case when the number is zero
    if (temp == 0) {
        printf("Hexadecimal = 0\n");
        printf("Binary = 0\n");
        return 0;
    }
    // convert decimal to hexadecimal, collecting digits from least significant
    while (temp > 0) {
        int remainder = temp % 16;
        if (remainder < 10) { // 1.Fixed 
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder - 10 + 'A';
        }
        temp /= 16;
        i++;
    }
    // convert decimal to binary, again starting from least significant bit
    temp = decimalNumber; // 2.Fixed
    while (temp > 0) {
        int remainder = temp % 2;
        if (remainder == 1) {
            binary[j] = '1';// j is used as the length/index for the binary representation
        } else {
            binary[j] = '0';
        }
        temp /= 2;
        j++; // 3.Fixed
    }
    // print hexadecimal digits in reverse to get the correct order
    printf("hexadecimal conversion = ");
    for(int k = i-1; k >=0; k --) { //4.Fixed
        printf("%c",hexadecimal[k]);
    }
    printf("\n"); 
    // print binary digits in reverse to get the correct order
    printf("binary conversion = ");
    for(int k = j -1; k >=0; k--){
        printf("%c",binary[k]);
    }
    printf("\n");
    return 0;
}