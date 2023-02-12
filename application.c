#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

int main(void){

    FILE *fp;
    char *buffer_bram_a = NULL;
    char *buffer_bram_b = NULL;
	int  *bram_a_txt_array, *bram_b_txt_array;
    size_t size = 0;
    
//*****************************************reading from .txt and storing data in array**********************//

    fp = fopen("bram_a.txt","r");
    if (NULL == fp) {
        printf("File can't be opened \n");
    }
    size = ftell(fp);
    buffer_bram_a = malloc((size+1) * sizeof(*buffer_bram_a));
    fread(buffer_bram_a, size, 1, fp);
    buffer[size] = '\0';
	printf("%s\n", buffer);	

//**************************************************************************************************************//


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





}