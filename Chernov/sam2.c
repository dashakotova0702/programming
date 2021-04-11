#include <stdio.h>
#include <stdlib.h>

int main (){

int file, size;
int i, j, max;
FILE *lol;
if (lol = fopen("kek.txt", "r")){
	fseek(lol, 0, SEEK_END);
	size = ftell(lol);
	fseek(lol, 0, SEEK_SET);
	int k[255] = {0};
	while ((file = fgetc(lol)) != EOF){ 
		k[file] = k[file] + 1;
	}
	max=0;
	for (i=0; i<255; i++){
		if (k[i]>max)
			max=k[i];
	}
	printf ("%d\n", max); 
	fclose(lol);
}
}
