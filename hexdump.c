#include <stdio.h>

long calculateBuffSize(long fileSize){      
    long res = 0;
    while(res <=  fileSize){
        res += 16 * sizeof(char);
    }
    return res+1;
}

void hexdump(FILE *input, FILE *output) { 
    //TODO: read String from file
    fseek(input, 0, SEEK_END);
    long fileSize = ftell(input);
    long buffSize = calculateBuffSize(fileSize);
    
    rewind(input);

    char arr [buffSize];
    for(int i=0; i < buffSize; i++)
	arr[i] = 0;

    fread(arr, 1, fileSize, input);
    fclose(input);
    arr[buffSize-1] = 0; //terminate with 0 byte

    int size = sizeof(arr)/(sizeof(arr[0])) -1;

    for(int i = 0; i < size; i+=16){

	fprintf(output, "%06x : ", i);

	for(int j = 0; j < 16; j++){
	    if(arr[i+j] == 0){
		fprintf(output, "   ");
	    }
	    else{
		fprintf(output, "%02x ", arr[i+j]);	
	    }
	}
	printf("  ");
	for(int k = i; k < i+16; k++){ //TODO: Nicht darstellbare chars durch . ersetzen
	    if(arr[k] != 0){
		fprintf(output, "%c", arr[k]);
	    }
	}
	fprintf(output, "\n");  
    }
    return;
}


