#include <stdio.h>

long calculateBuffSize(long fileSize){      
    long res = 0;
    while(res < fileSize){
        res += (16 * sizeof(char));
    }
    return res;
}

void hexdump(FILE *input, FILE *output) { 
    fseek(input, 0, SEEK_END);
    long fileSize = ftell(input);
    long buffSize = calculateBuffSize(fileSize);
    
    rewind(input);
    char arr [buffSize];

    for(int i=0; i < buffSize; i++) //fill buffer with 0s
	    arr[i] = 0;

    fread(arr, 1, fileSize, input); //read text from file into buffer
    fclose(input);

    int size = sizeof(arr)/(sizeof(arr[0]));

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

	    for(int k = i; k < i+16; k++){ 
            if(arr[k] != 0){
                if(arr[k] < 32 || arr[k] > 126)
                    printf(".");
                else{    
                    fprintf(output, "%c", arr[k]);
	            }
            }    
	    }
	    fprintf(output, "\n");  
    }
    fclose(output);
    return;
}


