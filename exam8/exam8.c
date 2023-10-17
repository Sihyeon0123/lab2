#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y;
    printf("행렬의 x, y 길이를 입력해주세요: ");
    scanf("%d %d", &x, &y);

    int *matrix1 = (int *)malloc(x * y *sizeof(int));
    int *matrix2 = (int *)malloc(x * y *sizeof(int));

    printf("첫번째 행렬을 입력해주세요:\n");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            int temp = 0;
            scanf("%d", &temp);
            matrix1[i * x + j] = temp;
        }
    }

    printf("\n두번째 행렬을 입력해주세요:\n");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            int temp = 0;
            scanf("%d", &temp);
            matrix2[i * x + j] = temp;
        }
    }

    printf("\n");
    printf("행렬출력1\n");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", matrix1[i * x + j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("행렬출력2\n");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", matrix2[i * x + j]);
        }
        printf("\n");
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            matrix1[i * x + j] += matrix2[i * x + j];
        }
    }

    printf("\n");
    printf("결과출력\n");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", matrix1[i * x + j]);
        }
        printf("\n");
    }

    free(matrix1);
    free(matrix2);
    return 0;
}
