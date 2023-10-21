#include <stdio.h>
#include <dlfcn.h>

int main(){
    void *handle;
    int (*multiply)(int, int);
    char *error;

    handle = dlopen("/root/c/lib/libmath.so", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        return 0;
    }
    
    multiply = dlsym(handle, "multiply");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        return 0;
    }
    int a, b;
    printf("정수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);
    printf("multiply(%d, %d) = %d\n",a ,b, (*multiply)(a,b));
}