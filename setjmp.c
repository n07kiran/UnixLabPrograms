#include<stdio.h>
#include<setjmp.h>

static jmp_buf envBuf;


void second()
{
	printf("second\n");
	longjmp(envBuf,2);
}

void first()
{
	second();
	printf("First\n");
}

int main(int argc,char* argv[])
{
	int x = setjmp(envBuf);
	
	if( x == 0 )
	{
		printf("setjmp is called first time,thus returns %d \n",x);
		first();
	}
	else
	{
		printf("setjmp is not called first time, thus return %d , returned by longjmp \n",x);
	}
}


