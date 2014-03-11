#include <stdio.h>

int main()
{
	char c  ;
	FILE *pin , *pout  ; 
	pin = fopen("file.in","r")  ; 
	pout = fopen("file.out","w+")  ; 
	flockfile(pout)  ;
	while ((c = fgetc(pin)) != EOF)
	{
		fputc(c,pout)  ;
	}
	funlockfile(pout) ;
	fclose(pin)  ;
	fclose(pout)  ; 
	return 0 ;
}
