#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "validation.h"
#include "apc.h"


int is_valid_number(const char* str) {
    int i = 0;

    if (str[0] == '\0') {
        return 0;
    }

    if (str[0] == '+' || str[0] == '-') {
        i = 1;
    }

    if (str[i] == '\0') {
        return 0;
    }

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }

    return 1;
}

int validate_Number_of_CLA(int argc) {
    if (argc != 4) {
        printf("Error: Invalid format. Use: ./apc <num1> <operator> <num2>\n");
        return 1;
    }
    return 0;
}

void validate_input(char* argv[]) {
    if (is_valid_number(argv[1]) == 0) {
        printf("Error: First input operand is not a valid number.\n");
        exit(1);
    }

    if (argv[2][0] == '\0' || argv[2][1] != '\0' || (argv[2][0] != '+' && argv[2][0] != '-'&& argv[2][0] != '*'&& argv[2][0] != '/')) {
        printf("Error: Operator must be either '+' or '-' or '*' or '/'.\n");
        exit(1);
    }

    if (is_valid_number(argv[3]) == 0) {
        printf("Error: Second input operand is not a valid number.\n");
        exit(1);
    }
}
