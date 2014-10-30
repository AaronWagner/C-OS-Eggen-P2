inclu

char* readline(char* inputfilename)
{  

			char buf[MAXLINE];
			FILE* filesStream=fopen(inputfilename 'r');	

			
			if (!(fileStream=fopen(input, "r")))
			   {
				  printf("Error init file not found. Program terminated.");
				  exit (0);
			   }
			
			  while (fgets (buf, sizeof(buf), fileStream))
			  {
				printf("line: %s", buf);
				numids++;
			  }
			  if (ferror(stdin)) {
				fprintf(stderr,"Oops, error reading stdin\n");
				abort();
			  }
			  return (buf);
			  
}