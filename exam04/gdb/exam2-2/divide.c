#include <stdio.h>
#include "libmath.h"

int main(){
    int a, b;
    printf("실수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);
    printf("divide(%d,%d) = %.2f\n", a, b, divide(a,b));
  }