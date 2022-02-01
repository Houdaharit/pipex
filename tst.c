#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **argv)
{
	int p[2];
	pipe(p);
	int pid = fork();
	if (pid > 0)
		write(p[1], "hello", 5);
	else
	{
		char buf[5];
		read(p[0], buf, 5);
		printf("%s", buf);
	}
}	
