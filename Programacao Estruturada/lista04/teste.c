#include <stdio.h>

int main() {
    int i = 1;
    
    for (int j = 0; j < 10; j++) {
        printf("%d\n",i);
        i >>= 1;
    }   
    
    return 0;
}