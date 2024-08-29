#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

struct stat buf;


int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("USAGE : Command originalFileName linkFileName\n");
		return -1;
	}

	stat(argv[1],&buf);
	printf("No of links of %s , before link() : %d \n",argv[1],buf.st_nlink);

	int x = link(argv[1],argv[2]);

	if(x == -1)
	{
		printf("Link is unsuccessful : \n");
		return -2;
	}

	printf("Link is successful \n");

	stat(argv[1],&buf);
	printf("No of links of %s , after link() : %d \n",argv[1],buf.st_nlink);
	

	printf("Now let's unlink..\n");
	x = unlink(argv[2]);

	if(x == -1 )
	{
		printf("Unlink is unsuccessful \n");
	}
	else
	{
		printf("Unlink is successful \n");
	}

	stat(argv[1],&buf);
	printf("No of links of %s , after unlink() : %d \n", argv[1],buf.st_nlink);
}
