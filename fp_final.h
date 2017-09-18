#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
long long denominator(long long mod1[],long long mod2[],int l1,int l2)
{										// calculates denominator 
	long long y=0;
	for(int i=0;i<l1;i++)
	{
		y+=mod1[i];
	}
	for(int i=0;i<l2;i++)
	{
		y+=mod2[i];
	}
	return y;
}
void fingerprint(long long mod1[],long long mod2[],int l1,int l2)
{											// calculates the percent using the finger print formula
	float x=0;
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			if(mod1[i]==mod2[j])
			{
				x=x+mod1[i];
			}
		}
	}
	
	float y=denominator(mod1,mod2,l1,l2);			// calling denominator function
	float percent= (((x*200)/y));					// formula of fp
	printf("  %.2f       ",percent);				// prints PERCENT
}