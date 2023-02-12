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
    
//*****************************************reading from .txt and storing data in array**********************//
    fp = fopen("bram_a", "r");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	printf("velicina %d\n", size);
	rewind(fp);
	buffer_bram_a = malloc((size+1) * sizeof(*buffer_bram_a));
	fread(buffer_bram_a, size, 1, fp);
	buffer_bram_a[size] = '\0';
	printf("%s\n", buffer_bram_a);	

    fp = fopen("bram_b", "r");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	printf("velicina %d\n", size);
	rewind(fp);
	buffer_bram_b = malloc((size+1) * sizeof(*buffer_bram_b));
	fread(buffer_bram_b, size, 1, fp);
	buffer_bram_b[size] = '\0';
	printf("%s\n", buffer_bram_b);	

//**************************************************************************************************************//








}