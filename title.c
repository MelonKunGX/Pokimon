//↑72 ↓80 ←75 →77

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

#include "Player.h"
#include "Map.h"

//文字色の設定
#define  T_BLACK   0x00
#define  T_BLUE     0x09
#define  T_GREEN   0x0a
#define  T_CYAN     0x0b
#define  T_RED      0x0c
#define  T_YELLOW 0x0e
#define  T_WHITE   0x0f

//SET(COLOR,文字色|背景色)で色の設定ができるように#defineに文字を代入
#define SET SetConsoleTextAttribute
#define COLOR hStdoutHandle

int mainmenu(void);
int option(void);
int opcolor(void);

int main(void){
	int in, i;
	FILE *fp;
	char t[8][81];
	while(1){

		system("mode 100,30");
		LoadPokimons();
		system("cls");
		fp = fopen("AA/pokipoki.txt","r");

		for(i = 0; i < 8; i++)
			fgets(t[i], 81, fp);

		for(i = 0; i < 8; i++)
			printf("%s", t[i]);

		fclose(fp);
		printf("\n\n\t\t\t                   Push Enter\n\n\n\t\t\t                    [Enter]");

		in = getch();

		if(in == 27)
			break;

		if(in == 13)
			mainmenu();

	}

	return 0;

}

int mainmenu(void){

	int in, mode=0, mode_g3 = 0, id, find = 0, c;
	char a[8][81];
	char t[8][28];
	char o[8][24];
	char x[8][25];
	char y[8][25];
	char g3[17][76];
	char name[20], p_name[20];
	FILE *fp;
	int i;

	while(1){

		system("cls");
		fp = fopen("AA/pokipoki.txt","r");

		for(i = 0; i < 8; i++)
			fgets(a[i], 81, fp);

		for(i = 0; i < 8; i++)
			printf("%s", a[i]);

		fclose(fp);

		switch(mode){

			case 0:

				printf("\n\n\n\n\t\t\t\t    ====================\n");
				printf("\t\t\t\t      >はじめから\n");
				printf("\t\t\t\t       続きから\n");
				printf("\t\t\t\t       せってい\n");
				printf("\t\t\t\t       タイトルに戻る\n");
				printf("\t\t\t\t    ====================\n");

				break;

			case 1:

				printf("\n\n\n\n\t\t\t\t    ====================\n");
				printf("\t\t\t\t       はじめから\n");
				printf("\t\t\t\t      >続きから\n");
				printf("\t\t\t\t       せってい\n");
				printf("\t\t\t\t       タイトルに戻る\n");
				printf("\t\t\t\t    ====================\n");

				break;

			case 2:

				printf("\n\n\n\n\t\t\t\t    ====================\n");
				printf("\t\t\t\t       はじめから\n");
				printf("\t\t\t\t       続きから\n");
				printf("\t\t\t\t      >せってい\n");
				printf("\t\t\t\t       タイトルに戻る\n");
				printf("\t\t\t\t    ====================\n");


				break;

			case 3:

				printf("\n\n\n\n\t\t\t\t    ====================\n");
				printf("\t\t\t\t       はじめから\n");
				printf("\t\t\t\t       続きから\n");
				printf("\t\t\t\t       せってい\n");
				printf("\t\t\t\t      >タイトルに戻る\n");
				printf("\t\t\t\t    ====================\n");

				break;

		}

		in = getch();

		if(in == 27)
			break;

		if(in == 13){

			switch(mode){

				case 0:
					system("cls");
					fp = fopen("AA/オーソド.txt","r");

					for(i = 0; i < 8; i++){
						fgets(t[i], 28, fp);
					}
					fclose(fp);
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t%s", t[i]);
					}
					printf("\t\t\t\t    ポキモンの世界へようこそ！\n");
					getch();
					printf("\t\t\t\t   わしの名前はオーソド博士じゃ\n");
					getch();
					printf("\t\t\t\t 早速だが、君の名前を教えてくれ！↓\n\n\t\t\t\t\t   ");
					scanf("%s", name);

					while(CreatePlayerData(name) == -1){

						printf("\t\t\t\t    君はもう冒険に出たはずだ！\n\n\t\t\t\t");
						getch();
						printf("    君の名前を教えてくれ！↓\n\n\t\t\t\t");
						scanf("%s", name);

					}

					system("cls");
					fp = fopen("AA/オーソド２.txt","r");

					for(i = 0; i < 8; i++){
						fgets(o[i], 24, fp);
					}
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t    %s", o[i]);
					}
					fclose(fp);
					printf("\t\t\t\t    そうか！君は「%s」というのか！\n", name);
					getch();
					printf("\t\t\t\t    冒険家らしい名前をしているな！\n");
					getch();
					system("cls");
					fp = fopen("AA/オーソド3.txt","r");

					for(i = 0; i < 8; i++){
						fgets(x[i], 25, fp);
					}
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t%s", x[i]);
					}
					printf("\t\t君はこれから広大な大地で、多くのポキモンと触れ合うことだろう。\n");
					getch();
					printf("\t\t野生のポキモンと戦ったり、仲間にしたりすることもあるだろう。\n");
					getch();
					printf("\t\t\t\t自由に旅を楽しんでくれ！");
					getch();
					system("cls");
					Sleep(500);
					fp = fopen("AA/オーソド4.txt","r");

					for(i = 0; i < 8; i++){
						fgets(y[i], 25, fp);
					}
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t%s", y[i]);
					}
					printf("\t.");
					Sleep(300);
					printf(".");
					Sleep(300);
					printf(".");
					Sleep(300);
					printf(".");
					Sleep(300);
					printf("そうじゃ!君と冒険をともにするパートナーを選んでもらってなかったな。\n");
					getch();
					printf("\t\t\t    この３体のポキモンのから１体を選んでくれ！\n");
					getch();

					while(1){

						if(mode_g3 == 0){

							fp = fopen("AA/リザーニョン.txt", "r");

							for(i = 0; i < 17; i++)
								fgets(g3[i], 76, fp);

							fclose(fp);
							system("cls");

							for(i = 0; i < 17; i++)
								printf("\t%s", g3[i]);

							printf("\n\t\t>リザーニョン　 フシギバニャン　 カメッニュス\n");

						}

						if(mode_g3 == 1){

							fp = fopen("AA/フシギバニャン.txt", "r");

							for(i = 0; i < 17; i++)
								fgets(g3[i], 76, fp);

							fclose(fp);
							system("cls");

							for(i = 0; i < 17; i++)
								printf("\t%s", g3[i]);

							printf("\n\t\t リザーニョン　>フシギバニャン　 カメッニュス\n");

						}

						if(mode_g3 == 2){

							fp = fopen("AA/カメッニュス.txt", "r");

							for(i = 0; i < 17; i++)
								fgets(g3[i], 76, fp);

							fclose(fp);
							system("cls");

							for(i = 0; i < 17; i++)
								printf("\t%s", g3[i]);

							printf("\n\t\t リザーニョン　 フシギバニャン　>カメッニュス\n");

						}

						in = getch();

						if(in == 13){

							id = mode_g3;
							break;

						}

						if(in != 0)
							continue;

						in = getch();

						if(in == 75 && mode_g3 > 0)
							mode_g3--;

						if(in == 77 && mode_g3 < 2)
							mode_g3++;

					}

					printf("\t\t\t\t選んだポキモンの名前を入力してくれ！\n\t\t\t\t");
					scanf("%s", p_name);

					AddPokimon(id, p_name);
					SavePlayerData(1);

					system("cls");
					fp = fopen("AA/オーソド3.txt","r");

					for(i = 0; i < 8; i++){
						fgets(x[i], 25, fp);
					}
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t%s", x[i]);
					}
					printf("\t\t\t\tそれでは改めて自由に旅を楽しんでくれ！\n");
					getch();

					system("cls");
					Sleep(2000);
					MapFadeIn(player.map);
					ToMap();
					return 0;

				case 1:

					printf("\n\n\n\t\t\tロードするプレイヤー名を入力してくれ！\n");
					printf("\n\n\t\t\t>");
					scanf("%s", name);

					for(i = 0; LoadPlayerData(i) == 0; i++){

						if(strcmp(GetPlayerName(), name) == 0){

							find = 1;
							break;

						}
					}

					if(find){

						printf("\n\n\n\t\t\tおかえり、%s！", GetPlayerName());
						getch();
						system("cls");
						Sleep(2000);
						MapFadeIn(player.map);
						ToMap();
						return 0;

					}else{

						printf("\n\n\n\t\t\tそのプレイヤーは知らないなぁ...\n");
						getch();

					}

					break;

				case 2:

					option();

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
