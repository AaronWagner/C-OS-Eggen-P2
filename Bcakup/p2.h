#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>

#include <stdlib.h>



#define MAXLINE 180;
#define SIZE 80;
#define NAMESIZE 20;



typedef struct TABLE
{

	
	char ids[20];
	int value;
} TABLE;