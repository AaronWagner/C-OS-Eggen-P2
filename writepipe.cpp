#include "p2.h"

int writepipe (int pipe char* buf int len)
{
	if(write(pipe,buf, len)!=len)
		{
			printf("write error in %d", results[5]);
			return (1);
		}

	return (0);
}