#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <math.h>

int numerator(char *word1[],char *word2[],int n1[],int n2[],int c1,int c2)
{													// numerator funtion takes word1,word2,n1,n2,c1,c2 as args
	int temp=0;
	for(int i=0;i<c1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			if((strcmp(word1[i],word2[j]))==0)			// when words same then multiply thier freq
			{
				temp+=n1[i]*n2[j];						// storing the value and summing up the values
			}
		}
	}
	int x=temp;												
	return x;										// returns x i.e numerator

}
float denominator(int n1[],int n2[],int c1,int c2)			// denominator function where n1,n2 are frequencies and c1 and c2 are their size
{
	float temp1=0,temp2=0;
	for(int i=0;i<c1;i++)							
	{
		temp1+=n1[i]*n1[i];
	}
	temp1=pow(temp1,0.5);
	for(int i=0;i<c2;i++)
	{
		temp2+=n2[i]*n2[i];
	}
	temp2=pow(temp2,0.5);
	float y=(temp1*temp2);							// y is the denominator by using bow formula
	return y;										// returns the y
}
void formula(char *word1[],char *word2[],int n1[],int n2[],int c1,int c2)
{													// this function is to calculate percentage by using the arguments which are passed
	
	int x = numerator(word1,word2,n1,n2,c1,c2);		// x is numerator which calls the function numerator
	float y = denominator(n1,n2,c1,c2); 			// y is denominator which calls the function denominator
	float percent= ((x*100.0/y));						// formula for percentage
	printf("%.2f         ",percent);				// print percent
}
void duplicates(char content1[1000][1000],char content2[1000][1000],int x1,int x2)
{													// this function is to check the frequency by removing the duplicates and comparing with the original content 
	char *word1[x1];						
	char *word2[x2];
	for(int i=0;i<=x1;i++)
	{
		word1[i]=malloc(128);						// allocating memory for each index
	}
	for(int i=0;i<=x2;i++)
	{
		word2[i]=malloc(128);
	}
	int c1=0;
	for(int i=0;i<=x1;i++)							// for loop to remove duplicats in content1 and saving in word1 
	{
		int count=0;
		for(int j=0;j<=x1;j++)
		{	
			if((strcmp(content1[i],word1[j]))==0)
			{   
				count++;
			}
		}
		if(count==0)
		{
			strcpy(word1[i],content1[i]);
			c1++;
		}
	}
	int c2=0;
	for(int i=0;i<=x2;i++)										// removes duplicates in content2 and saving in word2
	{	
		int count=0;
		for(int j=0;j<=x2;j++)
		{
			if((strcmp(content2[i],word2[j]))==0)
			{
				count++;
			}

		}
		if(count==0)
		{
			strcpy(word2[i],content2[i]);
			c2++;
		}
	}
	int n1[c1];											// arrays for frequency
	int n2[c2];
	for(int i=0;i<c1;i++)								// for loop to check the frequency of word1 checking with content1
	{	int count=0;
		for(int j=0;j<=x1;j++)
		{
			if((strcmp(word1[i],content1[j]))==0)
			{
				count++;
			}
		}
		n1[i]=count;
	}
	for(int i=0;i<c2;i++)								// for loop to check the frequeny of word2 checking with content2
	{	int count=0;
		for(int j=0;j<=x2;j++)
		{
			if((strcmp(word2[i],content2[j]))==0)
			{
				count++;
			}
		}
		n2[i]=count;
	}
	formula(word1,word2,n1,n2,c1,c2);					// formula function calling taking word1,word2 and their sizes as parameters and n1,n2 i.e frequencies
}
void wordset(char alphatemp1[],char alphatemp2[],int x,int y)		//this function to split with spaces, it takes alphatemp1,alphatemp2,x,y as arguments
{
	char content1[1000][1000]={'\0'};								// 2d array for words with special indexes for alphatemp1
	char content2[1000][1000]={'\0'};								// 2d array for words with special indexes for alphatemp2
	int x1=0,y1=0,x2=0,y2=0;
	for(int i=0;i<x;i++)									// for alphatemp1
	{
		if(isalnum(alphatemp1[i]))
		{
			content1[x1][y1]=alphatemp1[i];
			y1++;
		}
		else
		{
			content1[x1][y1]='\0';
			x1++;
			y1=0;
		}
	}
	for(int i=0;i<y;i++)									// for alphatemp2
	{
		if(isalnum(alphatemp2[i]))
		{
			content2[x2][y2]=alphatemp2[i];
			y2++;
		}
		else
		{
			content2[x2][y2]='\0';
			x2++;
			y2=0;
			
		}
	}
	duplicates(content1,content2,x1,x2);					// duplicates function takes the content1,content2,x1,x2 as parameters

}
void alphaset(char *alpha1,char *alpha2,int l1,int l2)		// this function takes contents of two files and their size as arguments
{
	char alphatemp1[l1];
	char alphatemp2[l2];
	int x=0,y=0;
	
	for(int i=0;i<l1;i++)					// for alpha1
	{
		if((isalnum(alpha1[i])) || (alpha1[i]=='_') || (alpha1[i]==' '))				// removes special characters 
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
	for(int i=0;i<l2;i++)									// for alpha2
	{
		if((isalnum(alpha2[i])) || (alpha2[i]=='_') || (alpha2[i]==' '))			// removes special characters
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
	wordset(alphatemp1,alphatemp2,x,y);				// this function takes alphatemp1,alphatemp2,x,y as parameters where alphatemp1 and alphatemp2 are content without any special characters
}