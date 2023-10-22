#include <stdio.h>
#include <dlfcn.h>

int main(){
    void *handle;
    float (*divide)(float, float);
    char *error;

    handle = dlopen("/root/exam2-3/lib/libmath.so", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        return 0;
    }
    
    divide = dlsym(handle, "divide");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        return 0;
    }
    float a, b;
    printf("실수 2개를 입력해 주세요:");
    scanf("%f %f", &a, &b);
    printf("divide(%.2f, %.2f) = %2.f\n",a ,b, (*divide)(a,b));
}
