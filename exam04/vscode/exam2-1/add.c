#include <stdio.h>
#include "libmath.h"

int main(){
    int a, b;
    printf("정수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);
    int c = 1;
    int result = add(a,b);
    for (int i = 0; i < 100000; i++){
      c += 1;
    }

    printf("add(%d,%d) = %d\n", a, b, result);
  }
