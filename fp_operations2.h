#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "fp_final.h"						// user defined header file to calculate the percent
void hashmod(long long hash1[],long long hash2[],int l1,int l2,long long max1,long long max2)
{												// hashmod function takes hashvalues of two files and maxprimes 
	long long mod1[1000];						
	long long x=0;
	for(int i=0;i<l1;i++)						//store hashmod1 % maxprime values in mod1
	{
		x=(hash1[i]%max1);
		mod1[i]=x;
	}
	long long mod2[1000];
	x=0;
	for(int j=0;j<l2;j++)						//store hashmod2 % maxprime values in mod1
	{
		x=(hash2[j]%max2);
		mod2[j]=x;
	} 
	fingerprint(mod1,mod2,l1,l2);				//calls fingerprint function 
}
long long primecheck(long long x)
{										// prime check function is to check the max value is prime or not, if not then next prime is returned
	int count=0;
	for(long long i=2;i<x;i++)
	{
		if(x%i==0)
		{
			count++;
		}
	}
	if(count==0)
	{
		return x; 						//returns max value
	}
	else
	{
		int flag=0;
		count=0;
		while(flag!=1)
		{
			count=0;
			x++;
			for(long long i=2;i<x;i++)
			{
				if(x%i==0)
				{
					count++;
				}
			}
			if(count==0)
			{
				flag=1;
				return x;						// returns the next prime num after max value
			}
		}
	}
}
void maximum(long long hash1[],long long hash2[],int l1,int l2)
{											// this function calculates maximum hashvalue in the array
	long long max1=hash1[0];
	for(int i=0;i<l1;i++)
	{
		if(hash1[i]>max1)
		{
			max1=hash1[i];
		}
	}
	long long max2=hash2[0];
	for(int i=0;i<l2;i++)
	{
		if(hash2[i]>max2)
		{
			max2=hash2[i];
		}
	}
	max1=primecheck(max1); 					// prime check function return prime max1 
	max2=primecheck(max2);					// Prime check function returns prime max2
	hashmod(hash1,hash2,l1,l2,max1,max2);	// calls hashmod function
}