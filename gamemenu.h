//��72 ��80 ��75 ��77

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

//FILE.h
#include "Player.h"

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

int menu(void);
int save(void);
int option(void);
int opcolor(void);

int menu(void)
{
	//menu�ϐ�
	int i, in,mode=0,poki=0;

	do{

		system("cls");

		switch(mode){

			case 0:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t          >�|�L����\n");
				printf("\t\t\t           ��������\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���|�[�g\n");
				printf("\t\t\t           �����Ă�\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");

				break;

			case 1:

				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �|�L����\n");
				printf("\t\t\t          >��������\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���|�[�g\n");
				printf("\t\t\t           �����Ă�\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");

				break;

			case 2:

				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �|�L����\n");
				printf("\t\t\t           ��������\n");
				printf("\t\t\t          >������\n");
				printf("\t\t\t           ���|�[�g\n");
				printf("\t\t\t           �����Ă�\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");

				break;

			case 3:

				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �|�L����\n");
				printf("\t\t\t           ��������\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t          >���|�[�g\n");
				printf("\t\t\t           �����Ă�\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
				break;

			case 4:

				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �|�L����\n");
				printf("\t\t\t           ��������\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���|�[�g\n");
				printf("\t\t\t          >�����Ă�\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");

				break;

			case 5:

				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �|�L����\n");
				printf("\t\t\t           ��������\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���|�[�g\n");
				printf("\t\t\t           �����Ă�\n");
				printf("\t\t\t          >���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");

				break;
		}

		in = getch();

		if(in == 13){
			switch(mode){
				case 0:
					system("cls");
					for(i = 0; i < 6, strcmp(GetPokimonName(i), "null") != 0; i++){
						printf("\n\t\t%s:\n", GetPokimonName(i));
						printf("\t\t\t  ��������: %d\n", GetPokimonAtk(i));
						printf("\t\t\t  �ڂ�����: %d\n", GetPokimonDef(i));
						printf("\t\t\t  ������傭: %d/%d\n", GetPokimonHp(i), GetPokimonMaxHp(i));
						printf("\t\t\t  ���΂₳: %d\n\n", GetPokimonSp(i));
					}
					getch();
				break;

				case 1:
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t=====================================\n");
					printf("\n\t\t\t           ����������: %d��\n\n", GetItemCount(0));
					printf("\n\t\t\t           �|�L�����{�[��: %d��\n", GetItemCount(1));
					printf("\n\t\t\t=====================================\n");
					getch();
				break;

				case 2:
					//library();
				break;

				case 3:
					if(save() == 1)
						return 1;
				break;

				case 4:
					option();
				break;

				case 5:
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
			if(mode < 5)
				mode ++;
	}while(poki != 1);

	return 0;

}

int save(void)
{
	int in,No=0,poki;

		system("cls");
		Sleep(1500);
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t�Z�[�u���܂���");
		Sleep(1500);
		system("cls");

	while(poki!=1&&poki!=2){
		system("cls");

		//�v���C���[�f�[�^�Z�[�u
		SavePlayerData(1);

		switch(No){
			case 0:
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t�I�����܂����H");
				printf("\n\n\t\t\t       >�͂��@�@ ������");
			break;

			case 1:
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t�I�����܂����H");
				printf("\n\n\t\t\t        �͂��@�@>������");
			break;
		}

		in = getch();
		if(in == 13){
			switch(No){
				case 0:
					return 1;

				case 1:
					return 0;
			}
		}

	in = getch();

	if(in == 75)
		if(No > 0)
			No--;

	if(in == 77)
		if(No < 1)
			No++;
		}
		return 0;
}

int option(void)
{
	int in,mode=0,poki;

	while(1){
		system("cls");
		switch(mode){
			case 0:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t          >�Q�[��\n");
				printf("\t\t\t           �I�[�f�B�I\n");
				printf("\t\t\t           �f�B�X�v���C\n");
				printf("\t\t\t           �O���t�B�b�N\n");
				printf("\t\t\t           �R���g���[��\n");
				printf("\t\t\t           �J���[\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
			break;

			case 1:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �Q�[��\n");
				printf("\t\t\t          >�I�[�f�B�I\n");
				printf("\t\t\t           �f�B�X�v���C\n");
				printf("\t\t\t           �O���t�B�b�N\n");
				printf("\t\t\t           �R���g���[��\n");
				printf("\t\t\t           �J���[\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
			break;

			case 2:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �Q�[��\n");
				printf("\t\t\t           �I�[�f�B�I\n");
				printf("\t\t\t          >�f�B�X�v���C\n");
				printf("\t\t\t           �O���t�B�b�N\n");
				printf("\t\t\t           �R���g���[��\n");
				printf("\t\t\t           �J���[\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
			break;

			case 3:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �Q�[��\n");
				printf("\t\t\t           �I�[�f�B�I\n");
				printf("\t\t\t           �f�B�X�v���C\n");
				printf("\t\t\t          >�O���t�B�b�N\n");
				printf("\t\t\t           �R���g���[��\n");
				printf("\t\t\t           �J���[\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
			break;

			case 4:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �Q�[��\n");
				printf("\t\t\t           �I�[�f�B�I\n");
				printf("\t\t\t           �f�B�X�v���C\n");
				printf("\t\t\t           �O���t�B�b�N\n");
				printf("\t\t\t          >�R���g���[��\n");
				printf("\t\t\t           �J���[\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
			break;

			case 5:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �Q�[��\n");
				printf("\t\t\t           �I�[�f�B�I\n");
				printf("\t\t\t           �f�B�X�v���C\n");
				printf("\t\t\t           �O���t�B�b�N\n");
				printf("\t\t\t           �R���g���[��\n");
				printf("\t\t\t          >�J���[\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
			break;

			case 6:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           �Q�[��\n");
				printf("\t\t\t           �I�[�f�B�I\n");
				printf("\t\t\t           �f�B�X�v���C\n");
				printf("\t\t\t           �O���t�B�b�N\n");
				printf("\t\t\t           �R���g���[��\n");
				printf("\t\t\t           �J���[\n");
				printf("\t\t\t          >���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki\n");
			break;
		}
	in = getch();

	if(in == 13){
		switch(mode){
			case 5:
				opcolor();
			break;

			case 6:
				return 0;
		}
	}

	if(in != 0)
		continue;


	in = getch();

	if(in == 72)
		if(mode > 0)
			mode--;

	if(in == 80)
		if(mode < 6)
			mode++;
	}
}

int opcolor(void)
{

	int in,mode=0;

	//color�ϐ�
	HANDLE hStdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	while(1){
		system("cls");
		switch(mode){
			case 0:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t          >����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           �݂ǂ�\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki");
			break;

			case 1:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t          >����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           �݂ǂ�\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki");
			break;

			case 2:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t          >����\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           �݂ǂ�\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki");
			break;

			case 3:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t          >������\n");
				printf("\t\t\t           �݂ǂ�\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki");
			break;

			case 4:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t          >�݂ǂ�\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki");
			break;

			case 5:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           �݂ǂ�\n");
				printf("\t\t\t          >������\n");
				printf("\t\t\t           ���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki");
			break;


			case 6:
				printf("\n\n\n\n\n\n\n\n\t\t\t     pokipokipokipokipokipo\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ����\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t           �݂ǂ�\n");
				printf("\t\t\t           ������\n");
				printf("\t\t\t          >���ǂ�\n");
				printf("\t\t\t     kipokipokipokipokipoki");
			break;
		}

		in = getch();

		if(in == 13){
			switch(mode){
				case 0:
					SetConsoleTextAttribute(hStdoutHandle,T_WHITE);
					return 0;

				case 1:
					SetConsoleTextAttribute(hStdoutHandle,T_RED);
					return 0;

				case 2:
					SetConsoleTextAttribute(hStdoutHandle,T_BLUE);
					return 0;

				case 3:
					SetConsoleTextAttribute(hStdoutHandle,T_YELLOW);
					return 0;

				case 4:
					SetConsoleTextAttribute(hStdoutHandle,T_GREEN);
					return 0;

				case 5:
					SetConsoleTextAttribute(hStdoutHandle,T_CYAN);
					return 0;

				case 6:
					return 0;
			}
		}

		if(in != 0)
			continue;

		in = getch();

		if(in == 72)
			if(mode > 0)
				mode--;

		if(in == 80)
			if(mode < 6)
				mode++;
	}
}
