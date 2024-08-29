#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 20

int main()
{
	printf("Reader\n");

	char* fifo_path = "./my_fifo";

	char buffer[SIZE];
	int fd = open(fifo_path,O_RDONLY);
	if(fd == -1)
	{
		printf("Error in opening the fifo file \n");
		return 1;
	}
	printf("Opened fifo File \n");
	//printf("Enter the message : \n");
	//scanf("%s",buffer);
	read(fd,buffer,sizeof(buffer));

	printf("Message : %s ",buffer);
	close(fd);
}
