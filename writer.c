#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 20

int main()
{
	printf("Writer\n");
	char* fifo_path = "./my_fifo";
	
	if(mkfifo(fifo_path,0666) == -1)
	{
		perror("Error creating fifo file \n");
		return 1;
	}
	//printf("FIFO File created \n");

	char buffer[SIZE];
	int fd = open(fifo_path,O_WRONLY);
	if(fd == -1)
	{
		printf("Error in opening the fifo file \n");
		return 1;
	}
	printf("Opened fifo File \n");
	printf("Enter the message : \n");
	scanf("%s",buffer);
	write(fd,buffer,sizeof(buffer));
	close(fd);
}
