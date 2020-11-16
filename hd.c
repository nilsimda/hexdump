#include <stdio.h>

void hexdump(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
    FILE *input = fopen(argv[1], "r");
    FILE *output;
    if(argc == 3)
	 output = fopen(argv[2], "w+");
    else
	output = stdout;   

    hexdump(input, output);
    return 0;
}
