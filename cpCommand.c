#include<stdio.h>

#define SIZE 100

int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("USAGE : COMMAND sourceFileName destFilenName\n");
		return -1;
	}

	FILE *sfptr, *dfptr;

	sfptr = fopen(argv[1],"r");
	
	if(sfptr==NULL)
	{
		printf("Error while opening source File \n");
		return -2;
	}

	dfptr  = fopen(argv[2],"w");

	if(dfptr == NULL)
	{
		printf("Error while opening destination File \n");
		return -3;
	}

	char buffer[SIZE];

	int noOfBytesRead = 0;

	while( (noOfBytesRead = fread(buffer,1,SIZE,sfptr)) > 0)
	{
		fwrite(buffer,1,noOfBytesRead,dfptr);
	}

	fclose(sfptr);
	fclose(dfptr);

	printf("Copied Files Successfully\n");

	return 0;	
}
