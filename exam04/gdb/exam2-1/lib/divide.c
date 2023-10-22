#include <stdio.h>

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}
