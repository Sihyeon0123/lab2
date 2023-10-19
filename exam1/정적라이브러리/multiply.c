#include <stdio.h>
#include "libmath.h"

int main(){
    int a, b;
    printf("정수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);
    printf("multiply(%d,%d) = %d\n", a, b, multiply(a,b));
  }