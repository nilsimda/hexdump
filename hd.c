#include <stdio.h>

void hexdump(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
    printf("%d\n", argc);

    for(int i =1; i<argc; i++){
        
        printf("%s\n", argv[i]);
        hexdump(fopen(argv[i], "r+" ), stdout);
        printf("This string");
        
    }

    return 0;
}
