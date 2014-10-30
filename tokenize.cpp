#include "p2.h"


void tokenize (string line, string* tokenizedline)
{
	
    istringstream iss(line);
	int words=0;
    do
    {
        string sub;
        iss >> sub;
        //cout << "Substring: " << sub << endl;
		words++;
    } while (iss);
	
	istringstream issnext(line);
	string output[words];
	
	for (int i=0; i<words; i++)
	{
		string out;
		issnext>>out;
		output[i]=out;
	
	}
	tokenizedline=output;
}