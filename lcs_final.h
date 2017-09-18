#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
void formula(int n,int x,int y)							// final formula of lcs ((n*2)/(x+y))*100
{
	float percent=(float)(n*200)/(x+y);
	printf("   %.2f       ",percent);
}

void lcs(char alphatemp1[],char alphatemp2[],int x,int y)		// this function is calculate the size of longest common substring
{
	int cmax=0,c=0;
	int temp;
	for(int i=0;i<strlen(alphatemp1);i++)
	{
		int j=0;
		while(j<strlen(alphatemp2))
		{
			temp=i;
			c=0;
			if(alphatemp1[temp]==alphatemp2[j])
			{
				while((alphatemp1[temp]==alphatemp2[j])&&j<strlen(alphatemp2)&&temp<strlen(alphatemp1))
				{
					c++;
					j++;
					temp++;
				}
				if(c>cmax)
				{
					
					cmax=c;
				}
			}
			else
			{
				j++;
			}
		}
	}
	formula(cmax,x,y);						// formula which takes cmax i.e size of longest common substring and x,y i.e size of the content of alpha1 and alpha2
}