/*
void my_strcpy(char *src,char *dest)
{
	char ch ;
	__asm{
	loop:
		LDRB ch,[src],#1
		STRB ch,[dest],#1
		CMP ch,#0
		BNE loop
	
	}
}
*/

//extern void my_strcpy(char *src,char *dest)  ;  

int cFun(int a,int b , int c)
{
	return a+b+c  ; 
}

/*
int main()
{
	char *a = "hello sundy"  ;
	char b[64]  ;
	my_strcpy(a,b)  ; 
}
*/