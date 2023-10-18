#include <stdio.h>
#include <dlfcn.h>

int main(){
    void *handle;
    int (*add)(int, int), (*sub)(int, int), 
    (*multiply)(int, int), (*divide)(int, int);
    char *error;

    handle = dlopen("./lib/libmath.so", RTLD_LAZY);
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

    printf("add(1,2) = %d\n", (*add)(1,2));
    printf("sub(1,2) = %d\n", (*sub)(1,2));
    printf("multiply(1,2) = %d\n", (*multiply)(1,2));
    printf("divide(1,2) = %d\n", (*divide)(1,2));
}