#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "lcs_final.h"						// user defined header file to calculate percentage
void alphaset(char *alpha1,char *alpha2,int l1,int l2)						// this function takes content of files and their size as arguments
{
	char alphatemp1[l1];
	char alphatemp2[l2];
	int x=0,y=0;
	
	for(int i=0;i<l1;i++)
	{
		if((isalnum(alpha1[i]))|| (alpha1[i]=='_') || (alpha1[i]==' '))			// removes characters for alpha1
		{
			if(isupper(alpha1[i]))
			{
				tolower(alpha1[i]);
				alphatemp1[x]=alpha1[i];
				x++;
			}
			else
			{
				alphatemp1[x]=alpha1[i];
				x++;
			}
		}
	}
	for(int i=0;i<l2;i++)
	{
		if((isalnum(alpha2[i]))|| (alpha2[i]=='_') || (alpha2[i]==' '))				// removes characters for alpha2
		{
			if(isupper(alpha2[i]))
			{
				tolower(alpha2[i]);
				alphatemp2[y]=alpha2[i];
				y++;
			}
			else
			{
				alphatemp2[y]=alpha2[i];
				y++;
			}
		}
	}
	lcs(alphatemp1,alphatemp2,x,y);							// function to calculate the percentage
}