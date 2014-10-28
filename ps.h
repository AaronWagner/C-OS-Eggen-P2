#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <iostream>
#include<malloc.h>
#define FLUSH while(getchar( )!='\n')

#define LINESIZE = 180
/* Forward declaration */
struct EDGETAG;


typedef    struct {
      char id[NAME_SIZE+1]; 
      int value;
    } TABLE[SIZE];







typedef struct
{
   char vertexName;
   bool isVisited;
   bool hasEdge;
   bool isUsed;
   struct EDGETAG* pTheEdge;
} VERTEX;


typedef struct EDGETAG
{
   VERTEX* endVertex;
   struct EDGETAG* pNextEdge;
   bool last;
   bool isNull;

} EDGE;

/* stack structure*/
typedef struct ST
{
   VERTEX *stack[52];

   int top;
}ST;



int main (int argc, char* argv[]);
