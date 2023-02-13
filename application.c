#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

int main(void){

    FILE *fp;
    char *text_bram_a= NULL;
    char *text_bram_b = NULL;
	int  *bram_a_txt_array, *bram_b_txt_array;
    long numbytes;
    
//**********************reading from bram_a.txt and storing data in array**********************//

    fp = fopen("bram_a.txt","r");
    if (fp == NULL) {
        printf("File can't be opened \n");
    }

	fseek(fp, 0L, SEEK_END);
	numbytes = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	text_bram_a = (char*)calloc(numbytes, sizeof(char));
	if(text_bram_a == NULL){
		printf("text_bram_a == NULL \n");
	}
	
	fread(text_bram_a, sizeof(char), numbytes, fp);
	if(fclose(fp)){
		printf("Problem pri zatvaranju text_file bram_a.txt\n");
		return -1;	
	}
	printf("********************************\n");
	printf("*************BRAM_A*************\n");
	printf(text_bram_a);
	printf("\n");
	printf("********************************\n");

//**********************reading from bram_b.txt and storing data in array**********************//

    fp = fopen("bram_b.txt","r");
    if (fp == NULL) {
        printf("File can't be opened \n");
    }

	fseek(fp, 0L, SEEK_END);
	numbytes = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	text_bram_b = (char*)calloc(numbytes, sizeof(char));
	if(text_bram_b == NULL){
		printf("text_bram_b == NULL \n");
	}
	
	fread(text_bram_b, sizeof(char), numbytes, fp);

	if(fclose(fp)){
		printf("Problem pri zatvaranju text_file bram_b.txt\n");
		return -1;	
	}

	printf("********************************\n");
	printf("*************BRAM_B*************\n");
	printf(text_bram_b);
	printf("\n");
	printf("********************************\n");

//***************************UPISUJEMO U /dev/bram_1***************************//

	fp = fopen("/dev/bram_a", "w");
	
	if(fp==NULL){
		printf("Nije moguce otvoriti /dev/bram_a.\n");
		return -1;	
	}

	fputs(text_bram_a,fp);

	if(fclose(fp)){	
		printf("Problem pri zatvaranju /dev/bram_a.\n");
		return -1;	
	}


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