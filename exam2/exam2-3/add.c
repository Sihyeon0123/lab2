#include <stdio.h>
#include <dlfcn.h>

int main(){
    void *handle;
    int (*add)(int, int);
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
    int a, b;
    printf("정수 2개를 입력해 주세요:");
    scanf("%d %d", &a, &b);
    printf("add(%d, %d) = %d\n",a ,b, (*add)(a,b));
}
