//��72 ��80 ��75 ��77

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

#include "Player.h"
#include "Map.h"

//�����F�̐ݒ�
#define  T_BLACK   0x00
#define  T_BLUE     0x09
#define  T_GREEN   0x0a
#define  T_CYAN     0x0b
#define  T_RED      0x0c
#define  T_YELLOW 0x0e
#define  T_WHITE   0x0f

//SET(COLOR,�����F|�w�i�F)�ŐF�̐ݒ肪�ł���悤��#define�ɕ�������
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
				printf("\t\t\t\t      >�͂��߂���\n");
				printf("\t\t\t\t       ��������\n");
				printf("\t\t\t\t       �����Ă�\n");
				printf("\t\t\t\t       �^�C�g���ɖ߂�\n");
				printf("\t\t\t\t    ====================\n");

				break;

			case 1:

				printf("\n\n\n\n\t\t\t\t    ====================\n");
				printf("\t\t\t\t       �͂��߂���\n");
				printf("\t\t\t\t      >��������\n");
				printf("\t\t\t\t       �����Ă�\n");
				printf("\t\t\t\t       �^�C�g���ɖ߂�\n");
				printf("\t\t\t\t    ====================\n");

				break;

			case 2:

				printf("\n\n\n\n\t\t\t\t    ====================\n");
				printf("\t\t\t\t       �͂��߂���\n");
				printf("\t\t\t\t       ��������\n");
				printf("\t\t\t\t      >�����Ă�\n");
				printf("\t\t\t\t       �^�C�g���ɖ߂�\n");
				printf("\t\t\t\t    ====================\n");


				break;

			case 3:

				printf("\n\n\n\n\t\t\t\t    ====================\n");
				printf("\t\t\t\t       �͂��߂���\n");
				printf("\t\t\t\t       ��������\n");
				printf("\t\t\t\t       �����Ă�\n");
				printf("\t\t\t\t      >�^�C�g���ɖ߂�\n");
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
					fp = fopen("AA/�I�[�\�h.txt","r");

					for(i = 0; i < 8; i++){
						fgets(t[i], 28, fp);
					}
					fclose(fp);
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t%s", t[i]);
					}
					printf("\t\t\t\t    �|�L�����̐��E�ւ悤�����I\n");
					getch();
					printf("\t\t\t\t   �킵�̖��O�̓I�[�\�h���m����\n");
					getch();
					printf("\t\t\t\t ���������A�N�̖��O�������Ă���I��\n\n\t\t\t\t\t   ");
					scanf("%s", name);

					while(CreatePlayerData(name) == -1){

						printf("\t\t\t\t    �N�͂����`���ɏo���͂����I\n\n\t\t\t\t");
						getch();
						printf("    �N�̖��O�������Ă���I��\n\n\t\t\t\t");
						scanf("%s", name);

					}

					system("cls");
					fp = fopen("AA/�I�[�\�h�Q.txt","r");

					for(i = 0; i < 8; i++){
						fgets(o[i], 24, fp);
					}
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t    %s", o[i]);
					}
					fclose(fp);
					printf("\t\t\t\t    �������I�N�́u%s�v�Ƃ����̂��I\n", name);
					getch();
					printf("\t\t\t\t    �`���Ƃ炵�����O�����Ă���ȁI\n");
					getch();
					system("cls");
					fp = fopen("AA/�I�[�\�h3.txt","r");

					for(i = 0; i < 8; i++){
						fgets(x[i], 25, fp);
					}
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t%s", x[i]);
					}
					printf("\t\t�N�͂��ꂩ��L��ȑ�n�ŁA�����̃|�L�����ƐG�ꍇ�����Ƃ��낤�B\n");
					getch();
					printf("\t\t�쐶�̃|�L�����Ɛ������A���Ԃɂ����肷�邱�Ƃ����邾�낤�B\n");
					getch();
					printf("\t\t\t\t���R�ɗ����y����ł���I");
					getch();
					system("cls");
					Sleep(500);
					fp = fopen("AA/�I�[�\�h4.txt","r");

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
					printf("��������!�N�Ɩ`�����Ƃ��ɂ���p�[�g�i�[��I��ł�����ĂȂ������ȁB\n");
					getch();
					printf("\t\t\t    ���̂R�̂̃|�L�����̂���P�̂�I��ł���I\n");
					getch();

					while(1){

						if(mode_g3 == 0){

							fp = fopen("AA/���U�[�j����.txt", "r");

							for(i = 0; i < 17; i++)
								fgets(g3[i], 76, fp);

							fclose(fp);
							system("cls");

							for(i = 0; i < 17; i++)
								printf("\t%s", g3[i]);

							printf("\n\t\t>���U�[�j�����@ �t�V�M�o�j�����@ �J���b�j���X\n");

						}

						if(mode_g3 == 1){

							fp = fopen("AA/�t�V�M�o�j����.txt", "r");

							for(i = 0; i < 17; i++)
								fgets(g3[i], 76, fp);

							fclose(fp);
							system("cls");

							for(i = 0; i < 17; i++)
								printf("\t%s", g3[i]);

							printf("\n\t\t ���U�[�j�����@>�t�V�M�o�j�����@ �J���b�j���X\n");

						}

						if(mode_g3 == 2){

							fp = fopen("AA/�J���b�j���X.txt", "r");

							for(i = 0; i < 17; i++)
								fgets(g3[i], 76, fp);

							fclose(fp);
							system("cls");

							for(i = 0; i < 17; i++)
								printf("\t%s", g3[i]);

							printf("\n\t\t ���U�[�j�����@ �t�V�M�o�j�����@>�J���b�j���X\n");

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

					printf("\t\t\t\t�I�񂾃|�L�����̖��O����͂��Ă���I\n\t\t\t\t");
					scanf("%s", p_name);

					AddPokimon(id, p_name);
					SavePlayerData(1);

					system("cls");
					fp = fopen("AA/�I�[�\�h3.txt","r");

					for(i = 0; i < 8; i++){
						fgets(x[i], 25, fp);
					}
					printf("\n\n\n\n\n\n\n\n");
					for(i = 0; i < 8; i++){
						printf("\t\t\t\t%s", x[i]);
					}
					printf("\t\t\t\t����ł͉��߂Ď��R�ɗ����y����ł���I\n");
					getch();

					system("cls");
					Sleep(2000);
					MapFadeIn(player.map);
					ToMap();
					return 0;

				case 1:

					printf("\n\n\n\t\t\t���[�h����v���C���[������͂��Ă���I\n");
					printf("\n\n\t\t\t>");
					scanf("%s", name);

					for(i = 0; LoadPlayerData(i) == 0; i++){

						if(strcmp(GetPlayerName(), name) == 0){

							find = 1;
							break;

						}
					}

					if(find){

						printf("\n\n\n\t\t\t��������A%s�I", GetPlayerName());
						getch();
						system("cls");
						Sleep(2000);
						MapFadeIn(player.map);
						ToMap();
						return 0;

					}else{

						printf("\n\n\n\t\t\t���̃v���C���[�͒m��Ȃ��Ȃ�...\n");
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
