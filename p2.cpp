#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>

#include <stdlib.h>



#define MAXLINE 180;
#define SIZE 80;
#define NAMESIZE 20;



typedef struct TABLE
{

	
	char ids[20];
	int value;
} TABLE;



int main(int argc, char **argv)
{
	char *init, *log, *trans1, *trans2;
		
	init=argv[1];
	log=argv[2];
	trans1=argv[3];
	trans2=argv[4];
	FILE* fileStream;
	
	if (!(fileStream=fopen(argv[1], "r")))
   {
      printf("Error file not found. Program terminated.");
      exit (0);
   }
	fclose(fileStream);
	if (!(fileStream=fopen(argv[2], "rw")))
   {
      printf("Error file not found. Program terminated.");
      exit (0);
   }
	fclose(fileStream);
	if (!(fileStream=fopen(argv[3], "rw")))
   {
      printf("Error file not found. Program terminated.");
      exit (0);
   }
	fclose(fileStream);
		if (!(fileStream=fopen(argv[4], "rw")))
   {
      printf("Error file not found. Program terminated.");
      exit (0);
   }
	fclose(fileStream);
	
	/*
	struct {
		  char id[NAME_SIZE+1]; 
		  int value;
		} TABLE[SIZE];
	*/

	//read from 0 write to 1 in pipes
	
	
	//  SETUP
	int pipein[2], pipeouta[2], pipeoutb[2];
	int p,q,r;
	string id;
	int value;

	int child_a_pid, child_b_pid, server_pid;

	//char buff[MAXLINE+1];

	


	p = pipe(pipeouta);
	if (p < 0) {
		printf("pipe in a error");
		exit(0);
	   }
	else
		printf("successful pipeina = %d\n",p);
	
	r = pipe(pipeoutb);
	if (r < 0) {
		printf("pipe in b error");
		exit(0);
	   }
	else
		printf("successful pipeind = %d\n",r);
  
  
	q = pipe(pipein);
	if (q < 0) {
		printf("pipe out error");
		exit(0);
	   }
		else
		printf("successful pipeout = %d\n",q);

///STORE MANAGER
   if ( (server_pid = fork()) == 0) 
   {   
   
   }
	

	//<Message formatting
	/*
	Prefix Origin code  1 or 2
	Orgin process Id #  (how long is this)
	Operand required U, TableID, Table_elem
					or
					 R, Table_id

	*/

//PROC1
   if ( (child_a_pid = fork()) == 0) 
   {

   }

//PROC2
   if ( (child_b_pid = fork()) == 0) 
   {

   }




////MANAGER



	exit (0);
}



