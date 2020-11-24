#include <stdio.h>

void hexdump(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
    FILE *input;
    for(int i =1; i<argc; i++){

       input = fopen(argv[i], "r+" );
       hexdump(input, stdout);

       if(i != argc-1)
        printf("\n");
        
    }

    return 0;
}
