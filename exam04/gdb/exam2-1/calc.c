#include <stdio.h>
#include "libmath.h"

int main(){
    int a, b;
    printf("정수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);

    for (int i = 0; i< 100000000; i++){
      add(a,b);
      sub(a,b);
      multiply(a,b);
      divide(a,b);
    }
    printf("add(%d,%d) = %d\n", a, b, add(a,b));
    printf("add(%d,%d) = %d\n", a, b, sub(a,b));
    printf("add(%d,%d) = %d\n", a, b, multiply(a,b));
    printf("add(%d,%d) = %.2f\n", a, b, divide(a,b));

  }
