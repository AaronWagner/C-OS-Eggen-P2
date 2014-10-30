#include "p2.h"

int results [6];
/*
[0] reads success [1] reads [2] write [3] write success [4] errors [5] pid
*/

int main(int argc, char **argv)
{
	char *init, *log, *trans1, *trans2;
	char input=' ';
	char nextid[20];
	char buf[256];
	bool debug=true;
	init=argv[0];
	log =argv[1];
	trans1=argv[2];
	trans2=argv[3];
	//void handler(int);          // signal handler prototype 
    void handler1(int);         // signal handler prototype 
    void handler2(int);         // signal handler prototype 
	
	init=argv[1];
	log=argv[2];
	trans1=argv[3];
	trans2=argv[4];
	FILE* fileStream;
	int i,j,k;
	for (i=0; i<6; i++)
	{
			results[i]=0;
	}
	
	//sigset(SIGUSR, handler);  // set handler to use the function
    sigset(SIGUSR1, handler1);  // sigset could also be used
                                 // works similar to signal 
    signal(SIGUSR2, handler2); // set handler to use the function
                                 // works similar to signal 

 //     printf("executing in the child process\n");
  //    printf("in the child process waiting for a signal\n");

//        sleep(2);
//      signal(SIGUSR1, handler2);  // reset handler to use the function
   //   printf("actually will get here now\n");
	
	
	
	
	
	
	if (!(fileStream=fopen(argv[1], "r")))
   {
      printf("Error init file not found. Program terminated.");
      exit (0);
   }
	fclose(fileStream);
	if (!(fileStream=fopen(argv[2], "rw")))
   {
      printf("Error log file not found. Program terminated.");
      exit (0);
   }
	fclose(fileStream);
	if (!(fileStream=fopen(argv[3], "rw")))
   {
      printf("Error first transaction file not found. Program terminated.");
      exit (0);
   }
	fclose(fileStream);
		if (!(fileStream=fopen(argv[4], "rw")))
   {
      printf("Error second transaction file not found. Program terminated.");
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
	char id[20];
	int value;

	int server_pid, child_a_pid, child_b_pid;
	
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
		results[6]=server_pid;
		
		//refactor to C++
		
		i=0;
		j=0;
		k=0;
		//read the init file and count the 
		if (!(fileStream=fopen(argv[1], "r")))
	   {
		  printf("Error init file not found. Program terminated.");
		  exit (0);
	   }
	   
	   int numids=0;
	   
	   
	  while (fgets (buf, sizeof(buf), fileStream)) {
		//printf("line: %s \n", buf);
		numids++;
	  }
	  
	  if (ferror(stdin)) {
		fprintf(stderr,"Oops, error reading stdin\n");
		abort();
	  }
	  fclose(fileStream);
		
		//if (debug) printf ("Init has %d ids. \n",numids);	
		TABLE mytable[numids];
	   
		char name[20];
		char stringnum[20];
		char nextchar;
		j=0;
		k=0;
		if (!(fileStream=fopen(argv[1], "r")))
			   {
				  printf("Error init file not found. Program terminated.");
				  exit (0);
			   }
		for (i=0; i<numids; i++)
		{
				
			
			  fgets (buf, sizeof(buf), fileStream);
			  
			  
			 // printf("line: %s \n", buf);
				
			  
			  if (ferror(stdin)) 
			  {
				fprintf(stderr,"Oops, error reading stdin\n");
				abort();
			  }
			  
			nextchar=buf[0];
			while (nextchar!=' ')
			{
				mytable[i].ids[j]=nextchar;
				j++;
				nextchar=buf[j];
			}
			k=0;
			while (nextchar=buf[++j])
			{
				stringnum[k]=buf[j];
				k++;
			}
			mytable[i].value=atoi(stringnum);
			//printf("String %s Value %d \n", mytable[i].ids, mytable[i].value);
			
			j=0;
		}
		fclose(fileStream);

		//printf("Table: \n Name:---------------Value:\n");
		for (i=0; i<numids; i++)
		{
			//printf ("%s %d \n", mytable[i].ids, mytable[i].value);
			//printf ("I: %d\n",i);
		}
		//read contents of pipein 
		
		
		
		
		
		while(true)
		{
			sleep(2);
		}
		//end of manager
		exit(0);
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
			//signal(SIGUSR1, handler1);
			results[6]=child_a_pid;
			sleep(1);
			char proc1buf[256];
			string lineA;
			char** fileContents;
			string *instructionsA;
			int numlines;
			string name, command;
			int value;
			char *commandchar;
			char cc;
			
			i=0;
			j=0;
			bool read;
			//bool 
				//paste from manager
						//refactor to C++
			
					i=0;
					j=0;
					k=0;
					//read the init file and count the 
					if (!(fileStream=fopen(trans1, "r")))
				   {
					  printf("Error init file not found. Program terminated.");
					  exit (0);
				   }
				   
				   int numids=0;
				   
				   
				  while (fgets (buf, sizeof(buf), fileStream)) {
					//printf("line: %s \n", buf);
					numids++;
				  }
				  
				  if (ferror(stdin)) {
					fprintf(stderr,"Oops, error reading stdin\n");
					abort();
				  }
				  fclose(fileStream);
					
					//if (debug) printf ("Init has %d ids. \n",numids);	
					INST myinstructions[numids];
					char commandA;
					char* nameA;
					char stringnum[20];
					char nextchar;
					
					j=0;
					k=0;
					if (!(fileStream=fopen(trans1, "r")))
						   {
							  printf("Error transaction 1 file not found. Program terminated.");
							  exit (0);
						   }
					for (i=0; i<numids; i++)
					{
							
						
						  fgets (buf, sizeof(buf), fileStream);
						  string lineA(buf);
						  tokenize(lineA, instructionsA);
						  
						  commandA=instructionsA[0].at(0);
						  
						  
						  nameA= ((char*)(instructionsA[1].c_str()));
						  myinstructions[i].command=commandA;
						  
						  if (commandA=='U')
						  {
							value=atoi(instructionsA[2].c_str());
							myinstructions[i].value=value;
						  }
						  else
						  {
							myinstructions[i].value=0;
						  }
						/*  
						  printf("line: %s \n", buf);
							
						  
						  if (ferror(stdin)) 
						  {
							fprintf(stderr,"Oops, error reading stdin\n");
							abort();
						  }
						  
						nextchar=buf[0];
						
						while (nextchar!=' ')
						{
							mytable[i].ids[j]=nextchar;
							j++;
							nextchar=buf[j];
						}
						k=0;
						while (nextchar=buf[++j])
						{
							stringnum[k]=buf[j];
							k++;
						}
						mytable[i].value=atoi(stringnum);
						printf("String %s Value %d \n", mytable[i].ids, mytable[i].value);
						
						j=0;
						*/
					}
					fclose(fileStream);
					/*

					printf("Table: \n namea:---------------Value:\n");
					for (i=0; i<numids; i++)
					{
						//printf ("%s %d \n", mytable[i].ids, mytable[i].value);
						//printf ("I: %d\n",i);
					}
					*/
					//end of manager
					exit(0);
				//end paste from manager
			//readfile(trans1, fileContents, *numlines
			
			/*
			do 
			{
				printf("Reading %s to %s I is %d", trans1, buf, i);
				//read and parse a line from the input file
				read=readline(trans1, proc1buf, i);
				string lineA(proc1buf);
				tokenize(lineA, instructionsA);
				command=instructionsA[0];
				commandchar=(char*)command.c_str();
				cc=commandchar[0];
				name=instructionsA[1];
				if (cc=='U')
				{
					value=atoi((char*)(instructionsA[2].c_str()));
				}
				//send a line in the pipe
				
			
			
			
			i++;
			}
			while (read);
			*/
			while (true)
			{
				sleep (2);
			}
	   }
	
	
	
//PROC2
   if ( (child_b_pid = fork()) == 0) 
   {
			//signal(SIGUSR2, handler2);
			results[6]=child_b_pid;
			sleep(1);
			char proc1buf[256];
			string lineB;
			char** fileContents;
			string *instructionsB;
			int numlines;
			string name, command;
			int value;
			char *commandchar;
			char cc;
			
			i=0;
			j=0;
			bool read;
			//bool 
				//paste from manager
						//refactor to C++
			
					i=0;
					j=0;
					k=0;
					//read the init file and count the 
					if (!(fileStream=fopen(trans2, "r")))
				   {
					  printf("Error init file not found. Program terminated.");
					  exit (0);
				   }
				   
				   int numids=0;
				   
				   
				  while (fgets (buf, sizeof(buf), fileStream)) {
					//printf("line: %s \n", buf);
					numids++;
				  }
				  
				  if (ferror(stdin)) {
					fprintf(stderr,"Oops, error reading stdin\n");
					abort();
				  }
				  fclose(fileStream);
					
					//if (debug) printf ("Init has %d ids. \n",numids);	
					INST myinstructions[numids];
					char commandB;
					char* nameB;
					char stringnum[20];
					char nextchar;
					
					j=0;
					k=0;
					if (!(fileStream=fopen(trans1, "r")))
						   {
							  printf("Error transaction 1 file not found. Program terminated.");
							  exit (0);
						   }
					for (i=0; i<numids; i++)
					{
							
						
						  fgets (buf, sizeof(buf), fileStream);
						  string lineB(buf);
						  tokenize(lineB, instructionsB);
						  
						  commandB=instructionsB[0].at(0);
						  
						  
						  nameB= ((char*)(instructionsB[1].c_str()));
						  myinstructions[i].command=commandB;
						  
						  if (commandB=='U')
						  {
							value=atoi(instructionsB[2].c_str());
							myinstructions[i].value=value;
						  }
						  else
						  {
							myinstructions[i].value=0;
						  }

					}
					fclose(fileStream);
					
					while (true)
					{
						sleep(2);
					}
				
			//readfile(trans1, fileContents, *numlines
			
			
   }

   while (true)
   {
		char input;
		int failcode;
		char one='1';
		char two='2';
		
		printf ("Please press \"1\" or \"2\" for statistics on worker's progress, or press any other key to terminate operations. \n WARNING: this will terminate processing even if work is not complete.\n\n");
		scanf ("%c", &input);
		
		if (input==one)
		{
			failcode=kill(child_a_pid, SIGUSR1);
			
			continue;
			//send signal 1
		}
		else if (input==two)
		{
			failcode=kill(child_b_pid, SIGUSR2);
			continue;
			//send signal 2
		}
		else if (input!=1&&input!=2)
		{
			failcode=kill(child_a_pid, SIGKILL);
			failcode=kill(child_b_pid, SIGKILL);
			failcode=kill(server_pid, SIGKILL);
		
			exit(0);
			//send signal 1
		}
   
   }



////MANAGER



	exit (0);
}




void handler1(int sig)
{
   printf("Process %d is worker1; it has read %d/%d transactions, written %d/%d transactions, and had %d erroneous transactions.", results[5], results[0], results[1], results[2], results[3], results[4]);
   signal(SIGUSR1, handler1);
  // printf("In signal handler ONE  \n\n\n");
}

void handler2(int sig2)
{
   printf("Process %d is worker2; it has read %d/%d transactions, written %d/%d transactions, and had %d erroneous transactions.", results[5], results[0], results[1], results[2], results[3], results[4]);
   signal(SIGUSR2, handler2);
}




