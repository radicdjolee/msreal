#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

int main(void){

    FILE *fp;
	FILE *textfile;
    char *buffer_bram_a;
    char *buffer_bram_b = NULL;
	int  *bram_a_txt_array, *bram_b_txt_array;
    long numbytes;
    
//*****************************************reading from .txt and storing data in array**********************//

    textfile = fopen("bram_a.txt","r");
    if (textfile == NULL) {
        printf("File can't be opened \n");
    }

	fseek(textfile, 0L, SEEK_END);
	numbytes = ftell(textfile);
	fseek(textfile, 0L, SEEK_SET);

	buffer_bram_a = (char*)calloc(numbytes, sizeof(char));
	if(buffer_bram_a == NULL){
		printf("buffer_bram_a == NULL \n");
	}
	
	fread(buffer_bram_a, sizeof(char), numbytes, textfile);
	fclose(textfile);
	printf(buffer_bram_a);

//**************************************************************************************************************//
/*

fp = fopen("/dev/imdct", "w");
	
	if(fp==NULL){
		
		printf("Nije moguce otvoriti /dev/imdct.\n");
		return -1;
		
	}
	sleep(0.5);
	printf("	********************************\n");
	printf("	**Upisujem block_type_00=0 u /dev/imdct.**\n");
	printf("	********************************\n");
	
	fputs("block_type_00 = 0",fp);
	
	if(fclose(fp)){
		
		printf("Problem pri zatvaranju /dev/imdct.\n");
		return -1;	
    }
*/



	return 0;
}