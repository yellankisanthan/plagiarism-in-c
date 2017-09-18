#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <math.h>
#include "bagofwords_operations.h"					// user defined header file which contain all the operations
void openfile(char *files[20],int x)						// openfile function takes filenames as argument and size of array
{
	for(int i=0;i<x;i++)
	{	
		FILE *file_handle = fopen(files[i], "r");	// open file using file name
		char a;
		char alpha1[10000];
		int l1=0;
		a=fgetc(file_handle);
		while(a!=EOF)								// storing the content in the file in alpha1[]
		{
			if(a=='\n')
			{
				alpha1[l1]=' ';
				l1++;
			}
			else
			{
				alpha1[l1]=a;
				l1++;
			}
			a=fgetc(file_handle);
		}
		fclose(file_handle);						//closing the file
		printf("\n");
		printf("%s ",files[i]);
		for(int j=0;j<x;j++)
    	{
    	    FILE *file_handle= fopen(files[j],"r");			//open file using file name
    	    char b;
			char alpha2[10000];
			int l2=0;
			b=fgetc(file_handle);
			while(b!=EOF)									// storing the content of the file in alpha2
			{
				if(b=='\n')
				{
					alpha2[l2]=' ';
					l2++;
				}
				else
				{
					alpha2[l2]=b;
					l2++;
				}
				b=fgetc(file_handle);
			}
    	    fclose(file_handle);						// close the file
    	    if((strcmp(files[i],files[j]))==0)			// if same files prints NULL
    	    {
    	    	printf("NULL         ");
    	    }
    	    else										// else call the function alphaset
    	    {
    	    	alphaset(alpha1,alpha2,l1,l2);			// alphaset function which takes alpha1,alpha2,l1,l2 as parameters
    	    }
    	}
	}
}
void main(int argc,char *argv[])									//main function for taking the file names in the directory
{
	char *files[50];
	int i=0;
	DIR *d;
	struct dirent *dir;
	char path[1000];
	// scanf("%[^\n]",path);
	strcpy(path,argv[1]);
	d=opendir(path);
	while( (dir=readdir(d)) != NULL)		// reading the path and storing the file name in dfiles[]
	{
		files[i]= malloc(128);
		int l=strlen(dir->d_name);
		if(dir->d_name[l-1]=='t'&&dir->d_name[l-2]=='x'&&dir->d_name[l-3]=='t')		//filtering for txt files
		{
			strcpy(files[i],dir->d_name);
			i=i+1;
		}
	}
	printf("[ BOW ]");
	int x=i;
	for(int i=0;i<x;i++)
	{
		printf("   %s  ",files[i]);
	}
	
	openfile(files,x);							// calling openfile function
}