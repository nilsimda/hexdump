#include <stdio.h>

void hexdump(FILE *input, FILE *output);

int main(int argc, char *argv[]) {

    for(int i =1; i<argc; i++){
        
       hexdump(fopen(argv[i], "r+" ), stdout);
        
    }

    return 0;
}
