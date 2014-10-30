#include "p2.h"

bool readline(char* inputfilename, char* buf, int linenum)
{  

			//char buf[256];
			FILE* fileStream;	
			bool out;
			int j;
			if (!(fileStream=fopen(inputfilename, "r")))
			   {
				  printf("Error %s file not found. Program terminated.\n", inputfilename);
				  exit (0);
			   }			
			for (j=0; j<linenum; j++)
			{
			  fgets (buf, sizeof(buf), fileStream);
			  printf("Skipped line: %s", buf);
			}
			out=fgets (buf, sizeof(buf), fileStream);
			printf("readline: %s", buf);
			
			
				
			  
			  if (ferror(stdin)) {
				fprintf(stderr,"Oops, error reading stdin\n");
				abort();
			  }
			fclose(fileStream); 	
			return (out);
			  
}