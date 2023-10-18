/*
* 5장 디버깅과 오류 처리
* 파일 이름: assert_test.c
*/
#include <stdio.h>
#include <stdlib.h>

#define my_assert(expression) do { \
    if (!(expression)) { \
        char *program_name = getenv("_");\
        char *last_slash = program_name; \
        for (char *p = program_name; *p; p++) { \
            if (*p == '/') last_slash = p; \
        } \
        if (last_slash != program_name) program_name = last_slash + 1; \
        fprintf(stderr, "%s: %s:%d: %s: Assertion `%s' failed.\n", program_name, __FILE__, __LINE__, __func__, #expression); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

void foo(int num){
    my_assert(((num >= 0) && (num <= 100)));
    printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[]){
    int num;

    if (argc < 2) {
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber100)\n");
        return(1);
    }
    num = atoi(argv[1]);
    foo(num);
} 
