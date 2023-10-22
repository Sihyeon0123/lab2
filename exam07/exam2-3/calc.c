#include <stdio.h>
#include <dlfcn.h>

int main(){
    void *handle;
    int (*add)(int, int), (*multiply)(int, int), (*sub)(int, int);
    float (*divide)(float, float);
    char *error;

    handle = dlopen("/root/exam2-3/lib/libmath.so", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        return 0;
    }
    
    add = dlsym(handle, "add");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        return 0;
    }

    sub = dlsym(handle, "sub");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        return 0;
    }   

    multiply = dlsym(handle, "multiply");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        return 0;
    }

    divide = dlsym(handle, "divide");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        return 0;
    }

    int a, b;
    printf("정수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);
    
    int res = 0;
    for (int i = 0; i < 1000000000; i++){
        res = (*add)(a,b);
        res = (*sub)(a,b);
        res = (*multiply)(a,b);
        res = (*divide)(a,b);
    }
    printf("add(%d, %d) = %d\n",a ,b, (*add)(a,b));
    printf("add(%d, %d) = %d\n",a ,b, (*sub)(a,b));
    printf("add(%d, %d) = %d\n",a ,b, (*multiply)(a,b));
    printf("add(%d, %d) = %.2f\n",a ,b, (*divide)(a,b));

    dlclose(handle);
}
