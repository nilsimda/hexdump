#include <stdio.h>

void hexdump(FILE *input, FILE *output) {
    //TODO: read String from file, print result to output file instead (use fprint maybe)

    char arr [48] = "The quick brown fox jumps over the lazy dog";
    int size = sizeof(arr)/(sizeof(arr[0])) -1;

    for(int i = 0; i < size; i+=16){

	printf("%06x : ", i);

	for(int j = 0; j < 16; j++){
	    if(arr[i+j] == NULL){
		printf("   ");
	    }
	    else{
		printf("%02x ", arr[i+j]);	
	    }
	}
	printf("   ");
	for(int k = i; k < i+16; k++){
	    if(arr[k] != NULL){
		printf("%c", arr[k]);
	    }
	}
	printf("\n");  
    }
    return;
}
