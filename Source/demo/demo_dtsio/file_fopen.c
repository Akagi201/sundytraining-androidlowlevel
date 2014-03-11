#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch  ;
	FILE *fp  ;
	char fname[50]  ;
	printf("input file name:")  ; 
	scanf("%s",fname)  ;
	fp = fopen(fname,"r")  ; // readonly 
	if(fp == NULL)
	{
		printf("error\n")  ; 
		exit(1)  ; 
	}
	while((ch=getc(fp))!= EOF)
	{
		printf("I got the file:%s\n",fname)  ; 
		putchar(ch)  ; 
		fclose(fp)  ; 
		return 0 ; 
	}
}
