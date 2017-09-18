#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "fp_operations2.h"						// user defined header file further operations

void hash(char alphaset1[],char alphaset2[],int x,int y)
{										// hash function takes content of two files as argument
	long long hash1[10000];
	int l1=0;
	long long value=0;
	for(int i=0;i<x-4;i++)				// using k gram value 5 calculates hashvalue
	{
		int z=4;
		for(int j=i;j<i+5;j++)		
		{
			value+=(alphaset1[j]*(pow(10,z)));				// calculates hashvalue of a word
			z--;
		}
		hash1[i]=value;					// store the hashvalue in array
		l1++;
	}
	long long hash2[1000];
	int l2=0;
	value=0;
	for(int i=0;i<y-4;i++)					// using k gram value 5 calculates hashvalue
	{
		int z=4;
		for(int j=i;j<i+5;j++)
		{
			value+=(alphaset2[j]*(pow(10,z)));				// calculates hashvalue of a word
			z--;
		}
		hash2[i]=value;						// store the hashvalue in array
		l2++;
	}
	maximum(hash1,hash2,l1,l2);					// call maximum function

}
void alphaset(char alpha1[],char alpha2[],int l1,int l2)
{										// alphaset funtions takes content of two files and their sizes
	char alphaset1[10000];
	char alphaset2[10000];
	int x=0;
	int y=0;
	for(int i=0;i<l1;i++)
	{
		if(isalnum(alpha1[i]))				//excludes all spaces and characters in content and store in alphaset1
		{
			alphaset1[x]=alpha1[i];
			x++;
		}
	}
	for(int i=0;i<l2;i++)
	{
		if(isalnum(alpha2[i]))				//excludes all spaces and characters in content and store in alphaset2
		{
			alphaset2[y]=alpha2[i];
			y++;
		}
	}
	hash(alphaset1,alphaset2,x,y);				// calls hash function to calculate hash values using k gram value
}
