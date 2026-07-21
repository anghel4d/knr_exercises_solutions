#include <stdio.h>
#include <malloc.h>
// #include <alloca.h>

int foo(int *a) {
    // Stack Allocation
    for(int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    
    return 1;
}


int main() {
    // Stack Allocation
    int a[5];

    foo(a);

    // Heap Allocation
    int *c = malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++) {
        c[i] = i + 1;
    }

    printf("Collection a:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }

    printf("Collection c:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", c[i]);
    }

    free(c);

    exit(0);
}