#include "p2.h"
void readfile (char* file, char** fileContents, *int numline )
{
	int numlines;
	
	if (!(fileStream=fopen(file, "r")))
	   {
		  printf("Error %s file not found. Program terminated.", file);
		  exit (0);
	   }
	   
	   int numlines=0;
	   
	   
	  while (fgets (buf, sizeof(buf), fileStream)) {
		printf("line: %s \n", buf);
		numlines++;
	  }
	  
	  if (ferror(stdin)) {
		fprintf(stderr,"Oops, error reading stdin\n");
		abort();
	  }
	numline=*numlines;  
	int i=0;
	char readfile[numlines][256];
	
	for (i=0; i<numlines; i++)
	{
		fgets (buf, sizeof(buf), fileStream)
		readfile[i]=buf;
	}

	fclose(fileStream);



}