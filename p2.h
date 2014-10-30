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
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>


#include <sstream>


 using namespace std;


#define MAXLINE 180;
#define SIZE 80;
#define NAMESIZE 20;



typedef struct TABLE
{
	char ids[20];
	int value;
} TABLE;

typedef struct INST
{
	char command;
	char ids[20];
	int value;
} INST;

int main(int argc, char **argv);
bool readline(char* inputfilename, char* buf, int linenum);
void tokenize (string line, string* tokenizedline);
