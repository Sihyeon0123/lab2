#include <stdio.h>
#include "libmath.h"

int main(){
    int a, b;
    printf("정수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);
    
    for (int i = 0; i < 1000000000; i++){
      add(a, b);
      sub(a, b);
      multiply(a, b);
      divide(a, b);
    }

  
    printf("add(%d,%d) = %d\n", a, b, add(a,b));
    printf("sub(%d,%d) = %d\n", a, b, sub(a,b));
    printf("mul(%d,%d) = %d\n", a, b, multiply(a,b));
    printf("div(%d,%d) = %.2f\n", a, b, divide(a,b));
  }