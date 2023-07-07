#include <stdio.h>

int num_vogais(char *str);

int main()
{
    char entrada[255];
    fgets(entrada, 255, stdin);
    
    printf("%d\n", num_vogais(entrada));
    
    return 0;
}

int num_vogais(char *str)
{
    int total = 0;
    while ((*str)!='\0') {
        if ((*str)=='a' || (*str)=='A' || (*str)=='e' || (*str)=='E' || (*str)=='i' ||
            (*str)=='I' || (*str)=='o' || (*str)=='O' || (*str)=='u' || (*str)=='U') {
            total++;
        }
        str++;
    }
    return total;
}