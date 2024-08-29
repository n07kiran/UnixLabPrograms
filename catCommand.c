#include<stdio.h>


#define SIZE 100

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("USAGE : COMMAND FILENAME\n");
		return -1;
	}
	
	char buffer[SIZE];

	FILE *fptr;
	fptr = fopen(argv[1],"r");

	if(fptr == NULL)
	{
		printf("File doesn't exist\n");
		return -2;
	}

	while(fgets(buffer,SIZE,fptr))
	{
		printf("%s",buffer);
	}
}
