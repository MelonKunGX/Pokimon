//↑72 ↓80 ←75 →77

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main(void){

	int in, mode=0;

	while(1){

		system("cls");

		switch(mode){

			case 0:

				printf("==========\n");
				printf(">はじめから\n");
				printf(" 続きから\n");
				printf(" せってい\n");
				printf(" タイトルに戻る\n");
				printf("==========\n");

				break;

			case 1:

				printf("==========\n");
				printf(" はじめから\n");
				printf(">続きから\n");
				printf(" せってい\n");
				printf(" タイトルに戻る\n");
				printf("==========\n");

				break;

			case 2:

				printf("==========\n");
				printf(" はじめから\n");
				printf(" 続きから\n");
				printf(">せってい\n");
				printf(" タイトルに戻る\n");
				printf("==========\n");

				break;

			case 3:

				printf("==========\n");
				printf(" はじめから\n");
				printf(" 続きから\n");
				printf(" せってい\n");
				printf(">タイトルに戻る\n");
				printf("==========\n");

				break;

		}

		in = getch();

		if(in == 27)
			break;

		if(in == 13){
		
			switch(mode){
			
				case 0:
				
					//hazime();
					
					break;
				
				case 1:
				
					//tuduki();
					
					break;
					
				case 2:
				
					//option();
					
					break;
					
				case 3:

					system("cls");

					return 0;

			}
		}

		if(in != 0)
			continue;

		in = getch();

		if(in == 72)
			if(mode > 0)
				mode --;

		if(in == 80)
			if(mode < 3)
				mode ++;

	}

	return 0;

}