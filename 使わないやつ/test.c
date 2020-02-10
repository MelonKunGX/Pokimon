#include<stdio.h>
#include<conio.h>
#include<windows.h>

int main(void){

	int in;
	
	while(1){
	
		in = getch();
		
		if(in != 0)
			continue;

		in = getch();

		printf("%d\n", in);

	}
	
	return 0;

}